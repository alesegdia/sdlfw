#include "waveanimator.h"
#include <math.h>

WaveAnimator::WaveAnimator()
{
    //ctor
}

WaveAnimator::~WaveAnimator()
{
    //dtor
}

void WaveAnimator::Step()
{
    position.x = sinf(currentAngle)*amplitude;
    currentAngle += 1/period;
}

void WaveAnimator::Setup(float amplitude, float period, float currentAngle)
{
    this->amplitude = amplitude;
    this->period = period;
    this->currentAngle = currentAngle;
}
