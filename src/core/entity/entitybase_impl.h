
/*
template <typename SceneNode>
EntityBase<SceneNode>::EntityBase()
{
	Reset();
}

template <typename SceneNode>
EntityBase<SceneNode>::~EntityBase()
{

}

void EntityBase<SceneNode>::LoadAnim(int animID)
{
	LoadAnimation(g_assets->GetAnim(animID));
}

template <typename SceneNode>
void EntityBase<SceneNode>::LoadTexture(Texture* tex)
{
	this->tex = tex;
	aabb.SetSize(tex->W(),tex->H());
}

template <typename SceneNode>
void EntityBase<SceneNode>::LoadAnimation(Animation* anim)
{
    this->anim = anim;
    animdata.Reset(anim);
    aabb.SetSize(anim->W(), anim->H());
}

template <typename SceneNode>
void EntityBase<SceneNode>::DeltaStep(uint32_t delta)
{

}

template <typename SceneNode>
void EntityBase<SceneNode>::Setup()
{
}

void EntityBase<SceneNode>::RecheckPosition()
{
	EntityBase* p;
	if(prev&&prev->X()>X()) {
		for( p = prev ; p && p->X() > X() ;p=p->prev);
		//printf("res PREV[%d]: %f-%f=%f\n",this,X(),p->X(),X()-p->X());fflush(stdout); }
		if(!p) {
			printf("NULO!!\n");
			//prev = NULL;
			//next = p;
		} else {
			prev->next = next;
			next->prev = prev;

			next = p->next;
			prev = p;
			p->next->prev = this;
			p->next = this;
			//InsertForward(p);
		}
	} else if(next&&X()-next->X()>0) {
		for(p=next; p && X() - p->X() >0;p=p->next);
		// { printf("res NEXT[%d]: %f-%f=%f\n",this,p->X(),X(),p->X()-X());fflush(stdout); }
		if(!p) {
			printf("NULO!!\n");
		} else {
			// desenlazamos de la posicion actual
			prev->next = next;
			next->prev = prev;

			// enlazamos en la nueva
			prev = p->prev;
			next = p;
			p->prev->next = this;
			p->prev = this;

			//InsertBackward(p);
		}
	} else {
		// void
	}
}

template <typename SceneNode>
void EntityBase<SceneNode>::Step()
{

}

template <typename SceneNode>
void EntityBase<SceneNode>::AnimationStep()
{
	
}


template <typename SceneNode>
void EntityBase<SceneNode>::HandleCollision(EntityBase* other)
{

}

template <typename SceneNode>
void EntityBase<SceneNode>::Reset()
{
}

template <typename SceneNode>
void EntityBase<SceneNode>::Cleanup()
{
}

void EntityBase<SceneNode>::InsertForward(EntityBase* p)
{
	next=p->next;
	prev=p;
	prev->next=this;
	next->prev=this;
}

void EntityBase<SceneNode>::InsertBackward(EntityBase* p)
{
	next=p;
	prev=p->prev;
	prev->next=this;
	next->prev=this;
}

void EntityBase<SceneNode>::AddToWorld(EntityBase *ref)
{
}

void EntityBase<SceneNode>::FreeFromWorld()
{
    prev->next=next;
	next->prev=prev;
}
*/

template <typename SceneNode>
bool EntityBase<SceneNode>::IsDestroyed()
{
    return destroyed;
}


template <typename SceneNode>
void EntityBase<SceneNode>::Destroy()
{
    //Cleanup();
    destroyed=true;
    //EntityBase<SceneNode>::remqueue.push_back(this);
	// en cola?
	//delete this;
	//world->FreeEntityBase(this);
}
