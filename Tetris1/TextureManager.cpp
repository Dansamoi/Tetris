#pragma once
#include "TextureManager.h"
#include "Game.h"

SDL_Texture* TextureManager::Loadtexture(const char* texture, int r, int g, int b) {
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_SetTextureColorMod(tex, r, g, b);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}


