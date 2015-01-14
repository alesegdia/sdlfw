#pragma once

#include "../../core/sdlapp/sdlapp.h"

#include "entity/entityfactory.h"
#include "entity/entitydef.h"
#include "../../core/renderer/rendererall.h"
#include "../../core/assets/spritesheet.h"



class TortasApp : public SDLApp {

private:
	// settings
	static const int SCR_WIDTH = 800;
	static const int SCR_HEIGHT = 600;

	// balizas
	/*
	EntityBase *inicial;
	EntityBase *final;
	*/
	HOrderScene* scene;

	// gameobjs
	EntityFactory* efactory;
	Player* player;

	// core
	RendererAll* renderer;
	//DebugRenderer* drenderer;

	// assets
	assets* asset;

	uint32_t deltatime;

public:
	TortasApp () :
		SDLApp (SCR_WIDTH, SCR_HEIGHT) {}
	virtual ~TortasApp ();

	// SDLApp interface
	void Setup(int argc, char** argv);
	void Update(uint32_t delta);
	void Render();
	void Cleanup();
	void HandleEvent(SDL_Event& event);

	void UpdateEntities(uint32_t delta);

};

