#pragma once

#include <SDL2/SDL.h>

class Desktop
{
	private:
		unsigned int	desktopWidth;
		unsigned int	desktopHeight;
		bool			running;
		SDL_Window*		window;
	private:
		void	setDesktopData();
	public:
		Desktop();
		~Desktop();
		void setDesktopWidth();
};
