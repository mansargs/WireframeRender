#pragma once

#include <vector>
#include <string>

using gridContent = std::vector<std::vector<std::string>>;

struct Vec3
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

struct Rgba
{
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 0.0f;
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
	public:
		Lge();
		int		parseFile(const std::string &filename);
		size_t	getWidth() const;
		size_t	getHeight() const;
};

