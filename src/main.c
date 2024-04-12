#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h> 

#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_keycode.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_video.h"

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

// Declarations
bool init();  // Initialize SDL and open window
bool loadMedia();  // Load media
void closeSDL();  // Shut down SDL

// WARN: Avoid global variables // this tutorial's design choices are questionable

// Initializing these variables at the start
SDL_Window* gWindow = NULL;  // The window
SDL_Surface* gScreenSurface = NULL;  // The surface contained by the window
SDL_Surface* gHelloWorld = NULL;  // The image to draw

bool init() {
	// check for ability to init SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init: %s\n", SDL_GetError());
		return 1;  // Program exited unsuccessfully // Error
	}
	
	// Init window
	gWindow = SDL_CreateWindow("Hello SDL2!", 100, 100, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);

	// Error handle window creation
	if (gWindow == NULL) {
		printf("SDL Error: %s\n", SDL_GetError());
		// SDL_Quit();
		return 1;
	}
	
	gScreenSurface = SDL_GetWindowSurface(gWindow);

	return 0;
}

bool loadMedia() {
	char* bmp = "assets/hello_world.bmp";  // Path to bitmap 
	gHelloWorld = SDL_LoadBMP(bmp);  // Load bitmap
	
	// Error handling
	if (gHelloWorld == NULL) {
		printf("Unable to load image %s! SDL ERROR: %s\n", bmp, SDL_GetError()); 
		return 1;
	}
	return 0;
}

void closeSDL() {
	SDL_FreeSurface(gHelloWorld);  // Destroy surface
	gHelloWorld = NULL;  // NOTE: Set to null pointers so we are memory safe
	SDL_DestroyWindow(gWindow);  // Destroy window
	gWindow = NULL;
	SDL_Quit();  // Quit SDL subsystems
}

int main(int argc, char* argv[]) {
	if (init()) {	
		printf("ERROR:: Failed to initialize!\n");
		closeSDL();
		return 1;
	}

	if (loadMedia()) {
		printf("ERROR:: Failed to load media!\n");
		closeSDL();
		return 1;
	}

	SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
	SDL_UpdateWindowSurface(gWindow);

	// Keeps window alive until closed
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
	}

	closeSDL(); // Free resources at end

	return 0;
}

int lesson1() {
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
