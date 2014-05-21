#ifndef WAVEANIMATOR_H
#define WAVEANIMATOR_H

#include "animator.h"

class WaveAnimator : public Animator
{
public:
    WaveAnimator();
    virtual ~WaveAnimator();

    void Setup(float,float,float currentAngle=0);
    void Step();

private:
    float amplitude;
    float period;
    float currentAngle;
};

#endif // WAVEANIMATOR_H
