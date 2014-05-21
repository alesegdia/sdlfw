#ifndef __DEBUGRENDERER_H__
#define __DEBUGRENDERER_H__

#include "entityrenderer.h"

class DebugRenderer : public EntityRenderer {
public:
	DebugRenderer ();
	virtual ~DebugRenderer ();

	void Render(SDL_Renderer*);

};


#endif

