#pragma once
#include "Map.h"
#include "Game.h"

Map::Map()
{
	for (int i = 0; i < 10; i++) {
		vector<SDL_Texture*> texCol;

		for (int j = 0; j < 25; j++) {
			texCol.push_back(0);
		}
		mapTexture.push_back(texCol);
	}

	for (int i = 0; i < 10; i++) {
		vector<int> column;

		for (int j = 0; j < 25; j++) {
			column.push_back(0);
		}
		theMap.push_back(column);
	}
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

int Map::Top(int x, int y)
{
	y = y / B_SIZE;
	vector<int> column = theMap[(int)((x - LEFT_BORDER) / B_SIZE)];
	for (int i = y; i < column.size(); i++) {
		if (column[i]) return i * B_SIZE;
	}
	return HEIGHT;
}

int Map::Sides(int x, int y, int side)
{
	x = (x - LEFT_BORDER) / B_SIZE;
	y = y / B_SIZE;

	if (side == 1) {
		for (int col = x + 1; col < 10; col++) {
			if (theMap[col][y]) return col * B_SIZE + LEFT_BORDER;
		}
		return RIGHT_BORDER;
	}
	else {
		for (int col = x - 1; col >= 0; col--) {
			if (theMap[col][y]) return col * B_SIZE + LEFT_BORDER + B_SIZE;
		}
		return LEFT_BORDER;
	}
}

Map::~Map()
{
}

void Map::CleanRow(int theRow) {
	for (int col = 0; col < 10; col++) {
		for (int row = theRow; row > 1; row--) {
			theMap[col][row] = theMap[col][row - 1];
		}
	}
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
		if (full) CleanRow(row);
	}
}

void Map::DrawMap()
{
	
	for (auto v : mapTexture) {
		for (auto tex : v) {
			SDL_DestroyTexture(tex);
		}
	}

	int r = 255, g = 255, b = 255;
	for (int col = 0; col < 10; col++) {
		for (int row = 0; row < 25; row++) {
			dest.x = LEFT_BORDER + col * B_SIZE;
			dest.y = row * B_SIZE;
			int type = theMap[col][row];
			if (!type) type = 7;
			else type -= 1;
			
			mapTexture[col][row] = TextureManager::Loadtexture("assets/block.png", Game::rgb[type][0], Game::rgb[type][1], Game::rgb[type][2]);
			TextureManager::Draw(mapTexture[col][row], src, dest);

		}
	}
}
