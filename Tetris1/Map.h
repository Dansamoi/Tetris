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
	int Top(int x);
private:
	vector<vector<int>> theMap;
	SDL_Rect src, dest;
	SDL_Texture* blockTex;
	SDL_Texture* sidesTex;

};

