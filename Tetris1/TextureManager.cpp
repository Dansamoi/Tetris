#pragma once
#include "TextureManager.h"

SDL_Texture* TextureManager::Loadtexture(const char* texture, SDL_Renderer* ren, int r, int g, int b) {
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_SetTextureColorMod(tex, r, g, b);
	SDL_FreeSurface(tempSurface);

	return tex;
}


