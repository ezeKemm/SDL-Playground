#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h> 

#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

int main(int argc, char* argv[]) {
	printf("hello world\n");

	// check for ability to init SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init: %s\n", SDL_GetError());
	}
	
	// Init window
	SDL_Window *win = SDL_CreateWindow("Hello SDL2!", 100, 100, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);

	// Error handle window creation
	if (win == NULL) {
		printf("SDL Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;  // Program exited unsuccessfully // Error
	}

	// Init renderer
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// Error handle renderer creation
	if (ren == NULL) {
		SDL_DestroyWindow(win);
		printf("SDL Renderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	// Simple Event Loop
	SDL_SetRenderDrawColor(ren, 40, 40, 60, 255); // Set background
	SDL_RenderClear(ren);  // Clear screen

	bool quit = false;  // Conditional flag for loop
	SDL_Event event;  // store a window event 
	while (!quit) {
		// Poll for an event -> we pass the event variable to store the event if it returns true
		while(SDL_PollEvent(&event)) {
			// If window is closed or escape key press :: Exit event loop, close program
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
				}
			}
		}
		SDL_RenderPresent(ren);  // Render scene
	}

	// Finalize program end
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;  // Program exited successfully
}
