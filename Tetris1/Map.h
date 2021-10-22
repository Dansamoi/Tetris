#pragma once
#include "Data.h"
#include "Shape.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void Add(Shape* s);
	void Debug();
	int Top(int x);
private:
	vector<vector<int>> theMap;

};

