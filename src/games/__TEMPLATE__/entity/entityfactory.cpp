
#include "entityfactory.h"
#include "entitydef.h"
#include "../../../core/physics/collisions.h"
#include "../../../core/entity/entitybase.h"
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
	Player* player = new Player(this);// Request<Player>();
	player->Cleanup();

	player->LoadAnimation(asset->GetAnim(assets::ANI_PLAYER_STAND));
	player->SetHealth(15);
	player->Place(50,50);
	player->SetCollisionGroup(CG_PLAYER);
	player->Setup();

	//Animation anim = new Animation(4,)

	scene->AddEntity(player);
	return player;
}

Enemy* EntityFactory::SpawnEnemy(GameEntity* e, float x, float y)
{
	Enemy* enemy = Request<Enemy>();
	enemy->Cleanup();
	enemy->LoadAnimation(asset->GetAnim(assets::ANI_ENEMY_STAND));
	enemy->SetHealth(10);
	enemy->Place(x,y);
	enemy->Setup();
	enemy->SetCollisionGroup(CG_ENEMY);

	scene->AddEntity(enemy);
	return enemy;
}

Powerup* EntityFactory::SpawnPowerup(GameEntity* e, uint8_t powerkind, float x, float y)
{
	//Powerup* pwup = Request<Powerup>();
	//pwup->LoadTexture(LoadSpritesheet(surfaces->GetSurface(SF_POWERUP),1, DEFAULT_ANIM_TIME);
	//pwup->SetType(powerkind);
	//pwup->Place(x,y);

	//pwup->AddToWorld(e);
	//return pwup;
	return NULL;
}

Spawner* EntityFactory::SpawnSpawner(GameEntity* e,float x,int winheight, int respawnTime)
{
	//Spawner* spwn = Request<Spawner,respawnTime>();
	Spawner* spwn = new Spawner(this);//Request<Spawner>();
	spwn->Reset();
	spwn->Setup();
	spwn->Place(x,winheight);

	scene->AddEntity(spwn);
	return spwn;
}

/*
Entity* EntityFactory::SpawnPowerup(Entity* e,float x, float y, int type)
{
    Entity* e = new Entity();
    e->SetCollisionGroup(CG_POWERUP);
    e->SetAnimation(g_AnimationHolder.GetAnim(ANI_PWUP_SPEED));
}
*/

Bullet* EntityFactory::SpawnBullet(GameEntity* e, float x, float y, float speed)
{
    Bullet* b = new Bullet(); //Request<Bullet>();
    b->Cleanup();
    b->LoadAnimation(asset->GetAnim(assets::ANI_BULLET));
    b->Setup();
    b->Place(x,y);
    b->SetSpeed(speed);
	scene->AddEntity(b);
    b->SetCollisionGroup(CG_BULLET);
    return b;
}
