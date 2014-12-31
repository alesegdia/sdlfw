#include "tortasapp.h"

#include <iostream>
#include <float.h>
#include <math.h>

#include "constants.h"
#include "assets/assets.h"
#include "../../core/physics/collisions.h"

extern assets* g_assets;


TortasApp::~TortasApp()
{

}

void TortasApp::Setup(int argc, char** argv)
{
	// init core objects
	renderer = new RendererAll();

	// init factory & assets
	asset = new assets(sdlrenderer);
	g_assets=asset;
	efactory = new EntityFactory(asset);

	// init entity world
	/*
	inicial = new EntityBase();
	final = new EntityBase();
	inicial->Cleanup();
	final->Cleanup();
	inicial->Next(final);
	inicial->Prev(NULL);
	inicial->X(-1000000);
	final->Next(NULL);
	final->Prev(inicial);
	final->X(1000000);
	*/

	scene = new HOrderScene( sdlrenderer );
	// init entities
	//player = efactory->SpawnPlayer(inicial,100,100);
	player = efactory->SpawnPlayer(NULL,100,100);
	//Enemy* e = efactory->SpawnEnemy(inicial,600,200);


	//tex=new Texture(sdlrenderer,"media/ranillasheet.png");

}


void TortasApp::Update(uint32_t delta)
{
	if (keyboard[SDLK_ESCAPE])
		Stop();
    //printf("VIDA PLAYER: %d", player->GetHealth());
    //if (player->GetHealth()==0) Stop();

	// perform collisions

	// DESPUES DE COLISIONES!
	UpdateEntities(delta);

	/*
	Entity*p=inicial;
	printf("ELIST: { ");
	for(;p;p=p->Next()) {
		printf("[ep:%d,x:%f,prev:%d,next:%d],",p,p->X(),p->Prev(),p->Next());
	}
	printf(" }\n");
	*/
}

void TortasApp::UpdateEntities(uint32_t time)
{
	/*
	EntityBase* p=inicial;
	int i=0;
	for(;p;p=p->Next()) {
		p->Step();
		p->DeltaStep(time);
	}
	*/
}


void TortasApp::Render()
{
	// render entities
	asset->GetTex(assets::SF_BG)->Render(0,0,sdlrenderer);
	renderer->Render(sdlrenderer);

	/*
    EntityBase* p;
    p=inicial;
    for(;p;) {
        if(p->IsDestroyed()) {
            EntityBase* tmp = p->Next();
            p->FreeFromWorld();
            p->Cleanup();
            p=tmp;
        } else {
            p=p->Next();
        }
	}*/

}

void TortasApp::HandleEvent(SDL_Event& event)
{
	/*
	switch(event.type) {
	case SDL_QUIT: running=false; break;
	case SDL_KEYDOWN:
		switch(e.key.keysym.sym) {
		case SDL_SCANCODE_UP: events->KeyDown(SDL_SCANCODE_UP); break;
		case SDL_SCANCODE_DOWN: break;
						case SDLK_
		}


	}*/
	if(keyboard[SDL_SCANCODE_ESCAPE]) Stop();

}

void TortasApp::Cleanup()
{
	/*
	EntityBase* p=inicial;
	EntityBase* tmp;

	while(p) {
		tmp=p->Next();
		p->Cleanup();
		delete p;
		p=tmp;
	}
	*/

	delete efactory;
	asset->Cleanup();
	delete asset;
	delete renderer;
}

