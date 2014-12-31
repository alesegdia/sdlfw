#pragma once

#include <SDL2/SDL.h>
#include "../math/aabb.h"
#include "../math/vec2.h"
#include "../util/timer.h"
#include "../assets/animation.h"
//#include <vector>


template <typename SceneNode>
class EntityBase : public SceneNode::Node
{
private:

	// EntityBase linked list
	/*
	EntityBase* next;
	EntityBase* prev;
	*/
	bool destroyed;

	static const int MAX_ENTITY_HALFWIDTH = 100;

protected:

	// chapuzas
	bool lookLeft;		// para hacer el flip en el renderer, pensar algo mejor
	bool movedSinceLastFrame;

	// void LoadAnim(int animID);

	// gfx & animation
	Texture* tex;
	Animation* anim;
	Animation::Data animdata;

	// physics
	AABB aabb;
	uint8_t cmask;
	Vec2 speed;

	// life
	int health;


public:


	EntityBase() { Reset(); }
	virtual ~EntityBase() {}

	// assets
	//static void SetAssets(assets* as);

	// entity interface
	int collisionGroup;
	virtual void Setup(){}
	virtual void Step(){}
	virtual void DeltaStep(uint32_t delta){}
	virtual void HandleCollision(EntityBase<SceneNode>* other){}
	virtual void Cleanup(){}

	// base entity reset
	void Reset(){
		anim=NULL;
		destroyed=false;
		movedSinceLastFrame = false;
		tex=NULL;
		lookLeft=false;
	}

	// graphics
	void LoadTexture(Texture* tex)               // para entidades estaticas, sin animacion
	{
		this->tex = tex;
		aabb.SetSize(tex->W(),tex->H());
	}
    void LoadAnimation(Animation* anim)
	{
		this->anim = anim;
		animdata.Reset(anim);
		aabb.SetSize(anim->W(), anim->H());
	}

	Texture* GetTexture() { return tex; }
	Animation* GetAnim() { return anim; }
	const Animation::Data& GetAnimData() { return animdata; }
	//void ResetAnimData() { animdata.Reset(anim); }
	void AnimationStep(){anim->Update(animdata);}
	void CycleAnim();
	  //aabb.SetSize(anim->W(),anim->H()); }

	// physics
	void Place(int x, int y) { aabb.Place(x,y); movedSinceLastFrame = true; }
	float X() { return aabb.X(); }
	float Y() { return aabb.Y(); }
	void X(float x) { Place(x,Y()); }
	void Y(float y) { Place(X(),y); }
	void Move(float x, float y) { aabb.Move(x,y); movedSinceLastFrame = true; }
	void ApplySpeed(int x, int y) { aabb.Move(x*speed.x,y*speed.y); }
	float W() { return aabb.W(); }
	float H() { return aabb.H(); }
	float HalfWidth() { return aabb.HalfWidth(); }
	float DistanciaX(EntityBase* e) { return abs(X()-e->X()); }
	void SetColmask(uint8_t c)
	{ cmask = c; }
	bool CollideWith(EntityBase* other)
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

	void Destroy() { destroyed = true; }
	bool IsDestroyed(){ return destroyed;}
	bool MovedSinceLastFrame() { return movedSinceLastFrame; }
	void ClearMoved(){ movedSinceLastFrame = false; }

};

//assets* EntityBase::ass = NULL;

//#include "entitybase_impl.h"
