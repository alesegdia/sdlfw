#include "rendererall.h"
#include "../entity/entitybase.h"

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
	EntityBase<HOrderScene>* p = ref;
	for(;p;p=p->next) {
		TryRenderEntity(p, renderer);
	}
}

