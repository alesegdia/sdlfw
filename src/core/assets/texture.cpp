#include "texture.h"

Texture::Texture (SDL_Renderer* renderer, const char* path)
{
	tex=NULL; w=h=0;
	if(path) {
        LoadFromFile(renderer,path);
	}
}

Texture::~Texture ()
{
	 Free();
}


bool Texture::LoadFromFile(SDL_Renderer* renderer, const char* path) {
	Free();

	SDL_Texture* newtex = NULL;
	SDL_Surface* surf = IMG_Load(path);
	if(!surf) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
	} else {
		newtex = SDL_CreateTextureFromSurface(renderer, surf);
		if(!newtex) {
			printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
		} else {
			w = surf->w;
			h = surf->h;
		}
		SDL_FreeSurface(surf);
	}

	tex = newtex;
	return tex!=NULL;
}

/*
void Texture::SetAsRenderTarget(SDL_Renderer* prenderer) {
	SDL_SetRenderTarget((prenderer) ? prenderer : renderer, tex);
}
*/

void Texture::SetBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(tex,blending);
}

void Texture::SetAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(tex,alpha);
}

void Texture::Free() {
	if(tex) {
		SDL_DestroyTexture(tex);
		tex=NULL;
		w=h=0;
	}
}

void Texture::Render(int x, int y, SDL_Renderer* renderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderquad = { x, y, w, h };
	if(clip!=NULL) {
		renderquad.w = clip->w;
		renderquad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, tex, clip, &renderquad, angle, center, flip);
}


