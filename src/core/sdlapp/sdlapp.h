#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SDLApp {

private:
	bool running;

protected:
	SDL_Window* window;
	SDL_Renderer* sdlrenderer;
	SDL_Texture* displaytex;
	uint8_t* keyboard;
	int winwidth, winheight;
	uint32_t sdlwinflags;
	uint32_t sdlrendererflags;

	virtual void Setup(int argc, char** argv);
	virtual void Update(uint32_t delta);
	virtual void Render();
	virtual void Cleanup();
	virtual void HandleEvent(SDL_Event& event);

	void Stop()
	{ running=false; }


public:
	SDLApp (int width, int height, uint32_t sdlwinflags=SDL_WINDOW_OPENGL,
		uint32_t sdlrendererflags=SDL_RENDERER_ACCELERATED|SDL_RENDERER_TARGETTEXTURE);
	virtual ~SDLApp ();

	int Exec(int argc, char** argv);


};


