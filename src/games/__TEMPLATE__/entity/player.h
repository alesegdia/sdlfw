#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../../core/entity/entitybase.h"
#include "../gameinfo.h"

class EntityFactory;

class Player : public EntityBase<HOrderScene> {
public:
	Player (EntityFactory* f);
	virtual ~Player ();

	// entity interface
	void Step();
	void HandleCollision(EntityBase* other);
	void Cleanup();
	void ShootStep(bool spacepress);

	void Shoot(bool spacepress);

private:
    int shootrate;
    Timer shoottimer;
    EntityFactory* factory;
};

#endif

