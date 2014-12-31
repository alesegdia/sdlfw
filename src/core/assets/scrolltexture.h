
#pragma once

#include "texture.h"

class ScrollTexture
{

private:

	float scrollpos;
	float step;
	float win_width;
	Texture* tex;

public:

	ScrollTexture( Texture* tex, float step, float win_width )
	{
		this->tex = tex;
		this->scrollpos = 0;
		this->step = step;
		this->win_width = win_width;
	}

	~ScrollTexture(){}

	void Render( SDL_Renderer* sdlrenderer )
	{
		if( scrollpos < -tex->W() )
		{
			scrollpos = 0;
			tex->Render( scrollpos, 0, sdlrenderer );
		}
		else if ( scrollpos < -(tex->W()-win_width) ) {
			tex->Render( scrollpos, 0, sdlrenderer );
			tex->Render( scrollpos+tex->W(), 0, sdlrenderer );
			// pintar dos
		} else if( scrollpos < 0) {
			// pintar uno
			tex->Render( scrollpos, 0, sdlrenderer );
		}
		scrollpos-=step;

	}

};
