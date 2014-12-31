#include "frogapp.h"

#include <iostream>
#include <float.h>
#include <math.h>

#include "constants.h"
#include "assets/assets.h"
#include "../../core/assets/spritesheet.h"
#include "../../core/assets/texture.h"
#include "../../core/assets/animation.h"

extern assets* g_assets;

FrogApp::~FrogApp()
{

}

void FrogApp::Setup(int argc, char** argv)
{

	scene = new HOrderScene( sdlrenderer );

	// init factory & assets
	asset = new assets(sdlrenderer);
	g_assets=asset;
	efactory = new EntityFactory(asset, scene);

	// init game stuff
    healthoff.Set(10,10);
	tqueue.Initialize(
		asset->GetSpritesheet(assets::SHEET_FONDO), 				// tileset
		52,						// capacity
		Vec2(4.f,9.f), 			// range
		Vec2(0.f,648.f-64.f),   // offset
		1.f						// speed
	);
	tqueue.Debug();

	std::vector<Texture*> texes;
	texes.push_back( asset->GetTex(assets::SF_ROCK1) );
	texes.push_back( asset->GetTex(assets::SF_ROCK2) );
	texes.push_back( asset->GetTex(assets::SF_ROCK3) );
	texqueue.SubmitTextures( texes );

	// init entities
	player = efactory->SpawnPlayer(NULL,100,100);
	//Enemy* e = efactory->SpawnEnemy(inicial,600,200);
	Spawner* spwn = efactory->SpawnSpawner(NULL, 800, winheight, 2000);

	scrollbg = new ScrollTexture( asset->GetTex(assets::SF_SCROLLBG), 1, 800 );


	layer1wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));
	layer2wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));
	layer3wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));
	layer4wanim.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD,r.get(0,200*M_PI));

}

void FrogApp::Update(uint32_t delta)
{
	Spritesheet *sss;
	Texture *ttt;
	Animation *aaa;

	if (keyboard[SDL_SCANCODE_ESCAPE])
		Stop();

    //printf("VIDA PLAYER: %d", player->GetHealth());
    if (player->GetHealth()==0) Stop();

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
	deltatime = time;
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

	scrollbg->Render( sdlrenderer );
	texqueue.Step( sdlrenderer );
	/*
    layer1->Render(x,y,sdlrenderer);
    x=layer2wanim.GetPosition().x-offset;
    layer2->Render(x,y,sdlrenderer);
    x=layer3wanim.GetPosition().x-offset;
    layer3->Render(x,y,sdlrenderer);
    x=layer4wanim.GetPosition().x-offset;
    layer4->Render(x,y,sdlrenderer);
    */

	scene->Step(deltatime);

	// render background and tiles
	//DrawBackground();
	tqueue.Draw(sdlrenderer);
	DrawGUI();

	/*
    EntityBase* p;
    p=inicial;
    for(;p;) {
        if(p->IsDestroyed()) {
            EntityBase* tmp = p->Next();
            p->FreeFromWorld();
            p=tmp;
        } else {
            p=p->Next();
        }
	}
	*/

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
	printf("saliendodelavida");
	fflush(stdout);

	asset->Cleanup();
	delete scene;
	delete asset;
	delete efactory;
	delete scrollbg;
	delete scene;

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
