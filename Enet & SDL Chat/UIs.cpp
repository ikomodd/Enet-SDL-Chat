#include "UIs.h"

#include "ClientApp.h"

//

void frame_element::Render() {

	if (Parent != nullptr) GlobalScale = { Parent->GlobalScale.X * Scale.X, Parent->GlobalScale.Y * Scale.Y };
	else GlobalScale = { App.WindowSize.X * Scale.X, App.WindowSize.Y * Scale.Y };

	vector2 PositionAnchor = {};

	if (Parent != nullptr) {
		switch (AnchorPoint) {

		case anchor_point::TOP_LEFT:

			PositionAnchor = { 0, 0 };

			break;
		case anchor_point::CENTER_LEFT:



			break;
		case anchor_point::BOTTON_LEFT:



			break;
		case anchor_point::TOP_CENTER:

			PositionAnchor = { (Parent->GlobalScale.X / 2) - (GlobalScale.X / 2), 0 };

			break;
		case anchor_point::CENTER:

			PositionAnchor = { (Parent->GlobalScale.X / 2) - (GlobalScale.X / 2), (Parent->GlobalScale.Y / 2) - (GlobalScale.Y / 2) };

			break;
		case anchor_point::BOTTON_CENTER:



			break;
		case anchor_point::TOP_RIGHT:



			break;
		case anchor_point::CENTER_RIGHT:



			break;
		case anchor_point::BOTTON_RIGHT:



			break;
		}
	}

	if (Parent != nullptr) GlobalPosition = {

		PositionAnchor.X + Parent->GlobalPosition.X + (Parent->GlobalScale.X * Position.X),
		PositionAnchor.Y + Parent->GlobalPosition.Y + (Parent->GlobalScale.Y * Position.Y)

	};

	//std::cout << Name << ": " << GlobalPosition.X << " " << GlobalPosition.Y << " " << GlobalScale.X << " " << GlobalScale.Y << "\n";

	//

	SDL_FRect ElementRect = { GlobalPosition.X + Position.X, GlobalPosition.Y + Position.Y, GlobalScale.X, GlobalScale.Y };

	SDL_SetRenderDrawColor(App.Renderer, BackgroundColor.R, BackgroundColor.G, BackgroundColor.B, 255);
	SDL_RenderFillRect(App.Renderer, &ElementRect);

	SDL_SetRenderDrawColor(App.Renderer, BorderColor.R, BorderColor.G, BorderColor.B, 255);
	SDL_RenderRect(App.Renderer, &ElementRect);

}

//

void group_element::AddChild(ui_element* Element) {

	Childs.push_back(Element);

	Element->Parent = this;
}