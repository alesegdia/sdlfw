
#pragma once

#include "../../../core/assets/waveanimator.h"
#include "../gameinfo.h"

class Enemy  : public GameEntity {
public:
	Enemy ();
	virtual ~Enemy ();

	// entity interface
	void Setup();
	void Step();
	void DeltaStep(uint32_t delta);
	void HandleCollision(GameEntity* other);
	void Cleanup();

private:
	float baseX;
	float baseY;
	float current;
	WaveAnimator wanimator;

};



