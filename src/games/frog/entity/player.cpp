
#include "player.h"
#include "../../../core/physics/collisions.h"
#include "entityfactory.h"
#include "../constants.h"


Player::Player (EntityFactory* f)
{
	speed.x = PLAYER_X_SPEED;
	speed.y = PLAYER_Y_SPEED;
	shootrate=PLAYER_SHOOT_RATE;
	shoottimer.Reset();
	factory=f;
}

Player::~Player ()
{
	 // dtor
}


void Player::Step()
{
	const uint8_t* keystate = SDL_GetKeyboardState(NULL);
	float x,y;
	x=y=0;

	if(keystate[SDL_SCANCODE_LEFT])
		x=-speed.x;
	if(keystate[SDL_SCANCODE_RIGHT])
		x=speed.x;
	if(keystate[SDL_SCANCODE_UP])
		y=-speed.y;
	if(keystate[SDL_SCANCODE_DOWN])
		y=+speed.y;

    if(keystate[SDL_SCANCODE_SPACE])
        ShootStep(keystate[SDL_SCANCODE_SPACE]);

	//printf("%f\n",x);
	Move(x,y);

	//Move(x,y);
	// check input
	// move based on input
}

void Player::ShootStep(bool spacepress)
{
    //printf("shootin'");
    if(shoottimer.Get()>shootrate) {
        factory->SpawnBullet(this,X()+100,Y(),BULLET_SPEED);
        shoottimer.Reset();
        printf("SHOOT!");
    } else {
    }

    shootrate--;
    if(shootrate<0) shootrate=-1;
}

void Player::HandleCollision(Entity* other)
{
    //printf("jugadorcol\n");
    if(other->GetCollisionGroup()==CG_ENEMY)
    {
    	printf("COLENEMY!");
        health--;
        other->Destroy();
    }
	/*
	if(other->cmask & cmask)
	if(other->collisionMask & CM_ENEMY_BULLET) {
		ApplyDamage(static_cast<Bullet*>(other)->GetPower());
		// Factory./World./Whatever.MarkForDelete(other);
		other->Delete();
	}*/
}

void Player::Cleanup()
{

}


void Player::Shoot(bool spacepress)
{
    ShootStep(spacepress);
}
