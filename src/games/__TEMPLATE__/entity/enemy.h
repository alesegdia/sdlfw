
#pragma once

#include "../../../core/assets/waveanimator.h"
#include "../gameinfo.h"

class Enemy  : public EntityBase<HOrderScene> {
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



