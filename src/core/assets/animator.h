#pragma once

#include "../math/vec2.h"

class Animator {
public:
	Animator ();
	virtual ~Animator ()=0;

    const Vec2& GetPosition()
    { return position; }
    void Step();

protected:
    Vec2 position;

};

