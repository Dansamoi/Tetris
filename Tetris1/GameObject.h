#pragma once
#include "Data.h"
class GameObject
{
public:
	GameObject(const char* textureSheet, int x, int y, Type type);
	~GameObject();

	void Update();
	void Render();
	int xpos, ypos;
	int speed = 2;
private:
	int r, g, b;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

