#pragma once

#include <SDL2/SDL.h>
class Entity;

class EntityRenderer
{
public:
	EntityRenderer();
	virtual ~EntityRenderer();

	void Render(SDL_Renderer*);
	void SetRef(Entity*);
		// entidad de referencia para el renderer

protected:
	void TryRenderEntity(Entity*,SDL_Renderer*);
		// chequea si una entidad tiene animación o textura
		// en cuyo caso, la pinta en el renderer pasado por
		// parámetro

	Entity* ref;

};
