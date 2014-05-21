#include "spritesheet.h"

Spritesheet::Spritesheet (Texture* tex, int x, int y)
{
    rects=NULL; this->tex=NULL;
    if(tex) LoadFromTexture(tex,x,y);
}

Spritesheet::~Spritesheet ()
{
	if(rects) delete [] rects;
}


void Spritesheet::LoadFromTexture(Texture* tex, int x, int y)
{
	if(rects) delete [] rects;
	size.x=x; size.y=y;

	this->tex = tex;
	tileSize.x = tex->W()/x;
	tileSize.y = tex->H()/y;
	printf("x: %f, y: %f\n",tileSize.x,tileSize.y);
	rects = new SDL_Rect[x*y];
	for(int i=0;i<y;i++) {
		for(int j=0;j<x;j++) {
			size_t index = i*x+j;
			rects[index].x = j*tileSize.x;
			rects[index].y = i*tileSize.y;
			rects[index].w = tileSize.x;
			rects[index].h = tileSize.y;
		}
	}
}


void Spritesheet::Render(int x, int y, int tileN, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect src,dst;
	dst.x=x; dst.w=rects[tileN].w;
	dst.y=y; dst.h=rects[tileN].h;
	src.x=rects[tileN].x; src.w=rects[tileN].w;
	src.y=rects[tileN].y; src.h=rects[tileN].h;
	SDL_RenderCopyEx(renderer, tex->GetTex(), &src, &dst, angle, center, flip);
}
