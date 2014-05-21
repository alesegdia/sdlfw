#include "bullet.h"
#include "../../../core/physics/collisions.h"
#include "../constants.h"


Bullet::Bullet()
{
    //ctor
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::Step()
{
    Move(speed,0);
    if(X()>BULLET_DESTROY_X_LIMIT) Destroy();
}

void Bullet::HandleCollision(Entity* other)
{

    if(other->GetCollisionGroup()==CG_ENEMY) {
        other->Destroy();
        Destroy();
    }

}
