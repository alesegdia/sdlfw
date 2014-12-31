
#pragma once

#include "scene.h"
#include "../entity/entitybase.h"

class Collisions;
class RendererAll;


class HOrderScene
{

public:

	struct Node {
		EntityBase<HOrderScene>* prev;
		EntityBase<HOrderScene>* next;
		Node(){}
		virtual ~Node(){}
	};


private:

	//void UnlinkEntity( Node* e );
	//void LinkEntity( Node* e );
	void RecheckPosition( EntityBase<HOrderScene>* e );

	void FreeFromWorld( EntityBase<HOrderScene>* e );
	void InsertForward( EntityBase<HOrderScene>* from, EntityBase<HOrderScene>* to );
	void InsertBackward( EntityBase<HOrderScene>* from, EntityBase<HOrderScene>* to );

	EntityBase<HOrderScene>* inicial;
	EntityBase<HOrderScene>* final;

	Collisions* collisions;
	RendererAll* renderer;
	SDL_Renderer* sdlrenderer;


public:

	HOrderScene( SDL_Renderer* );
	~HOrderScene();

	void Step(uint32_t);

	void AddEntity(EntityBase<HOrderScene>*);



};
