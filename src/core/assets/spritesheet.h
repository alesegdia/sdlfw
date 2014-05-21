#pragma once

#include <SDL2/SDL.h>
#include "../math/vec2.h"
#include "texture.h"

class Spritesheet {

private:
	Texture* tex;
	SDL_Rect* rects;
	Vec2 size;
	Vec2 tileSize;

public:
	Spritesheet (Texture* tex=NULL, int x=0, int y=0);
	virtual ~Spritesheet ();

	void LoadFromTexture(Texture* tex, int x,int y);
	void Render(int x, int y,
			int tileN,
			SDL_Renderer* renderer,
			double angle=0, SDL_Point* center=NULL,
			SDL_RendererFlip flip=SDL_FLIP_NONE);
	const Vec2& GetTileSize() const
	{ return tileSize; }
	const Vec2& GetSize() const
	{ return size; }
	SDL_Rect* GetFrameSrc(int f)
	{ return &(rects[f]); }

};

