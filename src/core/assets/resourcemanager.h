#pragma once

class ResourceManager
{
private:

public:
    ResourceManager();
    ~ResourceManager();

	SDL_Surface* GetSurf(int surfID)
	{ return surfaces[surfID]; }

	Tileset* GetTileset(int tsetID)
	{ return tilesets[tsetID]; }

	Animation* GetAnim(int animID)
	{ return anims[animID]; }

    void Cleanup() {
		for(int i=0;i<4;i++) {
			SDL_FreeSurface(surfaces[i]);
		}

		for(size_t i=0;i<4;i++) {
			delete tilesets[i];
		}

		for(size_t i=0;i<3;i++) {
			delete anims[i];
		}

	}

};
