#pragma once

#include <vector>

struct Vec3
{
	float x;
	float y;
	float z;
};

struct Rgba
{
	float r;
	float g;
	float b;
	float a;
};

struct Pixel
{
	Vec3 position;
	Rgba color;
};

class Map
{
	std::vector<std::vector<Pixel>> mapContent;
};

