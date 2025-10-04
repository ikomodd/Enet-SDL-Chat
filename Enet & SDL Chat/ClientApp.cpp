#include "ClientApp.h"

app App;

//

app::app() {

	SDL_CreateWindowAndRenderer("SDL & Enet Chat", 800, 600, SDL_WINDOW_RESIZABLE, &Window, &Renderer);

	FrameDelay = 1000 / MaxFPS;

}

void app::Run() {

	SDL_GetWindowSize(Window, &WindowSize.X, &WindowSize.Y);

	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderClear(Renderer);

	Render();

	SDL_RenderPresent(Renderer);

}

void GetAllChildrens(std::vector<ui_element*> &LinearVector, group_element* Parent) {

	for (auto Element : Parent->Childs) {

		LinearVector.push_back(Element);
		
		if (group_element* GroupParent = dynamic_cast<group_element*>(Element)) GetAllChildrens(LinearVector, GroupParent);
	}
}

void app::Render() {

	std::vector<ui_element*> LinearGUI = {};

	GetAllChildrens(LinearGUI, Gui);

	//std::cout << "Size: " << LinearGUI.size() << "\n";

	Gui->Render();

	for (ui_element* Ui : LinearGUI) {

		if (frame_element* Frame = dynamic_cast<frame_element*>(Ui)) {

			Frame->Render();
			
		}
	}
}