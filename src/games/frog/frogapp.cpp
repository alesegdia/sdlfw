#include "frogapp.h"

#include <iostream>
#include <float.h>
#include <math.h>

#include "constants.h"
#include "assets/assets.h"

extern assets* g_assets;

FrogApp::~FrogApp()
{
}



void FrogApp::Setup(int argc, char** argv)
{
	// init core objects
	renderer = new RendererAll();
	drenderer = new DebugRenderer();
	collisions = new Collisions();

	// init factory & assets
	asset = new assets(sdlrenderer);
	g_assets=asset;
	efactory = new EntityFactory(asset);

	// init entity world
	inicial = new Entity();
	final = new Entity();
	inicial->Cleanup();
	final->Cleanup();

	inicial->Next(final);
	inicial->Prev(nullptr);
	inicial->X(-1000000);

	final->Next(nullptr);
	final->Prev(inicial);
	final->X(1000000);

	// init game stuff
    healthoff.Set(10,10);
	tqueue.Initialize(
		asset->GetSpritesheet(assets::SHEET_ALL), 				// tileset
		15,						// capacity
		Vec2(4.f,9.f), 			// range
		Vec2(0.f,600.f-64.f),   // offset
		1.f						// speed
	);
	tqueue.Debug();

	// init entities
	player = efactory->SpawnPlayer(inicial,100,100);
	Enemy* e = efactory->SpawnEnemy(inicial,600,200);
	Spawner* spwn = efactory->SpawnSpawner(inicial, 800, winheight, 2000);

	collisions->SetRoot(inicial);
	renderer->SetRef(inicial);
	drenderer->SetRef(inicial);

	layer1wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));
	layer2wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));
	layer3wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));
	layer4wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));

}


void FrogApp::Update(uint32_t delta)
{
	if (keyboard[SDLK_ESCAPE])
		Stop();
    //printf("VIDA PLAYER: %d", player->GetHealth());
    if (player->GetHealth()==0) Stop();

	// perform collisions
	collisions->Process();

	// DESPUES DE COLISIONES!
	UpdateEntities(delta);

	// update background and tilemap
	UpdateBackground(1);
	layer1wanim.Step();
	layer2wanim.Step();
	layer3wanim.Step();
	layer4wanim.Step();

	UpdateLevel();


	/*
	Entity*p=inicial;
	printf("ELIST: { ");
	for(;p;p=p->Next()) {
		printf("[ep:%d,x:%f,prev:%d,next:%d],",p,p->X(),p->Prev(),p->Next());
	}
	printf(" }\n");
	*/
}

void FrogApp::UpdateEntities(uint32_t time)
{
	Entity* p=inicial;
	int i=0;
	for(;p;p=p->Next()) {
		p->Step();
		p->DeltaStep(time);
	}
}

void FrogApp::DrawGUI()
{
	Spritesheet* allset = asset->GetSpritesheet(assets::SHEET_ALL);
    for(int i=0; i < player->GetHealth();i++) {
    	int x = healthoff.x+i*allset->GetTileSize().x;
    	int y = healthoff.y;
        allset->Render(x,y,0,sdlrenderer);
    }
}

void FrogApp::Render()
{
    Texture* layer1 = asset->GetTex(assets::SF_FONDO_LAYER1);
    Texture* layer2 = asset->GetTex(assets::SF_FONDO_LAYER2);
    Texture* layer3 = asset->GetTex(assets::SF_FONDO_LAYER3);
    Texture* layer4 = asset->GetTex(assets::SF_FONDO_LAYER4);
    float offset = 50.f;

    //SDL_Rect r;
    //r.x=layer1wanim.GetPosition().x-offset; r.y = 0;
    int x = layer1wanim.GetPosition().x-offset;
    int y = 0;

    layer1->Render(x,y,sdlrenderer);
    x=layer2wanim.GetPosition().x-offset;
    layer2->Render(x,y,sdlrenderer);
    x=layer3wanim.GetPosition().x-offset;
    layer3->Render(x,y,sdlrenderer);
    x=layer4wanim.GetPosition().x-offset;
    layer4->Render(x,y,sdlrenderer);

	// render entities
	renderer->Render(sdlrenderer);
	drenderer->Render(sdlrenderer);

	// render background and tiles
	//DrawBackground();
	tqueue.Draw(sdlrenderer);
	DrawGUI();

    Entity* p;
    p=inicial;
    for(;p;) {
        if(p->IsDestroyed()) {
            Entity* tmp = p->Next();
            p->FreeFromWorld();
            p=tmp;
        } else {
            p=p->Next();
        }
	}

}

void FrogApp::HandleEvent(SDL_Event* event)
{
/*
    printf("handlin\n");
    if(event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE) {
        player->Shoot(true);
        printf("jiadsDJFJADFJAOSDOFKASDKFAKDSFKADSKMFKMADSMLKFKMLADSFKMLASMDF\n\n\n");
    } else {
        //player->Shoot(false);
    }
*/
	if(keyboard[SDL_SCANCODE_ESCAPE]) {
		printf("ESCAPE!");
		Stop();
	}
}

void FrogApp::Cleanup()
{
	Entity* p=inicial;
	Entity* tmp;

	while(p) {
		printf("Cleaning %d\n",((int)p));
		tmp=p->Next();

		printf("Next %d\n",((int)tmp));
		p->Cleanup();
		delete p;
		p=tmp;


		printf("NewP %d\n",((int)p));
		if(p!=nullptr) printf("otrave\n");
		else printf("salimos!");
		fflush(stdout);
	}


	printf("saliendodelavida");
	fflush(stdout);

	delete renderer;
	delete drenderer;
	delete collisions;
	asset->Cleanup();
	delete asset;
	delete efactory;

	/*
	for(;p;p=tmp) {
		tmp = p->Next();
		delete p;
	}*/
}

void FrogApp::UpdateBackground(int delta)
{
	/* Update layers
	for (auto it : BackgroundLayers)
	{
		it->Update();
	}*/
}

void FrogApp::UpdateLevel()
{
	tqueue.Step();
/*
	if (WeHaveToCreateNewTile)
	{
		Tiles.RemoveFirst();
		Tiles.PushBack(TilePatterns[RGen.Generate(0,TilePatterns.size()-1)]);
	}

	// Logic components? Logic system?
	if (Timer.Get() < 10)
	{
		int xpos = RGen.Generate(0 + tolerance, Height - tolerance);
		spawner->SpawnEntity(ypos);
	}*/
}

void FrogApp::DrawBackground()
{

}
