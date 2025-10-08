#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include "../hdrs/Map.hpp"


bool	verifyFile(const std::string &filename)
{
	std::filesystem::path filePath = "./" + filename;
	if (!std::filesystem::exists(filePath))
	{
		std::cerr << "\033[31mError: File doesn't exist\033[0m\n";
		return false;
	}
	if (filePath.extension() != ".lge")
	{
		std::cerr << "\033[31mError: Extension is not lge\033[0m\n";
		return false;
	}
	std::ifstream file(filePath);
	if (!file.is_open())
	{
		std::cerr << "\033[31mError: File cannot open file\033[0m\n";
		return false;
	}
	file.close();
	return true;
}

int	main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "\033[31mProgram must have one argument with the .lge extension!\033[0m\n";
		return EXIT_FAILURE;
	}
	if (!verifyFile(std::string(argv[1])))
		return EXIT_FAILURE;
	Lge engine;
	if (engine.parseFile(std::string(argv[1])) != 0)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}
