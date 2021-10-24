#pragma once
#include "Data.h"
#include "Map.h"

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	static SDL_Event event;
	static Map map;
	static SDL_Renderer* renderer;

	bool running() { return isRunning; };
	static int rgb[8][3];
};

