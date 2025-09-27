#include "ClientApp.h"

app::app() {

	SDL_CreateWindowAndRenderer("SDL & Enet Chat", 800, 600, SDL_WINDOW_RESIZABLE, &Window, &Renderer);

	FrameDelay = 1000 / MaxFPS;

}

void app::Run() {

	SDL_SetRenderDrawColor(App.Renderer, 255, 255, 255, 255);
	SDL_RenderClear(App.Renderer);

	Render();

	SDL_RenderPresent(App.Renderer);

}

void app::Render() {



}