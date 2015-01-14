
#include "horderscene.h"

#include "../physics/collisions.h"
#include "../renderer/rendererall.h"
#include "../entity/entitybase.h"

/*
typedef HOrderScene::EntityBase SceneEntity;
class EntityBase : public SceneEntity { }
*/

HOrderScene::HOrderScene( SDL_Renderer* sdlrenderer )
{
	collisions = new Collisions();
	renderer = new RendererAll();
	this->sdlrenderer = sdlrenderer;

	inicial = new EntityBase<HOrderScene>();
	final = new EntityBase<HOrderScene>();

	inicial->Cleanup();
	final->Cleanup();
	inicial->collisionGroup = CG_BALIZA;
	final->collisionGroup = CG_BALIZA;

	inicial->next = final;
	inicial->prev = nullptr;
	inicial->X(-1000000);

	final->next = NULL;
	final->prev = inicial;
	final->X(1000000);

	collisions->SetRoot(inicial);
	renderer->SetRef(inicial);
}

HOrderScene::~HOrderScene()
{
	HOrderScene::Node* cur = inicial;
	HOrderScene::Node* next;
	while( cur != NULL )
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	delete collisions;
	delete renderer;
}

void HOrderScene::FreeFromWorld( EntityBase<HOrderScene>* n )
{
    n->prev->next = n->next;
	n->next->prev = n->prev;
}

void HOrderScene::AddEntity( EntityBase<HOrderScene>* e )
{
	// funciona sin comprobar nulls porque
	// metemos dos balizas al principio y al
	// final a mano, y todo va entre estas
	// dos balizas

	// hacer el direccionamiento en un pool para tener
	// acceso directo y/o hacer una busqueda binaria.
	// De esta forma sabremos el indice en el array de una entidad
	// sabiendo su direccion pool[(entidad - base)]
	EntityBase<HOrderScene>* toadd;
	toadd = e;
	EntityBase<HOrderScene>* p=inicial;
	//printf("ADDIN'\n");

	/*
	if(toadd->X() > p->datap->X()-e->X() > 0) {
		// mirar hacia detras
		for(; p && toadd->X() > p->X() ; p = p->prev ) {}
		toadd->prev = p;
		toadd->next = p->next;
		p->next->prev = toadd;
		p->next = toadd;
		//InsertForward(toadd,p);
	} else {// if(X()-p->X()>0) {
		// mirar hacia delante
		*/
		for(; p && p->X() < toadd->X() ;p=p->next);
		toadd->next = p;
		toadd->prev = p->prev;
		p->prev->next = toadd;
		p->prev = toadd;
		//InsertBackward(toadd,p);
	//}

}

void HOrderScene::RecheckPosition( EntityBase<HOrderScene>* n )
{
	EntityBase<HOrderScene>* p;
	if( n->prev && n->prev->X() > n->X() )
	{
		for( p = n->prev ; p && p->X() > n->X() ; p=p->prev);
		//printf("res PREV[%d]: %f-%f=%f\n",this,X(),p->X(),X()-p->X());fflush(stdout); }
		if(!p) {
			printf("NULO!!\n");
			//prev = NULL;
			//next = p;
		} else {
			n->prev->next = n->next;
			n->next->prev = n->prev;

			n->next = p->next;
			n->prev = p;
			p->next->prev = n;
			p->next = n;
			//InsertForward(p);
		}
	} else if( n->next && n->next->X() < n->X() ) {
		for(p=n->next; p && p->X() > n->X() ; p = p->next );
		// { printf("res NEXT[%d]: %f-%f=%f\n",this,p->X(),X(),p->X()-X());fflush(stdout); }
		if(!p) {
			printf("NULO!!\n");
		} else {
			// desenlazamos de la posicion actual
			n->prev->next = n->next;
			n->next->prev = n->prev;

			// enlazamos en la nueva
			n->prev = p->prev;
			n->next = p;
			p->prev->next = n;
			p->prev = n;

			//InsertBackward(p);
		}
	} else {
		// void
	}
}

void HOrderScene::InsertForward(EntityBase<HOrderScene>* from, EntityBase<HOrderScene>* to)
{
	from->next=to->next;
	from->prev=to;
	from->prev->next=from;
	from->next->prev=from;
}

void HOrderScene::InsertBackward(EntityBase<HOrderScene>* from, EntityBase<HOrderScene>* to)
{
	from->next=to;
	from->prev=to->prev;
	from->prev->next=from;
	from->next->prev=from;
}

void HOrderScene::Step(uint32_t time)
{
	EntityBase<HOrderScene>* p=inicial;
	EntityBase<HOrderScene>* aux, *tmp;
	int i=0;
	for(;p;p=p->next) {
		/*
		switch( p->collisionGroup )
		{
			case CG_ENEMY: printf("E"); break;
			case CG_PLAYER: printf("P"); break;
			case CG_BULLET: printf("B"); break;
			case CG_BALIZA: printf("|"); break;
			case CG_SPAWNER: printf("+"); break;
		}
		printf(" - ");
		*/
		if( p->IsDestroyed() )
		{
			// cleanup / store to free mem
			p->Cleanup();
			p->Reset();
			tmp = p;

			// store next to process
			aux = p->next;

			// unlink
			p->prev->next = p->next;
			p->next->prev = p->prev;

			// restore
			p = aux;

			// safely free mem
			delete tmp;
		}
		else
		{
			if( p->MovedSinceLastFrame() )
			{
				RecheckPosition( p );
				p->ClearMoved();
			}
			p->Step();
			p->DeltaStep(time);
		}
	}
	//printf("\n");

	collisions->Process();
	renderer->Render( sdlrenderer );


}

