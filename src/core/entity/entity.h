#pragma once

#include <SDL2/SDL.h>
#include "../math/aabb.h"
#include "../math/vec2.h"
#include "../util/timer.h"
#include "../assets/animation.h"
#include <vector>

class Entity
{
private:
	// Entity linked list
	Entity* next;
	Entity* prev;
	bool destroyed;

	static const int MAX_ENTITY_HALFWIDTH = 100;



protected:

	// chapuzas
	bool lookLeft;		// para hacer el flip en el renderer, pensar algo mejor

	// void LoadAnim(int animID);

	// gfx & animation
	Texture* tex;
	Animation* anim;
	Animation::Data animdata;

	// physics
	AABB aabb;
	uint8_t cmask;
	Vec2 speed;
	int collisionGroup;

	// life
	int health;


public:
	Entity();
	~Entity();

	// assets
	//static void SetAssets(assets* as);

	// entity interface
	virtual void Setup();
	virtual void Step();
	virtual void DeltaStep(uint32_t delta);
	virtual void HandleCollision(Entity* other);
	virtual void Cleanup();

	// graphics
	void LoadTexture(Texture* tex);               // para entidades estaticas, sin animacion
    void LoadAnimation(Animation* anim);

	Texture* GetTexture() { return tex; }
	Animation* GetAnim() { return anim; }
	const Animation::Data& GetAnimData() { return animdata; }
	//void ResetAnimData() { animdata.Reset(anim); }
	void AnimationStep();
	void CycleAnim();
	  //aabb.SetSize(anim->W(),anim->H()); }

	// physics
	void Place(int x, int y) { aabb.Place(x,y); RecheckPosition(); }
	float X() { return aabb.X(); }
	float Y() { return aabb.Y(); }
	void X(float x) { Place(x,Y()); }
	void Y(float y) { Place(X(),y); }
	void Move(float x, float y) { aabb.Move(x,y); RecheckPosition(); }
	void ApplySpeed(int x, int y) { aabb.Move(x*speed.x,y*speed.y); }
	float W() { return aabb.W(); }
	float H() { return aabb.H(); }
	float HalfWidth() { return aabb.HalfWidth(); }
	float DistanciaX(Entity* e) { return abs(X()-e->X()); }
	void SetColmask(uint8_t c)
	{ cmask = c; }
	bool CollideWith(Entity* other)
	{ return aabb.intersects(other->aabb); }
	void SetCollisionGroup(int cgroup)
	{ collisionGroup=cgroup; }
	int GetCollisionGroup()
	{ return collisionGroup; }
	bool LookLeft()
	{ return lookLeft; }

	// health
	void SetHealth(int amount)
	{ health = amount; }
	void ApplyDamage(int amount)
	{ health -= amount; }
	int GetHealth()
	{ return health; }

	// aqui o en el propio renderer? es una
	// caracteristica mas del renderer que
	// de la entidad
	static int MaxHalfWidth()
	{ return MAX_ENTITY_HALFWIDTH; }

	// INPUT: reference entity
	void AddToWorld(Entity*);
   	void FreeFromWorld();
	void Destroy();
	bool IsDestroyed();

    // list handling
	void RecheckPosition();
	void InsertForward(Entity*);
	void InsertBackward(Entity*);
	Entity* Next()
	{ return next; }
	Entity* Prev()
	{ return prev; }
	void Next(Entity* e)
	{ next = e; }
	void Prev(Entity* e)
	{ prev = e; }

};

//assets* Entity::ass = NULL;
