#include <iostream>

#include <SDL3/SDL.h>

class app {
public:

	bool Running = true;

	SDL_Window* Window = nullptr;
	SDL_Renderer* Renderer = nullptr;

	SDL_Event Event;

	int FPS;

	int MaxFPS = 60;

	int FrameCount = 0;
	int FrameDelay = 0;
	Uint64 FPSTimer = 0;

	app();

	void Run();

	void Render();

};

extern app App;