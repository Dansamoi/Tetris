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

enum Rotation {
	R1,
	R2,
	R3,
	R4,
	NON
};

class Shape
{
public:
	Shape(SDL_Renderer* ren, int xPos, int yPos, Type type);
	~Shape();
	bool isTouchLeft();
	bool isTouchRight();
	void Update();
	void Render();
	void Move(int side);//1 - right, -1 - left
	bool Colide();
	void Rotate();
	Rotation mode = NON;
	Type type;
	int xPos;
	int yPos;
private:
	vector<GameObject*> blocks;

};

