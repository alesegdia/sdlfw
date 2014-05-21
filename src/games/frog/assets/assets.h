#pragma once

#include "../../../core/assets/texture.h"
#include "../../../core/assets/spritesheet.h"
#include "../../../core/assets/animation.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class assets {
public:
	virtual ~assets () {}

	Texture* GetTex(int texID)
	{ return textures[texID]; }

	Spritesheet* GetSpritesheet(int tsetID)
	{ return spritesheets[tsetID]; }

	Animation* GetAnim(int animID)
	{ return anims[animID]; }

	assets (SDL_Renderer* renderer) {
		textures[SF_PLAYER] = new Texture(renderer,"media/frog/ranillasheet.png");
		textures[SF_ENEMY] = new Texture(renderer,"media/frog/manstahsheet.png");
		textures[SF_FONDO_LAYER1] = new Texture(renderer,"media/frog/layer1.png");
		textures[SF_FONDO_LAYER2] = new Texture(renderer,"media/frog/layer2.png");
		textures[SF_FONDO_LAYER3] = new Texture(renderer,"media/frog/layer3.png");
		textures[SF_FONDO_LAYER4] = new Texture(renderer,"media/frog/layer4.png");
		textures[SF_FONDO] = new Texture(renderer,"media/frog/fondo.png");
		textures[SF_ALL] = new Texture(renderer,"media/frog/allset4x.png");
		spritesheets[SHEET_FONDO] = new Spritesheet(textures[SF_FONDO],4,4);
		spritesheets[SHEET_PLAYER] = new Spritesheet(textures[SF_PLAYER],4,1);
		spritesheets[SHEET_ENEMY] = new Spritesheet(textures[SF_ENEMY],6,1);
		spritesheets[SHEET_ALL] = new Spritesheet(textures[SF_ALL],3,1);
		anims[ANI_PLAYER_STAND]= new Animation(4,spritesheets[SHEET_PLAYER],-1);
		anims[ANI_PLAYER_STAND]->SetFrame(0,0,1);
		anims[ANI_PLAYER_STAND]->SetFrame(1,1,2);
		anims[ANI_PLAYER_STAND]->SetFrame(2,2,3);
		anims[ANI_PLAYER_STAND]->SetFrame(3,3,4);
		anims[ANI_ENEMY_STAND]= new Animation(6,spritesheets[SHEET_ENEMY],-1);
		anims[ANI_ENEMY_STAND]->SetFrame(0,0);
		anims[ANI_ENEMY_STAND]->SetFrame(1,1);
		anims[ANI_ENEMY_STAND]->SetFrame(2,2);
		anims[ANI_ENEMY_STAND]->SetFrame(3,3);
		anims[ANI_ENEMY_STAND]->SetFrame(4,4);
		anims[ANI_ENEMY_STAND]->SetFrame(5,5);
		anims[ANI_BULLET]= new Animation(2,spritesheets[SHEET_ALL],-1);
		anims[ANI_BULLET]->SetFrame(0,1);
		anims[ANI_BULLET]->SetFrame(1,2);
	}

	void Cleanup() {
		for(size_t i=0;i<4;i++) {
			delete spritesheets[i];
		}

		for(size_t i=0;i<8;i++) {
			delete textures[i];
		}

		for(size_t i=0;i<3;i++) {
			delete anims[i];
		}

	}

	static const size_t SF_PLAYER = 0;
	static const size_t SF_ENEMY = 1;
	static const size_t SF_FONDO_LAYER1 = 2;
	static const size_t SF_FONDO_LAYER2 = 3;
	static const size_t SF_FONDO_LAYER3 = 4;
	static const size_t SF_FONDO_LAYER4 = 5;
	static const size_t SF_FONDO = 6;
	static const size_t SF_ALL = 7;
	static const size_t SHEET_FONDO = 0;
	static const size_t SHEET_PLAYER = 1;
	static const size_t SHEET_ENEMY = 2;
	static const size_t SHEET_ALL = 3;
	static const size_t ANI_PLAYER_STAND = 0;
	static const size_t ANI_ENEMY_STAND = 1;
	static const size_t ANI_BULLET = 2;
	

private:

	static const size_t MAX_TEXTURES = 128;
	static const size_t MAX_SHEETS = 128;
	static const size_t MAX_ANIMS = 128;

	Texture* textures[MAX_TEXTURES];
	Spritesheet* spritesheets[MAX_SHEETS];
	Animation* anims[MAX_ANIMS];


};

