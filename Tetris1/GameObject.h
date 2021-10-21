#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y, int r, int g, int b);
	~GameObject();

	void Update();
	void Render();
	int xpos, ypos;
	int speed = 2;
private:
	int r, g, b;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

