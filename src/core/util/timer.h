#ifndef __TIMER_H__
#define __TIMER_H__

#include <cstdint>
#include <SDL2/SDL.h>

class Timer {
public:
	void Reset ()
	{ last = SDL_GetTicks(); }
	uint32_t Get ()
	{ return SDL_GetTicks()-last; }

private:
	uint32_t last;
};

#endif

