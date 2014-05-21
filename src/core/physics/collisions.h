#ifndef __COLLISIONS_H__
#define __COLLISIONS_H__

class Entity;

class Collisions {
public:
	Collisions ();
	virtual ~Collisions ();

	void SetRoot(Entity* root)
	{ this->root = root; }

	void Process();

private:

	//bool SDLTextureCollision(Entity* a, Entity* b);

	Entity* root;
};

enum {
    CG_ENEMY,
    CG_PLAYER,
    CG_BULLET
};


#endif

