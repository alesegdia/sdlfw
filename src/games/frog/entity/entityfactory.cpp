
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


Player* EntityFactory::SpawnPlayer(Entity* e, float x, float y)
{
	Player* player = new Player(this);// Request<Player>();

	player->LoadAnimation(asset->GetAnim(assets::ANI_PLAYER_STAND));
	player->SetHealth(15);
	player->Place(50,50);
	player->SetCollisionGroup(CG_PLAYER);
	player->Setup();

	//Animation anim = new Animation(4,)

	player->AddToWorld(e);
	return player;
}

Enemy* EntityFactory::SpawnEnemy(Entity* e, float x, float y)
{
	Enemy* enemy = Request<Enemy>();
	enemy->LoadAnimation(asset->GetAnim(assets::ANI_ENEMY_STAND));
	enemy->SetHealth(10);
	enemy->Place(x,y);
	enemy->Setup();
	enemy->SetCollisionGroup(CG_ENEMY);

	enemy->AddToWorld(e);
	return enemy;
}

Powerup* EntityFactory::SpawnPowerup(Entity* e, uint8_t powerkind, float x, float y)
{
	//Powerup* pwup = Request<Powerup>();
	//pwup->LoadTexture(LoadSpritesheet(surfaces->GetSurface(SF_POWERUP),1, DEFAULT_ANIM_TIME);
	//pwup->SetType(powerkind);
	//pwup->Place(x,y);

	//pwup->AddToWorld(e);
	//return pwup;
	return NULL;
}

Spawner* EntityFactory::SpawnSpawner(Entity* e,float x,int winheight, int respawnTime)
{
	//Spawner* spwn = Request<Spawner,respawnTime>();
	Spawner* spwn = new Spawner(this);//Request<Spawner>();
	spwn->Setup();
	spwn->Place(x,winheight);

	spwn->AddToWorld(e);
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

Bullet* EntityFactory::SpawnBullet(Entity* e, float x, float y, float speed)
{
    Bullet* b = new Bullet(); //Request<Bullet>();
    b->LoadAnimation(asset->GetAnim(assets::ANI_BULLET));
    b->Setup();
    b->Place(x,y);
    b->SetSpeed(speed);
    b->AddToWorld(e);
    b->SetCollisionGroup(CG_BULLET);
    return b;
}
