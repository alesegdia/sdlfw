
#include "entityfactory.h"
#include "entitydef.h"
#include "../../../core/physics/collisions.h"
#include "../../../core/assets/animation.h"
#include "../assets/assets.h"


EntityFactory::EntityFactory (assets* as)
{
	 this->asset=as;
}

EntityFactory::~EntityFactory ()
{
	 // dtor
}


Player* EntityFactory::SpawnPlayer(EntityBase* e, float x, float y)
{
	Player* player = Request<Player>();

	//player->LoadTexture(asset->GetTex(assets::SF_PLAYER));
	player->LoadAnimation(asset->GetAnim(assets::ANI_PLAYER_STAND));
	player->SetHealth(15);
	player->Place(50,500);  // WTF?!?!?!?!? PASAR X E Y!!! JODERRR!!
	player->SetCollisionGroup(CG_PLAYER);
	player->Setup();


	//Animation anim = new Animation(4,)

	player->AddToWorld(e);
	return player;
}

Enemy* EntityFactory::SpawnEnemy(EntityBase* e, float x, float y)
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


