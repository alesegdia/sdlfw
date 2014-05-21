#ifndef __ENTITYFACTORY_H__
#define __ENTITYFACTORY_H__

#include "entitydecl.h"
#include "../assets/assets.h"
#include <stdint.h>

class Entity;

class EntityFactory {
public:
	EntityFactory (assets*);
	virtual ~EntityFactory ();

	Player* SpawnPlayer (Entity* e, float x, float y);
	Enemy* SpawnEnemy(Entity* e,float x,float y);

private:
	static const uint32_t DEFAULT_ANIM_TIME = 100;
	assets* asset;

	template <typename EType>
	EType* Request() { return new EType(); }
};


#endif

