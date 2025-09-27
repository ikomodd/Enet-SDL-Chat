#include <iostream>

struct vector2 {

	float X = 0;
	float Y = 0;

	vector2(float x = 0, float y = 0) {};
};

struct color3 {

	Uint8 R = 255;
	Uint8 G = 255;
	Uint8 B = 255;

	color3(Uint8 r = 255, Uint8 g = 255, Uint8 b = 255): R(r), G(g), B(b) {}

};