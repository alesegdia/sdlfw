#ifndef __SPAWNER_H__
#define __SPAWNER_H__

#include "../../../core/entity/entitybase.h"
#include "../../../core/math/random.h"
#include "../gameinfo.h"

class EntityFactory;

class Spawner : public EntityBase<HOrderScene> {
public:
	//Spawner (int);
	Spawner(EntityFactory* f);
	virtual ~Spawner ();

	void Setup();
	void Step();
	void Cleanup();

	GameEntity* SpawnEnemy(float ypos);

private:
	EntityFactory* factory;
	int nextSpawn;
	Timer spawnTimer;
	RNG* r;
	int respawnTime;
	int estado;
	int spawns;
	int nextY;

	static const int STATE_SPAWNING=0;
	static const int STATE_WAITING=1;

};


#endif

