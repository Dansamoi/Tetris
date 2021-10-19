#pragma once
#include "SDL.h"
#include <vector>
#include "GameObject.h"
#include "Game.h"

using namespace std;

enum Type {
	LSHAPE,
	JSHAPE,
	OSHAPE,
	ISHAPE,
	SSHAPE,
	TSHAPE,
	ZSHAPE

};

class Shape
{
public:
	Shape(SDL_Renderer* ren, int xPos, int yPos, Type type);
	~Shape();
	void Update();
	void Render();
private:
	vector<GameObject*> blocks;

};

