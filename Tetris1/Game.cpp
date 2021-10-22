#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Shape.h"
#include "Map.h"

Shape* shape;
SDL_Event Game::event;
Map Game::map = Map();

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystems Initialised!..." << endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			cout << "Window created!" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			cout << "Renderer created!" << endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}
	shape = new Shape(renderer, (LEFT_BORDER + RIGHT_BORDER) / 2 -  B_SIZE, 0, Type(rand() % 7));
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	if(!shape->Colide()) shape->Update();
	else {
		map.Add(shape);
		shape = new Shape(renderer, (LEFT_BORDER + RIGHT_BORDER) /2 -  B_SIZE, 0, Type(rand() % 7));
		map.Debug();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//this is where we would add stuff to render
	shape->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Cleaned" << endl;
}
