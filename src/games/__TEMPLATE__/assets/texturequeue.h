
#pragma once

#include <SDL2/SDL.h>
#include "../../../core/math/random.h"
#include "../../../core/math/vec2.h"
#include "../../../core/assets/texture.h"
#include <vector>
#include <algorithm>

struct Item {
	float x;
	float speed;
	Texture* tex;
};

class TextureQueue
{

private:

	std::vector<Item> items;
	std::vector<Texture*> texs;
	RNG r;
	Vec2 next_spawn;
	Vec2 speed;
	float timer;


public:

	TextureQueue()
	{
		r.seed( 0xDEADBEEF );
		timer = 0;
		next_spawn.x = 100.f; // min
		next_spawn.y = 300.f; // max
		speed.x = 1.f;
		speed.y = 3.f;
	}

	void SubmitTextures( std::vector<Texture*>& tex )
	{
		texs = tex;
	}

	Texture* PickRandomTexture()
	{
		int ran = r.get(0, texs.size()-1);
		printf("%d\n", ran);
		return texs[ran];
	}

	void Step( SDL_Renderer* sdlrenderer )
	{
		timer--;
		if( timer <= 0 )
		{
			Item item;
			item.tex = PickRandomTexture();
			item.speed = r.get( speed.x, speed.y );
			printf("speed: %f\n", item.speed);
			item.x = 800;
			items.push_back( item );
			timer = r.get( next_spawn.x, next_spawn.y );
		}

		for( int i = 0; i < items.size(); i++ )
		{
			//printf("%f\n", items[i].x );
			items[i].x = items[i].x - items[i].speed;
			items[i].tex->Render( items[i].x, 600 - items[i].tex->H(), sdlrenderer );
		}

		items.erase(std::remove_if(items.begin(), items.end(),
                       [](Item it) { return it.x < -it.tex->W(); }), items.end());
	}

};
