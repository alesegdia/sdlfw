#ifndef __COLLISIONS_H__
#define __COLLISIONS_H__

#include "../entity/entitybase.h"
#include "../scene/horderscene.h"


class Collisions {
public:
	Collisions ();
	virtual ~Collisions ();

	void SetRoot(EntityBase<HOrderScene>* root)
	{ this->root = root; }

	void Process();

private:

	//bool SDLTextureCollision(EntityBase* a, EntityBase* b);

	EntityBase<HOrderScene>* root;
};

enum {
    CG_ENEMY,
    CG_PLAYER,
    CG_BULLET,
    CG_SPAWNER,
    CG_BALIZA
};


#endif

