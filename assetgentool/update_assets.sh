#!/usr/bin/env bash

function reparse_game_assets {
	php assetgen.php $1/assets.assets
	mv assets.h assets.cpp ../src/games/$1/assets/
}

# assets.assets in <GAME>/
reparse_game_assets tortas
reparse_game_assets frog

