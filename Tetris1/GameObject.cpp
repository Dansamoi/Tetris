#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y, int r, int g, int b)
{
	renderer = ren;
	objTexture = TextureManager::Loadtexture(textureSheet, ren, r, g, b);

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
}

void GameObject::Update()
{
	ypos+=2;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
