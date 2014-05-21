#ifndef __SPAWNER_H__
#define __SPAWNER_H__

#include "../../../core/entity/entity.h"
#include "../../../core/math/random.h"

class EntityFactory;

class Spawner : public Entity {
public:
	//Spawner (int);
	Spawner(EntityFactory* f);
	virtual ~Spawner ();

	void Setup();
	void Step();
	void Cleanup();

	Entity* SpawnEnemy(float ypos);

private:
	EntityFactory* factory;
	int nextSpawn;
	Timer spawnTimer;
	Random* r;
	int respawnTime;
	int estado;
	int spawns;
	int nextY;

	static const int STATE_SPAWNING=0;
	static const int STATE_WAITING=1;

};


#endif

