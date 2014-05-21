#include "entity.h"

Entity::Entity()
{
	tex=NULL;
	next=prev=NULL;
	lookLeft=false;

	Cleanup();
}

Entity::~Entity()
{

}

/*
void Entity::LoadAnim(int animID)
{
	LoadAnimation(g_assets->GetAnim(animID));
}
*/

void Entity::LoadTexture(Texture* tex)
{
	this->tex = tex;
	aabb.SetSize(tex->W(),tex->H());
}

void Entity::LoadAnimation(Animation* anim)
{
    this->anim = anim;
    animdata.Reset(anim);
    aabb.SetSize(anim->W(), anim->H());
}

void Entity::DeltaStep(uint32_t delta)
{

}

void Entity::Setup()
{

}

void Entity::RecheckPosition()
{
	Entity* p;
	if(prev&&prev->X()-X()>0) {
		for(p=prev;p&&p->X()-X()>0;p=p->prev);
		//printf("res PREV[%d]: %f-%f=%f\n",this,X(),p->X(),X()-p->X());fflush(stdout); }
		if(!p) {
			printf("NULO!!\n");
			//prev = NULL;
			//next = p;
		} else {
			prev->next = next;
			next->prev = prev;
			InsertForward(p);
		}
	} else if(next&&X()-next->X()>0) {
		for(p=next;p&&X()-p->X()>0;p=p->next);
		// { printf("res NEXT[%d]: %f-%f=%f\n",this,p->X(),X(),p->X()-X());fflush(stdout); }
		if(!p) {
			printf("NULO!!\n");
		} else {
			prev->next = next;
			next->prev = prev;
			InsertBackward(p);
		}
	} else {
		// void
	}
}

void Entity::Step()
{

}

void Entity::AnimationStep()
{
	anim->Update(animdata);
}


void Entity::HandleCollision(Entity* other)
{

}

void Entity::Cleanup()
{
    anim=NULL;
   	destroyed=false;

}

void Entity::InsertForward(Entity* p)
{
	next=p->next;
	prev=p;
	prev->next=this;
	next->prev=this;
}

void Entity::InsertBackward(Entity* p)
{
	next=p;
	prev=p->prev;
	prev->next=this;
	next->prev=this;
}

void Entity::AddToWorld(Entity *ref)
{
	// funciona sin comprobar nulls porque
	// metemos dos balizas al principio y al
	// final a mano, y todo va entre estas
	// dos balizas

	Entity* p=ref;
	//printf("ADDIN'\n");

	if(p->X()-X() > 0) {
		// mirar hacia detras
		for(;p&&X()-p->X()<0;p=p->prev) {}
		InsertForward(p);
	} else {// if(X()-p->X()>0) {
		// mirar hacia delante
		for(;p&&p->X()-X()<0;p=p->next);
		InsertBackward(p);
	}
}

bool Entity::IsDestroyed()
{
    return destroyed;
}

void Entity::FreeFromWorld()
{
    prev->next=next;
	next->prev=prev;
}

void Entity::Destroy()
{
    //Cleanup();
    destroyed=true;
    //Entity::remqueue.push_back(this);
	// en cola?
	//delete this;
	//world->FreeEntity(this);
}
