#ifndef __RENDERERALL_H__
#define __RENDERERALL_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entityrenderer.h"

class RendererAll : public EntityRenderer {
public:
	RendererAll ();
	virtual ~RendererAll ();

	void Render(SDL_Renderer*);

};


#endif

