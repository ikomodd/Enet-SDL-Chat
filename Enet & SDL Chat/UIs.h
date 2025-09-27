#pragma once

#include <iostream>

#include <SDL3/SDL.h>

#include "utilityes.hpp"

class ui {

	std::string Name = "No Name UI";

	vector2 Position = {};
	vector2 Scale = {};

	color3 Color = {};

	float Opacity = 1.0f;
	
	ui(std::string name, vector2 position, vector2 scale): Name(name), Position(position), Scale(scale) {}
};