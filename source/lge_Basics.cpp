#include "../hdrs/Lge.hpp"
#include <fstream>
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>

size_t	Lge::getWidth() const { return width;}

size_t	Lge::getHeight() const { return height;}

Lge::Lge() : width(0), height(0) {}

// void	Lge::printMap(const gridContent &mapContent) const
// {
// 	for (const auto &row : mapContent)
// 	{
// 		for (const auto &cell : row)
// 		{
// 			std::cout << std::setw(2) << cell << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// 	std::cout << "Map Width: " << width << ", Height: " << height << std::endl;
// }


