#ifndef __FROGAPP_H__
#define __FROGAPP_H__

#include "../../core/sdlapp/sdlapp.h"
//#include "renderer/debugrenderer.h"

#include "entity/entityfactory.h"
#include "entity/entitydef.h"
#include "../../core/physics/collisions.h"
#include "../../core/renderer/rendererall.h"
#include "../../core/renderer/debugrenderer.h"
#include "../../core/assets/spritesheet.h"
#include "assets/tilequeue.h"
#include "assets/assets.h"

class FrogApp : public SDLApp {

private:

	// settings
	static const int SCR_WIDTH = 800;
	static const int SCR_HEIGHT = 600;

	// balizas
	Entity *inicial;
	Entity *final;

	// gameobjs
	EntityFactory* efactory;
	Player* player;

	// core
	RendererAll* renderer;
	DebugRenderer* drenderer;
	Collisions* collisions;

	// assets
	assets* asset;
	TileQueue tqueue;
	Vec2 healthoff;
	Random r;

	// layer animators
	WaveAnimator layer1wanim;
	WaveAnimator layer2wanim;
	WaveAnimator layer3wanim;
	WaveAnimator layer4wanim;


public:
	FrogApp () :
		SDLApp (SCR_WIDTH, SCR_HEIGHT) {}
	virtual ~FrogApp ();

	// SDLApp interface
	void Setup(int argc, char** argv);
	void Update(uint32_t delta);
	void Render();
	void Cleanup();
	void HandleKeyboard();
	void HandleJoystick();
	void HandleEvent(SDL_Event* event);

	// Update & Draw
	void UpdateBackground(int);
	void UpdateLevel();
	void UpdateEntities(uint32_t delta);
	void DrawBackground();
	void DrawGUI();


};

#endif

