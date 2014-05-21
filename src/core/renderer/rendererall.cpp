#include "rendererall.h"
#include "../entity/entity.h"

RendererAll::RendererAll ()
{
	 // ctor
}

RendererAll::~RendererAll ()
{
	 // dtor
}

void RendererAll::Render(SDL_Renderer* renderer)
{
	Entity* p = ref;
	for(;p;p=p->Next()) {
		TryRenderEntity(p, renderer);
	}
}

