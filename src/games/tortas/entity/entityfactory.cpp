
#include "entityfactory.h"
#include "entitydef.h"
#include "../../../core/physics/collisions.h"
#include "../../../core/assets/animation.h"
#include "../assets/assets.h"


EntityFactory::EntityFactory (assets* as, HOrderScene* scene)
{
	 this->asset=as;
	 this->scene = scene;
}

EntityFactory::~EntityFactory ()
{
	 // dtor
}


Player* EntityFactory::SpawnPlayer(GameEntity* e, float x, float y)
{
	Player* player = new Player(); //Request<Player>();
	player->Cleanup();

	//player->LoadTexture(asset->GetTex(assets::SF_PLAYER));
	player->LoadAnimation(this->asset->GetAnim(assets::ANI_PLAYER_STAND));
	player->SetHealth(15);
	player->Place(50,500);  // WTF?!?!?!?!? PASAR X E Y!!! JODERRR!!
	player->SetCollisionGroup(CG_PLAYER);
	player->Setup();


	//Animation anim = new Animation(4,)

	//player->AddToWorld(e);
	return player;
}

Enemy* EntityFactory::SpawnEnemy(GameEntity* e, float x, float y)
{
//	Enemy* enemy = Request<Enemy>();
//	//enemy->LoadSpritesheet(surfaces->GetSurface(SF_ENEMY),6,DEFAULT_ANIM_TIME);
//	enemy->SetAnimation(g_assets.GetAnim(assets::ANI_ENEMY_STAND));
//	enemy->SetHealth(10);
//	enemy->Place(x,y);
//	enemy->Setup();
//	enemy->SetCollisionGroup(CG_ENEMY);

//	enemy->AddToWorld(e);
//	return enemy;
}


