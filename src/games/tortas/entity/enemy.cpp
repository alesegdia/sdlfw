#include "enemy.h"
#include <math.h>

#include "../../../core/physics/collisions.h"
#include "../constants.h"
#include "../../../core/assets/waveanimator.h"


Enemy::Enemy ()
{

}

Enemy::~Enemy ()
{
	 // dtor
}

void Enemy::Setup()
{
	baseY = Y();
	baseX = X();
	current=0;
	wanimator.Setup(ENEMY_SINE_AMPLITUDE,ENEMY_SINE_PERIOD);
}

void Enemy::Step()
{

}

void Enemy::DeltaStep(uint32_t delta)
{
	float dy = wanimator.GetPosition().x;
	float dx = -ENEMY_X_SPEED;

	Place(X()+dx, baseY+dy);
	if(X()<-ENEMY_X_DESTROY_LIMIT) Destroy();
	wanimator.Step();
}

void Enemy::HandleCollision(EntityBase* other)
{/*
    if(other->GetCollisionGroup()==CG_BULLET) {
        other->Destroy();
        Destroy();
    }
	// do enemy collision response
	
	switch(other->GetCollisionGroup()) {
    case CG_PLAYER:
            Destroy(); break;
    default:
        printf("unrecognized collision\n");
	}*/
}

void Enemy::Cleanup()
{

}
