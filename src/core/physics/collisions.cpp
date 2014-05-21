#include "collisions.h"
#include "../entity/entity.h"

Collisions::Collisions ()
{
	 // ctor
}

Collisions::~Collisions ()
{
	 // dtor
}


void Collisions::Process()
{
	Entity* e1, *e2;
	e1 = root;
	for(;e1;e1=e1->Next()) {
		// check forward
		e2=e1->Next();
		if(e2){
		for(;e2&&e2->X()-e1->HalfWidth()>0;e2=e2->Next()) {
			if(e2 && e1!=e2 && e1->CollideWith(e2)){//e1->colmask & e2->colmask && CheckCollision(e1,e2))
				printf("COL1: %d contra %d\n",e1->GetCollisionGroup(),e2->GetCollisionGroup());
				e1->HandleCollision(e2);
			}
		}}

		// check backwards
		e2=e1->Prev();
		if(e2) {
		for(;e2&&e1->HalfWidth()-e2->X()>0;e2=e2->Prev())
			//printf("overjiar\n");
			if(e2 && e1!=e2 && e1->CollideWith(e2)) {// e1->colmask & e2->colmask && CheckCollision(e1,e2))
				printf("COL2: %d contra %d\n",e1->GetCollisionGroup(),e2->GetCollisionGroup());
				e1->HandleCollision(e2);
			}
		}
	}
}

/*
bool Collisions::SDLTextureCollision(Entity* a, Entity* b)
{
	SDL_Texture* a_tex = a->GetTexture();
	SDL_Texture* b_tex = b->GetTexture();
	int dx = a->X() - b->X();
	int dy = a->Y() - b->Y();
	int xmin = b->X()-;
	if(dx>0) {
		if(dy>0) {
			// 1er cuadrante
			a_ini = a->X();
			a_fin = a->X() +
			b_ini =
		} else {
			// 2o cuadrante
		}
	} else {
		if(dy>0) {
			// 4p cuadrante
		} else {
			// 3er cuadrante
		}
	}
}
*/
