#pragma once

#include <iostream>

struct vector2 {

	float X = 0;
	float Y = 0;

	vector2(float x = 0, float y = 0): Y(y), X(x) {};
};

struct ivector2 {

	int X = 0;
	int Y = 0;

	ivector2(int x = 0, int y = 0) : Y(y), X(x) {};
};

struct color3 {

	Uint8 R = 255;
	Uint8 G = 255;
	Uint8 B = 255;

	color3(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255): R(r), G(g), B(b) {}

};