#include "sdlapp.h"

#include <iostream>

SDLApp::SDLApp (int width, int height, uint32_t sdlwinflags, uint32_t sdlrendererflags) {
	running=true;
	keyboard=NULL;
	window=NULL;
	sdlrenderer=NULL;
	displaytex=NULL;
	winwidth=width;
	winheight=height;
	this->sdlwinflags=sdlwinflags;
	this->sdlrendererflags=sdlrendererflags;
}

SDLApp::~SDLApp()
{
	// dtor
}

int SDLApp::Exec(int argc, char** argv)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		return -1;
	}

	window = SDL_CreateWindow(
		"SDL2 test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		winwidth, winheight, sdlwinflags);

	if(!window) {
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return -2;
	}

	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags)) {
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return -3;
	}

	sdlrenderer = SDL_CreateRenderer(window,-1,sdlrendererflags);
	SDL_SetRenderDrawColor( sdlrenderer, 0x99, 0x99, 0x99, 0xFF );

	displaytex = SDL_CreateTexture(sdlrenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_TARGET,
		winwidth, winheight);

	Setup(argc,argv);

	SDL_Event event;
	const int TIME_STEP = 20;
	int currtime = SDL_GetTicks();
	int delta, accum;
	accum = TIME_STEP;

	while(running) {
		int prevtime = currtime;
		currtime = SDL_GetTicks();
		delta = (currtime - prevtime);
		int accum_ = accum;
		accum -= delta;

		keyboard = ((uint8_t*)SDL_GetKeyboardState(NULL));
		while(SDL_PollEvent(&event)) {
			HandleEvent(event);
		}

		if(accum <= 0) {
			Update(delta);
			accum = TIME_STEP-accum;

			//SDL_SetRenderTarget(sdlrenderer,displaytex);
			SDL_RenderClear(sdlrenderer);
			Render();
			//SDL_SetRenderTarget(sdlrenderer,NULL);
			//SDL_RenderCopy(sdlrenderer, displaytex, NULL, NULL);
			SDL_RenderPresent(sdlrenderer);
		} else {
			SDL_Delay(accum);
		}
	}

	Cleanup();

	SDL_DestroyTexture(displaytex);
	SDL_DestroyRenderer(sdlrenderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	IMG_Quit();

	return 0;
}


void SDLApp::Setup(int argc, char** argv)
{

}

void SDLApp::Update(uint32_t delta)
{

}

void SDLApp::Render()
{

}

void SDLApp::HandleEvent(SDL_Event& event)
{

}

void SDLApp::Cleanup()
{

}
