#include "../hdrs/Map.hpp"
#include <fstream>
#include <iostream>
#include <cctype>
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

bool	Lge::validNumber(const std::string &strNumber)
{
	if (strNumber.empty())
		return false;
	if (strNumber.length() == 1 && strNumber[0] == '0')
		return true;
	if (strNumber[0] == '0')
		return false;
	if (strNumber.length() > 4)
		return false;
	for (const auto &c : strNumber)
	{
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return false;
	}
	return true;
}

bool	Lge::validColor(const std::string &strColor)
{
	size_t i = 1;

	if (strColor.empty())
		return true;
	if (strColor.length() != 5 && strColor.length() != 6
		&& strColor.length() != 8 && strColor.length() != 10)
		return false;
	if (strColor[i] != '#')
		return false;
	++i;
	for (; i < strColor.length(); ++i)
	{
		if (!std::isxdigit(static_cast<unsigned char>(strColor[i])))
			return false;
	}
	return true;
}

// int	Lge::convertToPixels(const gridContent &mapContent)
// {
// 	mapPixels.resize(height);
// 	for (auto &row : mapPixels)
// 	row.resize(width);

// 	for (size_t i = 0; i < height; ++i)
// 	{
// 		for (size_t j = 0; j < height; ++j)
// 		{
// 			std::string zAxis, color;
// 			size_t found = mapContent[i][j].find(',');
// 			if (found == std::string::npos)
// 				zAxis = mapContent[i][j];
// 			else
// 			{
// 				zAxis = mapContent[i][j].substr(0, found);
// 				color = mapContent[i][j].substr(found);
// 			}
// 			if (!validNumber(zAxis))
// 				return -1;
// 			if (!validColor(color))
// 				return -1;
// 			fillToCell(mapPixels[i][j], zAxis, color);
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
