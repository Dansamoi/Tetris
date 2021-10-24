#pragma once
#include "Data.h"

class TextureManager {
public:
	static SDL_Texture* Loadtexture(const char* fileName, int r, int g, int b);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

