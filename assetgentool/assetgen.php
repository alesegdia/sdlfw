<?php

define("MAX_SIZE", 128);

function salir ($msg) {
	fclose($assetfile);
	//fclose($cppout);
	fclose($hout);
	print "$msg\n";
	print "Saliendo...\n";
}

function insert_const($file, $const, $value=128) {
	//if($value==NULL) { printf("NULLL!!!\n");
	//$value=constant("MAX_SIZE"); //}
	fprintf($file,"\tstatic const size_t $const = $value;\n");
}

function checkState($state, $expected) {
	if ($state != $expected) salir("bloque $expected corrupto");
}

function clean($file, $bagname, $n) {
	fprintf($file, "\t\tfor(size_t i=0;i<$n;i++) {\n".
		"\t\t\tdelete %s[i];\n".
		"\t\t}\n\n", $bagname);
}


if($argc != 2) {
	print "php assetgen.php <FILE>.assets\n";
	salir();
}

$assetfile = fopen("./$argv[1]","r");	// asset filename
$assetpathinfo = pathinfo($argv[1]);
$assetname = $assetpathinfo["filename"];	// asset basename

# $assetname = $assetname[0];
$hfile = $assetname . ".h";			// .h file name
$hout = fopen($hfile, "w"); 		// out .h file
$hcpp = fopen($assetname.".cpp","w");

fwrite($hcpp,"#include \"$assetname.h\"\n\n".
	"$assetname* g_$assetname;\n\n");
fclose($hcpp);

$state = "none";	// parsing state
$assetid = "";		// current asset being processed
$consts = array();  // store consts assoc to assets
$n_frames = 0;		// anims
$surfID = "";		// tilesets
$tsID = "";			// anim ts id
$times = 0;			// times for anim
$assetnum = array();

$nsurfs = 0;
$nanims = 0;
$nsheet = 0;

function advanceAsset () {
	global $assetctr, $state, $assetnum, $assetid;
	if(!isset($assetctr[$state])) $assetctr[$state]=0;
	else $assetctr[$state]++;
	$assetnum[$assetid]=$assetctr[$state];
}



if (!$assetfile || !$hout) {
	salir("error al abrir fichero");
}

$assetsprefix = "../../../core/assets";
fprintf($hout,
	"#pragma once\n\n" .
	"#include \"$assetsprefix/texture.h\"\n" .
	"#include \"$assetsprefix/spritesheet.h\"\n" .
	"#include \"$assetsprefix/animation.h\"\n" .
	"#include <SDL2/SDL.h>\n" .
	"#include <SDL2/SDL_image.h>\n\n" .
	"class $assetname {\n" .
	"public:\n".
	"\tvirtual ~$assetname () {}\n\n".
	"\tTexture* GetTex(int texID)\n".
	"\t{ return textures[texID]; }\n\n".
	"\tSpritesheet* GetSpritesheet(int tsetID)\n".
	"\t{ return spritesheets[tsetID]; }\n\n".
	"\tAnimation* GetAnim(int animID)\n".
	"\t{ return anims[animID]; }\n\n".
	"\t$assetname (SDL_Renderer* renderer) {\n",$assetname,$assetname);

$assetctr = array();

$nsurfs = 0;
$nplays = -1;
$nanims = 0;
$nsheet = 0;

$regex = "/\[(?<header>(texture|spritesheet|animation)) (?<assetid>.*)\]/";
$regex2 = "/(?<arg>(texture|imgsrc|tiles|spritesheet|steps|times|nplays))([\s]?)*=([\s?]?)*(?<val>.*)/";
$linenum = 0;

while(($line=fgets($assetfile))!=false) {
	$linenum++;
	if(trim($line)=="") continue;
	else if(preg_match("/(\s)*#.*/",$line)) continue;
	else if(preg_match($regex, $line, $tokens)) {
		// do header
		switch($tokens["header"]) {
		case "texture":
			$nsurfs++;
			break;
		case "spritesheet":
			$nsheet++;
			break;
		case "animation":
			$nanims++;
			$times = "";
			$n_frames = 0;
			$nplays = -1;
			break;
		}
		$assetid = $tokens["assetid"];
		$state = $tokens["header"];
		array_push($consts,$assetid);
	} else if(preg_match($regex2, $line, $tokens)) {
		// do args
		switch($tokens["arg"]) {
		case "texture":
			checkState($state,"spritesheet");
			$surfID = $tokens["val"];
			break;
		case "imgsrc":
			# final surface state
			checkState($state,"texture");
			$imgsrc=$tokens["val"];
			fprintf($hout,"\t\ttextures[$assetid] = new Texture(renderer,\"$imgsrc\");\n");
			advanceAsset();
			break;
		case "tiles":
			# final spritesheet state
			checkState($state,"spritesheet");
			preg_match("/(\d+),(\d+)/",$tokens["val"],$tilepos);
			print_r($tilepos);
			fprintf($hout,
				"\t\tspritesheets[$assetid] = new Spritesheet(".
				"textures[$surfID],%s,%s);\n",
				$tilepos[1],$tilepos[2]);
			advanceAsset();
			break;
		case "spritesheet":
			checkState($state,"animation");
			$tsID = $tokens["val"];
			break;
		case "steps":
			# final animation state
			checkState($state,"animation");
			$steps = split(",",$tokens["val"]);
			fprintf($hout,"\t\tanims[$assetid]".
				"= new Animation(%s,spritesheets[$tsID],$nplays);\n",
				count($steps));
			for($i=0;$i<count($steps);$i++) {
				if($times!="") {
					fprintf($hout,
						"\t\tanims[$assetid]->SetFrame($i,%s,%s);\n",
						$steps[$i],$times[$i]);
				} else {
					fprintf($hout,
						"\t\tanims[$assetid]->SetFrame($i,%s);\n",
						$steps[$i]);
				}
			}
			advanceAsset();
			break;
		case "times":
			checkState($state,"animation");
			$times=split(",",$tokens["val"]);
			break;
		case "nplays":
			checkState($state,"animation");
			print("NPLAYS!!!");
			$nplays=$tokens["val"];
		}
	} else {
		print("unrecognized line: $line\n");
	}
	//print_r($tokens);
}

print_r($assetnum);
print_r($consts);

fwrite($hout,"\t}\n\n".
	"\tvoid Cleanup() {\n");
clean($hout, "spritesheets", $nsheet);
clean($hout, "textures", $nsurfs);
clean($hout, "anims", 	 $nanims);
fwrite($hout, "\t}\n\n");

# insertamos constantes
for($i=0;$i<count($consts);$i++) {
	$a = $consts[$i]; $b=$assetnum[$consts[$i]];
	printf("\n%s, %s\n", $a, $b);
	insert_const($hout, $a, $b);
}

fwrite($hout, "\t\n\nprivate:\n\n");
insert_const($hout, "MAX_TEXTURES");
insert_const($hout, "MAX_SHEETS");
insert_const($hout, "MAX_ANIMS");
fwrite($hout, "\n\tTexture* textures[MAX_TEXTURES];\n");
fwrite($hout, "\tSpritesheet* spritesheets[MAX_SHEETS];\n");
fwrite($hout, "\tAnimation* anims[MAX_ANIMS];\n\n");
fwrite($hout, "\n};\n\n");
?>
