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
}

void Map::Add(Shape* s)
{
	for (auto block : s->blocks)
	{
		theMap[(int)((block->xpos - LEFT_BORDER) / B_SIZE)][(int)(block->ypos / B_SIZE)] = 1;
	}
}

void Map::Debug()
{
	for (auto v : theMap)
	{
		for (auto inV : v)
		{
			if (inV == 1) cout << "# ";
			else cout << ". ";
		}
		cout << endl;
	}
	cout << endl;
}

int Map::Top(int x)
{
	vector<int> column = theMap[(int)((x - LEFT_BORDER) / B_SIZE)];
	for (int i = 0; i < column.size(); i++) {
		if (column[i] == 1) return i * B_SIZE;
	}
	return HEIGHT;
}

Map::~Map()
{

}
