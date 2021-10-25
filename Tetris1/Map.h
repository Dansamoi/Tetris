#pragma once
#include "Data.h"
#include "Shape.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void fullRowCheck();
	void DrawMap();

	void Add(Shape* s);
	void Debug();
	//void Render(Shape* s, int r, int g, int b);
	int Top(int x, int y);
	int Sides(int x, int y, int side);
private:
	vector<vector<int>> theMap;
	vector<vector<SDL_Texture*>> mapTexture;
	SDL_Rect src, dest;
	SDL_Texture* sidesTex;

};

