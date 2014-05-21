#include "entityrenderer.h"
#include "../entity/entity.h"
#include "../assets/texture.h"
#include "../assets/animation.h"

EntityRenderer::EntityRenderer ()
{
	 // ctor
}

EntityRenderer::~EntityRenderer ()
{

}


void EntityRenderer::TryRenderEntity(Entity*p,SDL_Renderer*renderer)
{
	SDL_Rect src;
	Texture* tex = p->GetTexture();
	Animation* anim = p->GetAnim();
	if( anim ){
		p->AnimationStep();
		int currentFrame = p->GetAnimData().currentFrame;
		SDL_RendererFlip flip = (p->LookLeft()?SDL_FLIP_HORIZONTAL:SDL_FLIP_NONE);
		anim->Render(((int)p->X()),((int)p->Y()),renderer,currentFrame,0.0,NULL,flip);
	} else if( tex ){
		tex->Render( p->X(), p->Y(), renderer );
	}
}

void EntityRenderer::SetRef(Entity*ref)
{
	this->ref=ref;
}
