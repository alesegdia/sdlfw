#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
private:

	SDL_Texture* tex;
	int w, h;

public:
	Texture (SDL_Renderer* renderer, const char* path=NULL);
	virtual ~Texture ();
	bool LoadFromFile(SDL_Renderer* renderer, const char* path);

	void Render(
		int x, int y,							// dest coord
		SDL_Renderer* renderer,
		SDL_Rect* clip=NULL,					// src clip
		double angle=0.0,						// rotate angle...
		SDL_Point* center=NULL,					// ... around point
		SDL_RendererFlip flip = SDL_FLIP_NONE);	// vert/horiz flip
	void Free();
	void SetAlpha(uint8_t alpha);
	void SetBlendMode(SDL_BlendMode blending);
	// void SetAsRenderTarget(SDL_Renderer* renderer);
	// CreateBlank

	int W() { return w; }
	int H() { return h; }
    SDL_Texture* GetTex() { return tex; }

};



