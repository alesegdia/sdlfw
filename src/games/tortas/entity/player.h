#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../../../core/entity/entitybase.h"
#include "../assets/assets.h"

extern assets *g_assets;

class Player : public EntityBase {
public:
	Player ();
	virtual ~Player ();

	// entity interface
	void Setup();
	void Step();
	void HandleCollision(EntityBase* other);
	void Cleanup();
	void ShootStep(bool spacepress);

	void Shoot(bool spacepress);

private:

	void LoadState(int state, int animID) {
		LoadAnimation(g_assets->GetAnim(animID));
		this->state=state;
	}

    int shootrate;
    Timer shoottimer;
    int state;
    float ypos;
    float impulso;
    int timer;
    bool first; // primera vez
    // que se pasa por el estado

    static const int STATE_WALKING=0;
    static const int STATE_STAND=1;
    static const int STATE_JUMP=2;
    static const int STATE_CROUCH=3;
    static const int STATE_PUNCH=4;

};

#endif

