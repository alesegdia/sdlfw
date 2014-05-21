#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "../../../core/entity/entity.h"

class Powerup : public Entity {
public:
	Powerup ();
	virtual ~Powerup ();

	// entity interface
	void Step();
	void HandleCollision(Entity* other);
	void Cleanup();

	void SetType(int t)
	{ type = t; }


private:
	int type;
};

enum {
	PW_HEALTH = 0,
	PW_SPEED,
	PW_BOMB
};

#endif

