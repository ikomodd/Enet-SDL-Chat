#pragma once

#include <iostream>
#include <vector>

#include <SDL3/SDL.h>

#include "utilityes.hpp"

//

enum class anchor_point {

	TOP_LEFT,
	CENTER_LEFT,
	BOTTON_LEFT,

	TOP_CENTER,
	CENTER,
	BOTTON_CENTER,

	TOP_RIGHT,
	CENTER_RIGHT,
	BOTTON_RIGHT

};

//

class group_element; // Pré-declaração da classe

//

class ui_element {
public:

	group_element* Parent = nullptr;

	ui_element() {};
	virtual ~ui_element() {};

	virtual void _Ready() {};
	virtual void _Process() {};

};

class frame_element : public ui_element {
public:

	std::string Name = "No Name UI";

	vector2 GlobalPosition = {};
	vector2 GlobalScale = {};

	vector2 Position = {};
	vector2 Scale = {};

	anchor_point AnchorPoint = anchor_point::TOP_LEFT;

	color3 BackgroundColor = {150, 150, 150};
	color3 BorderColor = {0, 0, 0};

	float Opacity = 1.0f;

	frame_element(std::string name = "UiElement", vector2 position = {}, vector2 scale = {}, anchor_point anchor = anchor_point::TOP_LEFT) : Name(name), Position(position), Scale(scale), AnchorPoint(anchor) {}

	void Render();

};

class group_element : public frame_element {
public:

	std::vector<ui_element*> Childs;

	group_element(std::string name = "UiElement", vector2 position = {}, vector2 scale = {}, anchor_point anchor = anchor_point::TOP_LEFT): frame_element(name, position, scale, anchor) {}

	void AddChild(ui_element* element);
};