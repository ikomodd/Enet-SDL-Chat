#include <iostream>
#include <thread>

#include <enet/enet.h>
#include <SDL3/SDL.h>

#include "ClientApp.h"
#include "ClientConnection.hpp"
#include "ClientNetwork.hpp"

app App;

client_connection Connection;

int main() {

	if (enet_initialize() != 0) return EXIT_FAILURE;
	atexit(enet_deinitialize);

	Connection.Init();

	std::thread NetworkThread(Network);

	//

	SDL_Init(SDL_INIT_VIDEO);

	int FrameTime;

	while (App.Running) {

		int FrameStart = SDL_GetTicks();
		App.FrameCount++;

		while (SDL_PollEvent(&App.Event)) {

			if (App.Event.type == SDL_EVENT_QUIT) App.Running = false;

		}

		App.Run();

		if (SDL_GetTicks() - App.FPSTimer > 1000) {

			App.FPS = App.FrameCount;
			App.FrameCount = 0;

			App.FPSTimer = SDL_GetTicks();

		}

		FrameTime = SDL_GetTicks() - FrameStart;

		int TimeDelay = App.FrameDelay - FrameTime;

		if (TimeDelay > 0) SDL_Delay(TimeDelay);

	}

	SDL_DestroyWindow(App.Window);
	SDL_DestroyRenderer(App.Renderer);

	enet_peer_disconnect(Connection.Peer, 0);

	NetworkThread.join();

	enet_host_destroy(Connection.Client);

	return 1;
}