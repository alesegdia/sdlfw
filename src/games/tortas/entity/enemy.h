#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../../../core/assets/waveanimator.h"
#include "../../../core/entity/entitybase.h"
#include "../../../core/scene/horderscene.h"

class Enemy : public EntityBase<HOrderScene> {
public:
	Enemy ();
	virtual ~Enemy ();

	// entity interface
	void Setup();
	void Step();
	void DeltaStep(uint32_t delta);
	void HandleCollision(Entity* other);
	void Cleanup();

private:
	float baseX;
	float baseY;
	float current;
	WaveAnimator wanimator;

};


#endif

