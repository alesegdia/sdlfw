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
		textures[SF_TORTAS] = new Texture(renderer,"media/tortas/tortasheet.png");
		textures[SF_BG] = new Texture(renderer,"media/tortas/bg.png");
		spritesheets[SHEET_TORTAS] = new Spritesheet(textures[SF_TORTAS],4,3);
		anims[ANI_PLAYER_WALK]= new Animation(4,spritesheets[SHEET_TORTAS],-1);
		anims[ANI_PLAYER_WALK]->SetFrame(0,0,5);
		anims[ANI_PLAYER_WALK]->SetFrame(1,1,5);
		anims[ANI_PLAYER_WALK]->SetFrame(2,2,5);
		anims[ANI_PLAYER_WALK]->SetFrame(3,3,5);
		anims[ANI_PLAYER_STAND]= new Animation(1,spritesheets[SHEET_TORTAS],-1);
		anims[ANI_PLAYER_STAND]->SetFrame(0,4);
		anims[ANI_PLAYER_CROUCH]= new Animation(4,spritesheets[SHEET_TORTAS],1);
		anims[ANI_PLAYER_CROUCH]->SetFrame(0,5,2);
		anims[ANI_PLAYER_CROUCH]->SetFrame(1,6,2);
		anims[ANI_PLAYER_CROUCH]->SetFrame(2,7,2);
		anims[ANI_PLAYER_CROUCH]->SetFrame(3,8,2);
		anims[ANI_PLAYER_PUNCH]= new Animation(2,spritesheets[SHEET_TORTAS],1);
		anims[ANI_PLAYER_PUNCH]->SetFrame(0,9,10);
		anims[ANI_PLAYER_PUNCH]->SetFrame(1,10,10);
	}

	void Cleanup() {
		for(size_t i=0;i<1;i++) {
			delete spritesheets[i];
		}

		for(size_t i=0;i<2;i++) {
			delete textures[i];
		}

		for(size_t i=0;i<4;i++) {
			delete anims[i];
		}

	}

	static const size_t SF_TORTAS = 0;
	static const size_t SF_BG = 1;
	static const size_t SHEET_TORTAS = 0;
	static const size_t ANI_PLAYER_WALK = 0;
	static const size_t ANI_PLAYER_STAND = 1;
	static const size_t ANI_PLAYER_CROUCH = 2;
	static const size_t ANI_PLAYER_PUNCH = 3;
	

private:

	static const size_t MAX_TEXTURES = 128;
	static const size_t MAX_SHEETS = 128;
	static const size_t MAX_ANIMS = 128;

	Texture* textures[MAX_TEXTURES];
	Spritesheet* spritesheets[MAX_SHEETS];
	Animation* anims[MAX_ANIMS];


};

