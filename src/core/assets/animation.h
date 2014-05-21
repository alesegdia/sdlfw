#pragma once

#include <SDL2/SDL.h>
#include "spritesheet.h"

class Animation {
public:
	struct Data {
		Data() { timer = 0; last=0; nplays=-1; }
		void Reset(Animation* anim)
		{ currentFrame=0; timer=anim->times[currentFrame]; nplays=anim->nplays; last=0;}
		int currentFrame; int timer;
		int last;
		int nplays;
	};

	Animation (int nframes, Spritesheet* tset, int nplays=-1);
	virtual ~Animation ();
	void Update(Data& d);
	void Render(
		int x, int y,							// dest coord
		SDL_Renderer* renderer,
		int nframe=-1,					// src clip
		double angle=0.0,						// rotate angle...
		SDL_Point* center=NULL,					// ... around point
		SDL_RendererFlip flip = SDL_FLIP_NONE);	// vert/horiz flip
	void SetFrame(int nframe, int ntile, int time=DEFAULT_ANIM_TIME);
	float W() { spritesheet->GetTileSize().x; }
	float H() { spritesheet->GetTileSize().y; }
	SDL_Rect* GetFrameSrc(int f)
	{ return spritesheet->GetFrameSrc(f); }

private:

	static const int DEFAULT_ANIM_TIME = 10;
	Spritesheet* spritesheet;
	int* frames;
	int* times;
	int nframes;
	int nplays;
};


