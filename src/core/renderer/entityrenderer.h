#pragma once

#include <SDL2/SDL.h>
#include "../scene/horderscene.h"
#include "../entity/entitybase.h"



class EntityRenderer
{
public:
	EntityRenderer();
	virtual ~EntityRenderer();

	void Render(SDL_Renderer*);
	void SetRef(EntityBase<HOrderScene>*);
		// entidad de referencia para el renderer

protected:
	void TryRenderEntity(EntityBase<HOrderScene>*,SDL_Renderer*);
		// chequea si una entidad tiene animación o textura
		// en cuyo caso, la pinta en el renderer pasado por
		// parámetro

	EntityBase<HOrderScene>* ref;

};
