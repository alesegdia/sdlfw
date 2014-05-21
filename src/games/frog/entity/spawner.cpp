#include "spawner.h"
#include "enemy.h"
#include "entityfactory.h"

#include "../constants.h"

Spawner::Spawner (EntityFactory* f)
{
	this->factory=f;
	 this->respawnTime = SPAWNER_RESPAWN_TIME;
	 this->estado = STATE_WAITING;
	 this->spawns = SPAWNER_N_SPAWNS;
	 //this->spawnTimer = respawnTime;
}

Spawner::~Spawner ()
{
	 // dtor
}

void Spawner::Setup()
{
	spawnTimer.Reset();
	r = new Random(time(nullptr));
}

void Spawner::Step()
{
	float tolBOT = SPAWNER_BOT_TOLERANCE;
	float tolTOP = SPAWNER_TOP_TOLERANCE;
	switch(estado) {
	case STATE_SPAWNING:
		if(spawns>0) {
			if(spawnTimer.Get() > SPAWNER_RESPAWN_TIME) {
				factory->SpawnEnemy(this,X()+100,nextY);
				spawnTimer.Reset();
				spawns--;
			}
		} else {
			spawnTimer.Reset();
			spawns = SPAWNER_N_SPAWNS;
			estado = STATE_WAITING;
		}
		break;
	case STATE_WAITING:
		if(spawnTimer.Get() > SPAWNER_WAIT_TIME)  {
			spawnTimer.Reset();
			estado=STATE_SPAWNING;
			nextY = r->get(tolTOP, Y()-tolBOT);
		}

		break;
	}
	// pensar en tiempo fijo

	//if(timer.Get() > nextSpawn)
	//	SpawnEnemy(0); // 0 no, random
}

void Spawner::Cleanup()
{
	delete r;
}

Entity* Spawner::SpawnEnemy(float ypos)
{
	//Enemy* e = factory->SpawnEnemy(X(),ypos);
}

