#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../../../core/assets/waveanimator.h"
#include "../../../core/entity/entitybase.h"

class Enemy : public EntityBase {
public:
	Enemy ();
	virtual ~Enemy ();

	// entity interface
	void Setup();
	void Step();
	void DeltaStep(uint32_t delta);
	void HandleCollision(EntityBase* other);
	void Cleanup();

private:
	float baseX;
	float baseY;
	float current;
	WaveAnimator wanimator;

};


#endif

