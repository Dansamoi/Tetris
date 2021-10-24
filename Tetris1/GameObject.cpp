#include "GameObject.h"
#include "Game.h"
GameObject::GameObject(const char* textureSheet, int x, int y, Type type)
{
	objTexture = TextureManager::Loadtexture(textureSheet, Game::rgb[type][0], Game::rgb[type][1], Game::rgb[type][2]);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(objTexture);
}

void GameObject::Update()
{
	ypos += speed;

	srcRect.h = B_SIZE;
	srcRect.w = B_SIZE;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::Render()
{
	TextureManager::Draw(objTexture, srcRect, destRect);
}
