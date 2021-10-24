#pragma once
#include "Data.h"
#include "GameObject.h"

using namespace std;

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
	Shape(int xPos, int yPos, Type type);
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
	vector<GameObject*> blocks;
};

