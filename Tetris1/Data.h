#pragma once
#define WIDTH 1280
#define HEIGHT 800
#define LEFT_BORDER 480
#define RIGHT_BORDER 800
#define B_SIZE 32
#include <iostream>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

using namespace std;

enum Type {
	LSHAPE,
	JSHAPE,
	OSHAPE,
	ISHAPE,
	SSHAPE,
	TSHAPE,
	ZSHAPE,
	NOTYPE
};

