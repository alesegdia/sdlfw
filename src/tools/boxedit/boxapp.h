#pragma once

#include "../../core/sdlapp/sdlapp.h"

#include "../../core/assets/texture.h"

class BoxApp : public SDLApp {

private:
	// settings
	static const int SCR_WIDTH = 800;
	static const int SCR_HEIGHT = 600;

	// mouse states
	static const int STATE_DRAGGING_SHAPE=1;
	static const int STATE_FREE=2;

	// core
	Texture* tex;
	char* imagepath;
	int xtiles, ytiles;
	int mousestate;
	SDL_Rect selectionRect;


public:
	BoxApp () :
		SDLApp (SCR_WIDTH, SCR_HEIGHT) {}
	virtual ~BoxApp ();

	// SDLApp interface
	void Setup(int argc, char** argv);
	void Update(uint32_t delta);
	void Render();
	void Cleanup();
	void HandleEvent(SDL_Event* event);

};

