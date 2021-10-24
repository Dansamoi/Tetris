#pragma once
#define LEFT_BORDER 480
#define RIGHT_BORDER 800
#define B_SIZE 32
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"

class TextureManager {
public:
	static SDL_Texture* Loadtexture(const char* fileName, int r, int g, int b);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};

