#include "Shape.h"

Shape::Shape(SDL_Renderer* ren, int xPos, int yPos, Type type)
{
	switch (type) {
	case LSHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos + 64, 255, 150, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 255, 150, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos + 64, 255, 150, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos, 255, 150, 0));
		break;
	case JSHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos, 0, 0, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos + 64, 0, 0, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 0, 0, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos + 64, 0, 0, 255));
		break;
	case OSHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos, 255, 255, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 255, 255, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos, 255, 255, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos + 64, 255, 255, 0));
		break;
	case ISHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos + 64, 0, 200, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 0, 200, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos + 64, 0, 200, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 192, yPos + 64, 0, 200, 255));
		break;
	case SSHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos, 0, 255, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos, 0, 255, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos + 64, 0, 255, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 0, 255, 0));
		break;
	case TSHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos, 255, 0, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 255, 0, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos + 64, 255, 0, 255));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos + 64, 255, 0, 255));
		break;
	case ZSHAPE:
		blocks.push_back(new GameObject("assets/block.png", ren, xPos, yPos, 255, 0, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos, 255, 0, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 64, yPos + 64, 255, 0, 0));
		blocks.push_back(new GameObject("assets/block.png", ren, xPos + 128, yPos + 64, 255, 0, 0));
		break;

	default:
		break;
	}

	for (auto block : blocks) {
		
	}
}

Shape::~Shape()
{
}

void Shape::Update()
{
	for (auto block : blocks) {
		block->Update();
	}
}

void Shape::Render()
{
	for (auto block : blocks) {
		block->Render();
	}
}
