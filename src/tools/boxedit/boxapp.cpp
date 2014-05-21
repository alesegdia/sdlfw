#include "boxapp.h"

#include <iostream>
#include <float.h>
#include <math.h>



BoxApp::~BoxApp()
{

}

void BoxApp::Setup(int argc, char** argv)
{
	tex=new Texture(sdlrenderer,"media/ranillasheet.png");
	if(argc == 4) {
		imagepath = argv[1];
		xtiles = atoi(argv[2]);
		ytiles = atoi(argv[3]);
		printf("imgpath: %s\nxtiles: %d\nytiles: %d\n",
			imagepath, xtiles, ytiles);
		tex = new Texture(sdlrenderer,imagepath);
	} else {
		printf("ERROR!");
	}
}


void BoxApp::Update(uint32_t delta)
{

}

void BoxApp::Render()
{
	tex->Render(0,0,sdlrenderer);
}

void BoxApp::HandleEvent(SDL_Event* event)
{

}

void BoxApp::Cleanup()
{

}

