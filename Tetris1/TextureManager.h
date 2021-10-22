#pragma once
#include "Data.h"

class TextureManager {
public:
	static SDL_Texture* Loadtexture(const char* fileName, SDL_Renderer* ren, int r, int g, int b);

};

