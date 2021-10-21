#include "Shape.h"

Shape::Shape(SDL_Renderer* ren, int xPos, int yPos, Type type)
{
	this->type = type;
	this->xPos = xPos;
	this->yPos = yPos;
	int r, g, b;
	switch (type) {
	case LSHAPE:
		r = 255;
		g = 150;
		b = 0;
		break;
	case JSHAPE:
		r = 0;
		g = 0;
		b = 255;
		break;
	case OSHAPE:
		r = 255;
		g = 255;
		b = 0;
		break;
	case ISHAPE:
		r = 0;
		g = 200;
		b = 255;
		break;
	case SSHAPE:
		r = 0;
		g = 255;
		b = 0;
		break;
	case TSHAPE:
		r = 255;
		g = 0;
		b = 255;
		break;
	case ZSHAPE:
		r = 255;
		g = 0;
		b = 0;
		break;

	default:
		break;
	}
	for (int i = 0; i < 4; i++) {
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos, r, g, b));
	}
	Rotate();
}

Shape::~Shape()
{
}

bool Shape::isTouchLeft() {
	for (auto block : blocks) {
		if (block->xpos <= LEFT_BORDER) return true;
	}
	return false;
}

bool Shape::isTouchRight() {
	for (auto block : blocks) {
		if (block->xpos >= RIGHT_BORDER - B_SIZE) return true;
	}
	return false;
}

void Shape::Update()
{
	int speed = 2;
	if (Game::event.type == SDL_KEYDOWN) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_d:
			if(!isTouchRight()) Move(1);
			break;
		case SDLK_a:
			if(!isTouchLeft()) Move(-1);
			break;
		case SDLK_s:
			speed = 10;
			break;
		case SDLK_r:
			Rotate();
			break;
		default:
			break;
		}
	}
	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_s:
			speed = 2;
			break;
		default:
			break;
		}
	}
	for (auto block : blocks) {
		block->speed = speed;
		block->Update();
	}
}

void Shape::Render()
{
	for (auto block : blocks) {
		block->Render();
	}
}

void Shape::Move(int side)
{
	xPos += side * B_SIZE;
	for (auto block : blocks) {
		block->xpos += B_SIZE * side;
	}
	
}

bool Shape::Colide() {
	for (auto block : blocks) {
		if (block->ypos >= HEIGHT - B_SIZE) return true;
	}

	return false;
}

