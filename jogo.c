#include<SDL/SDL.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	SDL_INIT_EVERYTHING);
	SDL_Surface* screen;
	SDL Event event;

	int quit = 0;
	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(640, 480, 8, 0);

	while(!quit)
	{
		while(SDL_PollEvent(&event))
			if(event.type == SDL_QUIT)
				quit = 1;

		SDL_Flip(screen);
	}

	SDL_Quit();
	return 0;
}