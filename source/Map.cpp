#include "../hdrs/Map.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

size_t	Lge::getWidth() const {	return width;}

size_t	Lge::getHeight() const {	return height;}

Lge::Lge() : width(0), height(0) {}

void	Lge::printMap(const gridContent &mapContent) const
{
	for (const auto &row : mapContent)
	{
		for (const auto &cell : row)
		{
			std::cout << std::setw(2) << cell << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Map Width: " << width << ", Height: " << height << std::endl;
}

int Lge::parseLine(const std::string &line, gridContent &mapContent)
{
	std::istringstream			lineStream(line);
	std::string					cell;
	size_t						widthEach = 0;
	std::vector<std::string>	row;

	while (lineStream >> cell)
	{
		row.push_back(cell);
		++widthEach;
	}
	if (!lineStream.eof())
	{
		std::cerr << "Error reading line\n";
		return -1;
	}
	mapContent.push_back(row);
	++height;
	if (widthEach > width)
		width = widthEach;
	return 0;
}

// int	Lge::convertToPixels(const gridContent &mapContent)
// {
// 	mapPixels.reserve(height);
// 	for (auto &row : mapPixels)
// 	row.reserve(width);

// 	for (const auto & row : mapContent)
// 	{
// 		for (const auto & cell : row)
// 		{
// 			std::string zAxis, color;
// 			size_t found = cell.find(',');
// 			if (found == std::string::npos)
// 				zAxis = cell;
// 			else
// 			{
// 				zAxis = cell.substr(0, found);
// 				color = cell.substr(found);
// 			}

// 		}
// 	}

// }

int	Lge::parseFile(const std::string &filename)
{
	std::ifstream	file(filename);
	std::string		line;
	gridContent		mapContent;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (parseLine(line, mapContent) != 0)
				return -1;
		}
		if (!file.eof())
		{
			std::cerr << "Error reading file\n";
			return -1;
		}
	}
	else
	{
		std::cerr << "Error opening file\n";
		return -1;
	}
	// convertToPixels(mapContent);
	printMap(mapContent);
	return 0;
};
