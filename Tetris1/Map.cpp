#pragma once
#include "Map.h"

Map::Map()
{
	for (int i = 0; i < 10; i++) {
		vector<int> column;

		for (int i = 0; i < 25; i++) {
			column.push_back(0);
		}
		theMap.push_back(column);
	}
	blockTex = TextureManager::Loadtexture("block.png", 255, 255, 255);
	sidesTex = TextureManager::Loadtexture("block.png", 255, 255, 255);
	src.h = B_SIZE;
	src.w = B_SIZE;
	src.x = 0;
	src.y = 0;

	dest.x = 0;
	dest.y = 0;
	dest.w = src.w;
	dest.h = src.h;
}

void Map::Add(Shape* s)
{
	for (auto block : s->blocks)
	{
		theMap[(block->xpos - LEFT_BORDER) / B_SIZE][block->ypos / B_SIZE] = (int)s->type + 1;
	}

}

void Map::Debug()
{
	for (auto v : theMap)
	{
		for (auto inV : v)
		{
			if (inV) cout << "# ";
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
}

/*
void Map::Render(Shape* s, SDL_Renderer* ren, int r, int g, int b)
{
	SDL_Texture* tex = TextureManager::Loadtexture("block.png", ren, r, g, b);
}
*/

int Map::Top(int x)
{
	vector<int> column = theMap[(int)((x - LEFT_BORDER) / B_SIZE)];
	for (int i = 0; i < column.size(); i++) {
		if (column[i]) return i * B_SIZE;
	}
	return HEIGHT;
}

Map::~Map()
{
}

void Map::fullRowCheck() {
	bool full = true;
	int theRow = 0;
	for (int row = 0; row < 25; row++) {
		full = true;
		theRow = row;
		for (int col = 0; col < 10; col++) {
			if (!theMap[col][row]) {
				full = false;
			}
		}
		if (full) break;
	}

	if (full) {
		for (int col = 0; col < 10; col++) {
			for (int row = theRow; row > 1; row--) {
				theMap[col][row] = theMap[col][row - 1];
			}
		}
	}
}

void Map::DrawMap()
{
	int r = 255, g = 255, b = 255;
	for (int col = 0; col < 10; col++) {
		for (int row = 0; row < 25; row++) {
			dest.x = LEFT_BORDER + col * B_SIZE;
			dest.y = row * B_SIZE;

			switch (theMap[col][row]) {
			case 1:
				r = 255;
				g = 150;
				b = 0;
				break;
			case 2:
				r = 0;
				g = 0;
				b = 255;
				break;
			case 3:
				r = 255;
				g = 255;
				b = 0;
				break;
			case 4:
				r = 0;
				g = 200;
				b = 255;
				break;
			case 5:
				r = 0;
				g = 255;
				b = 0;
				break;
			case 6:
				r = 255;
				g = 0;
				b = 255;
				break;
			case 7:
				r = 255;
				g = 0;
				b = 0;
				break;

			default:
				r = 50;
				g = 50;
				b = 50;
				break;
			}
			blockTex = TextureManager::Loadtexture("assets/block.png", r, g, b);
			TextureManager::Draw(blockTex, src, dest);

		}
	}
}
