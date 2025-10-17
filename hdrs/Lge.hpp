#pragma once

#include <vector>
#include <string>

using gridContent = std::vector<std::vector<std::string>>;

struct Vec3
{
	float x;
	float y;
	float z = 0.0f;
};

struct Rgba
{
	float r = 255.0f;
	float g = 255.0f;
	float b = 255.0f;
	float a = 1.0f;
};

struct Pixel
{
	Vec3 position;
	Rgba color;
};

class Lge
{
	using gridPixels = std::vector<std::vector<Pixel>>;
	private:
		size_t		width;
		size_t		height;
		gridPixels	mapPixels;
	private:
		int			parseLine(const std::string &line, gridContent &mapContent);
		int			convertToPixels(const gridContent &mapContent);
		void		printMap(const gridContent &mapContent) const;
		static bool	validColor(const std::string &strColor);
		static bool	validNumber(const std::string &strNumber);
		void		cellColor(Pixel &cell, const std::string &zAxis, const std::string &color);
	public:
		Lge();
		int		parseFile(const std::string &filename);
		size_t	getWidth() const;
		size_t	getHeight() const;
		static bool	verifyFile(const std::string &filename);
};