void Shape::Rotate()
{
	if (mode < 3 && mode != NON) mode = Rotation(int(mode) + 1);
	else if(mode != NON) mode = R1;
	switch (type) {
	case LSHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos += B_SIZE; //x0 = B_SIZE
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos += B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos +=  B_SIZE * 2; //x2 =  B_SIZE * 2
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos; //y3 = 0
			mode = R1;
			break;
		case R1:
			blocks[1]->xpos -= B_SIZE; //x1 = 0
			blocks[1]->ypos -= B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos +=  B_SIZE * 2; //x2 =  B_SIZE * 2
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos += B_SIZE; //x3 =  B_SIZE * 2
			blocks[3]->ypos; //y3 = 0
			break;
		case R2:
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos -= B_SIZE; //y1 = 0
			blocks[2]->xpos -= B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos += B_SIZE; //y2 =  B_SIZE * 2
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos +=  B_SIZE * 2; //y3 =  B_SIZE * 2
			break;
		case R3:
			blocks[1]->xpos -= B_SIZE; //x1 = 0
			blocks[1]->ypos +=  B_SIZE * 2; //y1 =  B_SIZE * 2
			blocks[2]->xpos -= B_SIZE; //x2 = 0
			blocks[2]->ypos -= B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos -= B_SIZE; //y3 = B_SIZE
			break;
		case R4:
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos; //y1 =  B_SIZE * 2
			blocks[2]->xpos; // x2 = 0
			blocks[2]->ypos -= B_SIZE; //y2 = 0
			blocks[3]->xpos -= B_SIZE; //x3 = B_SIZE
			blocks[3]->ypos -= B_SIZE; //y3 = 0
			break;
		}
		break;
	case JSHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos += B_SIZE; //x0 = B_SIZE
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos; //x2 = 0
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			mode = R1;
			break;
		case R1:
			blocks[1]->xpos -= B_SIZE; //x1 = 0
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos -= B_SIZE; //x2 = 0
			blocks[2]->ypos -= B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos -= B_SIZE; //y3 = B_SIZE
			break;
		case R2:
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos +=  B_SIZE * 2; //y1 =  B_SIZE * 2
			blocks[2]->xpos += B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos -= B_SIZE; //y2 = 0
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos -= B_SIZE; //y3 = 0
			break;
		case R3:
			blocks[1]->xpos -= B_SIZE; //x1 = 0
			blocks[1]->ypos -= B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos += B_SIZE; //x2 =  B_SIZE * 2
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos +=  B_SIZE * 2; //y3 =  B_SIZE * 2
			break;
		case R4:
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos -= B_SIZE; //y1 = 0
			blocks[2]->xpos -= B_SIZE; // x2 = B_SIZE
			blocks[2]->ypos += B_SIZE; //y2 =  B_SIZE * 2
			blocks[3]->xpos -=  B_SIZE * 2; //x3 = 0
			blocks[3]->ypos; //y3 =  B_SIZE * 2
			break;
		}
		break;
	case ISHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos; //x0 = 0
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos += B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos +=  B_SIZE * 2; //x2 =  B_SIZE * 2
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos +=  B_SIZE * 3; //x3 =  B_SIZE * 3
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			mode = R1;
			break;
		case R1:
			blocks[0]->xpos -= B_SIZE; //x0 = 0
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos; //x1 = B_SIZE
			blocks[1]->ypos; //y1 = B_SIZE
			blocks[2]->xpos += B_SIZE; //x2 =  B_SIZE * 2
			blocks[2]->ypos -= B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 3
			blocks[3]->ypos -=  B_SIZE * 2; //y3 = B_SIZE
			break;
		case R2:
			blocks[0]->xpos +=  B_SIZE * 2; //x0 =  B_SIZE * 2
			blocks[0]->ypos -= B_SIZE; //y0 = 0
			blocks[1]->xpos += B_SIZE; //x1 =  B_SIZE * 2
			blocks[1]->ypos; //y1 = B_SIZE
			blocks[2]->xpos; //x2 =  B_SIZE * 2
			blocks[2]->ypos += B_SIZE; //y2 =  B_SIZE * 2
			blocks[3]->xpos -= B_SIZE; //x3 =  B_SIZE * 2
			blocks[3]->ypos +=  B_SIZE * 2; //y3 =  B_SIZE * 3
			break;
		case R3:
			blocks[0]->xpos -=  B_SIZE * 2; //x0 = 0
			blocks[0]->ypos +=  B_SIZE * 2; //y0 =  B_SIZE * 2
			blocks[1]->xpos -= B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos += B_SIZE; //y1 =  B_SIZE * 2
			blocks[2]->xpos; //x2 =  B_SIZE * 2
			blocks[2]->ypos; //y2 =  B_SIZE * 2
			blocks[3]->xpos += B_SIZE; //x3 =  B_SIZE * 3
			blocks[3]->ypos -= B_SIZE; //y3 =  B_SIZE * 2
			break;
		case R4:
			blocks[0]->xpos += B_SIZE; //x0 = B_SIZE
			blocks[0]->ypos -=  B_SIZE * 2; //y0 = 0
			blocks[1]->xpos; //x1 = B_SIZE
			blocks[1]->ypos -= B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos -= B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos; //y2 =  B_SIZE * 2
			blocks[3]->xpos -=  B_SIZE * 2; //x3 = B_SIZE
			blocks[3]->ypos += B_SIZE; //y3 =  B_SIZE * 3
			break;
		}
		break;
	case SSHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos += B_SIZE; //x0 = B_SIZE
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos += B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos += B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos; //y2 = 0
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos; //y3 = 0
			mode = R1;
			break;
		case R1:
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos += B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos; //x2 = B_SIZE
			blocks[2]->ypos -=  B_SIZE * 2; //y2 = 0
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos -= B_SIZE; //y3 = 0
			break;
		case R2:
			blocks[1]->xpos +=  B_SIZE * 2; //x1 =  B_SIZE * 2
			blocks[1]->ypos; //y1 = B_SIZE
			blocks[2]->xpos; //x2 = B_SIZE
			blocks[2]->ypos; //y2 = 0
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos +=  B_SIZE * 2; //y3 =  B_SIZE * 2
			break;
		case R3:
			blocks[1]->xpos; //x1 =  B_SIZE * 2
			blocks[1]->ypos; //y1 = B_SIZE
			blocks[2]->xpos; //x2 = B_SIZE
			blocks[2]->ypos +=  B_SIZE * 2; //y2 =  B_SIZE * 2
			blocks[3]->xpos -=  B_SIZE * 2; //x3 = 0
			blocks[3]->ypos; //y3 =  B_SIZE * 2
			break;
		case R4:
			blocks[1]->xpos -=  B_SIZE * 2; //x1 = 0
			blocks[1]->ypos -= B_SIZE; //y1 = 0
			blocks[2]->xpos; //x2 = B_SIZE
			blocks[2]->ypos; //y2 =  B_SIZE * 2
			blocks[3]->xpos; //x3 = 0
			blocks[3]->ypos -= B_SIZE; //y3 = B_SIZE
			break;
		}
		break;
	case TSHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos += B_SIZE; //x0 = B_SIZE
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos; //x2 = 0
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			mode = R1;
			break;
		case R1:
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos -= B_SIZE; //y1 = 0
			blocks[2]->xpos -= B_SIZE; //x2 = 0
			blocks[2]->ypos -= B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos += B_SIZE; //x3 =  B_SIZE * 2
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			break;
		case R2:
			blocks[1]->xpos; //x1 = B_SIZE
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos += B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos += B_SIZE; //y2 =  B_SIZE * 2
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos; //y3 = B_SIZE
			break;
		case R3:
			blocks[1]->xpos -= B_SIZE; //x1 = 0
			blocks[1]->ypos += B_SIZE; //y1 = B_SIZE
			blocks[2]->xpos; //x2 = B_SIZE
			blocks[2]->ypos; //y2 =  B_SIZE * 2
			blocks[3]->xpos; //x3 =  B_SIZE * 2
			blocks[3]->ypos; //y3 = B_SIZE
			break;
		case R4:
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos; //y1 = B_SIZE
			blocks[2]->xpos; //x2 = B_SIZE
			blocks[2]->ypos; //y2 =  B_SIZE * 2
			blocks[3]->xpos -= B_SIZE; //x3 = B_SIZE
			blocks[3]->ypos -= B_SIZE; //y3 = 0
			break;
		}
		break;
	case ZSHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos += B_SIZE; //x0 = B_SIZE
			blocks[0]->ypos += B_SIZE; //y0 = B_SIZE
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos += B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos; //y2 = 0
			blocks[3]->xpos +=  B_SIZE * 2; //x3 =  B_SIZE * 2
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			mode = R1;
			break;
		case R1:
			blocks[1]->xpos; //x1 = 0
			blocks[1]->ypos -=  B_SIZE * 2; //y1 = 0
			blocks[2]->xpos += B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos -= B_SIZE; //y2 = 0
			blocks[3]->xpos += B_SIZE; //x3 =  B_SIZE * 2
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			break;
		case R2:
			blocks[1]->xpos +=  B_SIZE * 2; //x1 =  B_SIZE * 2
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos += B_SIZE; //x2 =  B_SIZE * 2
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos -= B_SIZE; //x3 = B_SIZE
			blocks[3]->ypos += B_SIZE; //y3 =  B_SIZE * 2
			break;
		case R3:
			blocks[1]->xpos; //x1 =  B_SIZE * 2
			blocks[1]->ypos +=  B_SIZE * 2; //y1 =  B_SIZE * 2
			blocks[2]->xpos -= B_SIZE; //x2 = B_SIZE
			blocks[2]->ypos += B_SIZE; //y2 =  B_SIZE * 2
			blocks[3]->xpos -= B_SIZE; //x3 = 0
			blocks[3]->ypos -= B_SIZE; //y3 = B_SIZE
			break;
		case R4:
			blocks[1]->xpos -=  B_SIZE * 2; //x1 = 0
			blocks[1]->ypos; //y1 =  B_SIZE * 2
			blocks[2]->xpos -= B_SIZE; //x2 = 0
			blocks[2]->ypos -= B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos += B_SIZE; //x3 = B_SIZE
			blocks[3]->ypos -= B_SIZE; //y3 = 0
			break;
		}
		break;
	case OSHAPE:
		switch (mode) {
		case NON:
			blocks[0]->xpos; //x0 = 0
			blocks[0]->ypos; //y0 = 0
			blocks[1]->xpos += B_SIZE; //x1 = B_SIZE
			blocks[1]->ypos; //y1 = 0
			blocks[2]->xpos; //x2 = 0
			blocks[2]->ypos += B_SIZE; //y2 = B_SIZE
			blocks[3]->xpos += B_SIZE; //x3 = B_SIZE
			blocks[3]->ypos += B_SIZE; //y3 = B_SIZE
			mode = R1;
			break;
		default:
			break;
		}
	}
	Move(1);
	while (isTouchLeft()) {
		Move(1);
	}
	Move(-1);
	Move(-1);
	while (isTouchRight()) {
		Move(-1);
	}
	Move(1);
}
