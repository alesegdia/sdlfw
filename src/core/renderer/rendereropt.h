#ifndef __RENDEREROPT_H__
#define __RENDEREROPT_H__

#include <SDL2/SDL.h>

class Entity;

class RendererOpt  {
public:
	RendererOpt ();
	virtual ~RendererOpt ();

	void Render(SDL_Renderer*);
	void SetCamera(Entity*);

private:
	Entity* cam;
	static const size_t maxEntityHalfWidth = 32;
};


#endif

