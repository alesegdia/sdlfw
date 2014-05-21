#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../../core/entity/entity.h"

class EntityFactory;

class Player : public Entity {
public:
	Player (EntityFactory* f);
	virtual ~Player ();

	// entity interface
	void Step();
	void HandleCollision(Entity* other);
	void Cleanup();
	void ShootStep(bool spacepress);

	void Shoot(bool spacepress);

private:
    int shootrate;
    Timer shoottimer;
    EntityFactory* factory;
};

#endif

