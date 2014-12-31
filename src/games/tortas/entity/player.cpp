
#include "player.h"
#include "../../../core/physics/collisions.h"
#include "entityfactory.h"
#include "../constants.h"


extern EntityFactory g_EntityFactory;

Player::Player ()
{
	speed.x = PLAYER_X_SPEED;
	speed.y = PLAYER_Y_SPEED;
	shootrate=PLAYER_SHOOT_RATE;
	shoottimer.Reset();
	LoadState(STATE_STAND,assets::ANI_PLAYER_STAND);
	state=STATE_STAND;
}

Player::~Player ()
{
	 // dtor
}

void Player::Setup()
{
	ypos = Y();
	printf("ypos!: %f\n",ypos);
	impulso = PLAYER_JUMP_IMPULSE;
}

void Player::Step()
{
	const uint8_t* keystate = SDL_GetKeyboardState(NULL);
	float dx,dy;
	bool move=true;
	bool askforkey=true;
	dx=dy=0;
	bool left, right, jump, down, punch;
	left = keystate[SDL_SCANCODE_LEFT];
	right = keystate[SDL_SCANCODE_RIGHT];
	jump = keystate[SDL_SCANCODE_SPACE];
	down = keystate[SDL_SCANCODE_DOWN];
	punch = keystate[SDL_SCANCODE_A];

	if(state==STATE_WALKING) {
		if(!left&&!right&&!jump) {
			LoadState(STATE_STAND,assets::ANI_PLAYER_STAND);
		} else if(jump) {
			LoadState(STATE_JUMP,assets::ANI_PLAYER_STAND);
		}else if(punch) {
			LoadState(STATE_PUNCH,assets::ANI_PLAYER_PUNCH);
			//lookLeft=left;
		}
	} else if(state==STATE_STAND) {
		if(left||right) {
			LoadState(STATE_WALKING,assets::ANI_PLAYER_WALK);
		} else if (jump) {
			LoadState(STATE_JUMP, assets::ANI_PLAYER_STAND);
		} else if(down) {
			LoadState(STATE_CROUCH, assets::ANI_PLAYER_CROUCH);
		} else if(punch) {
			timer=PLAYER_PUNCH_DURATION;
			LoadState(STATE_PUNCH, assets::ANI_PLAYER_PUNCH);
		}
	} else if(state==STATE_JUMP) {
		printf("%f\n",Y());
		dy += impulso;
		impulso += PLAYER_JUMP_GRAVITY;
		if(dy+Y()>=ypos) {
			dy=-Y()+ypos;
			impulso=PLAYER_JUMP_IMPULSE;
			LoadState(STATE_WALKING,assets::ANI_PLAYER_WALK);
		}
		//lookLeft=left;
	} else if(state==STATE_CROUCH) {
		move=false;
		if(!down) LoadState(STATE_STAND,assets::ANI_PLAYER_STAND);
		if(left) lookLeft=true;
		if(right) lookLeft=false;
	} else if(state==STATE_PUNCH) {
		if(timer<=0){
			if(punch) {
				LoadState(STATE_PUNCH,assets::ANI_PLAYER_PUNCH);
				timer=PLAYER_PUNCH_DURATION;
			} else LoadState(STATE_STAND,assets::ANI_PLAYER_STAND);
		} else timer--;
	}

	if(move) {
		if(left) {
			dx=-speed.x;
			lookLeft=true;
		}else if(right) {
			dx=speed.x;
			lookLeft=false;
		}
	}

	//printf("%f\n",x);
	aabb.Move(dx,dy);

	//Move(x,y);
	// check input
	// move based on input
}

void Player::ShootStep(bool spacepress)
{
    //printf("shootin'");
    if(shoottimer.Get()>shootrate) {
        //g_EntityFactory.SpawnBullet(this,X()+100,Y(),BULLET_SPEED);
        shoottimer.Reset();
    } else {
    }

    //shootrate--;
    //if(shootrate<0) shootrate=-1;
}

void Player::HandleCollision(EntityBase* other)
{
    //printf("jugadorcol\n");
    if(other->GetCollisionGroup()==CG_ENEMY)
    {
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
