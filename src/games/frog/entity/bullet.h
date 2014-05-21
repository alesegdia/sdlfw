#pragma once

#include "../../../core/entity/entity.h"

class Bullet : public Entity
{
    public:
        Bullet();
        virtual ~Bullet();

        void SetSpeed(float s)
        { this->speed = s; }

        void Step();
        void HandleCollision(Entity* other);


    private:
        float speed;
};

