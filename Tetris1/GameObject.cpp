#include "GameObject.h"
#include "Game.h"
GameObject::GameObject(const char* textureSheet, int x, int y, int r, int g, int b)
{
	objTexture = TextureManager::Loadtexture(textureSheet, r, g, b);
	cout << objTexture;

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{
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
