#include "debugrenderer.h"
#include "../entity/entity.h"

DebugRenderer::DebugRenderer ()
{
	 // ctor
}

DebugRenderer::~DebugRenderer ()
{
	 // dtor
}


void DebugRenderer::Render(SDL_Renderer* renderer)
{
	SDL_Rect destR;
	Entity* p = ref;
	SDL_SetRenderDrawColor(renderer,255,0,255,255);
	for(;p;p=p->Next()) {
		if (p->GetAnim() || p->GetTexture()) {
			destR.w = p->W(); destR.h = p->H();
			destR.x = p->X(); destR.y = p->Y();
			printf("%d,%d,%d,%d\n",destR.x,destR.y,destR.w,destR.h);
			SDL_RenderDrawRect(renderer,&destR);
		}
	}
}
