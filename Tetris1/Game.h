#pragma once
#define WIDTH 1280
#define HEIGHT 800
#define LEFT_BORDER 480
#define RIGHT_BORDER 800
#define B_SIZE 32
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	static SDL_Event event;

	bool running() { return isRunning; };

};

