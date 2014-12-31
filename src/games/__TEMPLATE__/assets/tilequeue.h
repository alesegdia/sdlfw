#ifndef __TILEQUEUE_H__
#define __TILEQUEUE_H__

#include <SDL2/SDL.h>
#include "../../../core/math/random.h"
#include "../../../core/math/vec2.h"
#include "../../../core/assets/spritesheet.h"

struct Tile {
	float x; int n;
};

class TileQueue {
public:
	TileQueue ();
	virtual ~TileQueue ();

	void Initialize(Spritesheet*,size_t,const Vec2&,const Vec2&,float);
	void Step();
	void Draw(SDL_Renderer* sdlrenderer);
	void Debug();

private:

	void Add(float x, int n);
	size_t norm(size_t n)
	{ return n%MAX_CAPACITY; }
	int PickupTile()
	{ return r.get(range.x,range.y); }

	static const size_t MAX_CAPACITY = 128;
	Tile q[MAX_CAPACITY];
	Spritesheet *tileset;
	size_t capacity;
	size_t head; size_t tail;
	Vec2 range;
	Vec2 offset;
	float speed;
	RNG r;
	size_t head_, tail_;

};


#endif

