#ifndef __ENTITYFACTORY_H__
#define __ENTITYFACTORY_H__

#include "entitydecl.h"
#include "../assets/assets.h"
#include "../../../core/scene/horderscene.h"
#include "../../../core/entity/entitybase.h"
#include <stdint.h>

typedef EntityBase<HOrderScene> GameEntity;

class EntityFactory {
public:
	EntityFactory (assets* as, HOrderScene* scene);
	virtual ~EntityFactory ();

	Player* SpawnPlayer (GameEntity* e, float x, float y);
	Enemy* SpawnEnemy(GameEntity* e,float x,float y);
	Powerup* SpawnPowerup(GameEntity*,uint8_t,float,float);
	Spawner* SpawnSpawner(GameEntity*,float,int,int);
	Bullet* SpawnBullet(GameEntity*,float,float,float);

private:
	static const uint32_t DEFAULT_ANIM_TIME = 100;
	assets* asset;
	HOrderScene* scene;

	template <typename EType>
	EType* Request() { return new EType(); }
};


#endif

