// Test2.cpp : Defines the entry point for the console application.
//
#include <SFML\Graphics.hpp>
#include "stdafx.h"
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(0200, 0200), "SFML works.");
	/*CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;*/
}

