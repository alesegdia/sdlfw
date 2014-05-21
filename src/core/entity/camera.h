#pragma once

#include "entity.h"

class Camera : public Entity
{
private:
	Entity* ref;

public:
	void Step();
	void SetEntityRef(Entity* e);

};
