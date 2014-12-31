#pragma once

#include "../../../core/entity/entitybase.h"
#include "../gameinfo.h"

class Bullet : public EntityBase<HOrderScene>
{
    public:
        Bullet();
        virtual ~Bullet();

        void SetSpeed(float s)
        { this->speed = s; }

        void Step();
        void HandleCollision(EntityBase* other);


    private:
        float speed;
};

