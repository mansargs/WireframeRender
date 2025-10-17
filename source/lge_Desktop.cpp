#include "../hdrs/Desktop.hpp"
#include <stdexcept>

void Desktop::setDesktopData()
{
	SDL_DisplayMode dm;
	if (SDL_GetCurrentDisplayMode(0, &dm) != 0)
		return;
	desktopWidth = dm.w - 100;
	desktopHeight = dm.h - 100;
};
Desktop::Desktop() : desktopWidth(1000), desktopHeight(800), running(false)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
		throw std::runtime_error(SDL_GetError());
	setDesktopData();
	window = SDL_CreateWindow("Line Engine",
						  SDL_WINDOWPOS_CENTERED,
						  SDL_WINDOWPOS_CENTERED,
						  desktopWidth - 100,
						  desktopHeight - 100,
						  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
		throw std::runtime_error(SDL_GetError());
}

Desktop::~Desktop()
{
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
}

