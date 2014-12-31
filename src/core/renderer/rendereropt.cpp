#include "rendereropt.h"
#include "../entity/entitybase.h"

/*
RendererOpt::RendererOpt ()
{
	 // ctor
}

RendererOpt::~RendererOpt ()
{
	 // dtor
}


void RendererOpt::Render(SDL_Renderer* display)
{
	// poner la camara siempre a la derecha o a la izquierda, para evitar
	// problema cuando se vaya de un lado a otro, que puede pintarse en una
	// posicion un jugador y en otra otra segun si la camara esta a la izquierda
	// o derecha
	Entity* p;
	float camx = cam->X();

	// p->HalfWidth => maxEntityHalfWidth
	int WinWidth = 1000;
	for(p=cam->Next();p->X()-camx<WinWidth+maxEntityHalfWidth&&p;p=p->Next())
		SDL_BlitSurface(p->GetSurface(),p->GetFrame(),display,p->GetRect());

	for(p=cam->Prev();camx-p->X()<WinWidth+maxEntityHalfWidth&&p;p=p->Prev())
		SDL_BlitSurface(p->GetSurface(),p->GetFrame(),display,p->GetRect());
}

void RendererOpt::SetCamera(EntityBase* cam)
{
	this->cam = cam;
}
*/
