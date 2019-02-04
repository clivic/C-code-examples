#include <SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include <iostream>

using namespace sf;
using std::cout;
using std::endl;

Event event;

int main()
{
	static_cast<int>(2.0f);
	RenderWindow window(VideoMode(800, 600), "SFML works!", Style::Close | Style::Titlebar);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	Color* p_backgroundColor = NULL;

	// Load SG image
	Texture txd_sg;
	if (!txd_sg.loadFromFile("Textures/txd_sg.gif")) {
		cout << "Loading texture failed." << endl;
	}
	txd_sg.setSmooth(true);
	RectangleShape recimg_sg;
	recimg_sg.setOrigin(250, 150);
	recimg_sg.setPosition(300, 200);
	recimg_sg.setSize(Vector2f(1000,600));
	
	//recimg_sg.setFillColor(Color(0x00FF00FF));
	recimg_sg.setTexture(&txd_sg);

	// Load font
	Font fnt_beon;
	if (!fnt_beon.loadFromFile("Fonts/Beon.otf")) {
		cout << "Loading font failed." << endl;
	}
	Text txt_sg;
	txt_sg.setFillColor(Color::White);
	txt_sg.setFont(fnt_beon);
	txt_sg.setString("Supergirl rules!");
	txt_sg.setCharacterSize(50);
	txt_sg.setStyle(Text::Italic);

	// Load bgm
	/*SoundBuffer wav_bgm;
	if (!wav_bgm.loadFromFile("Audio/bgm.wav")) {
		cout << "Loading audio failed." << endl;
	}
	Sound ado_bgm(wav_bgm);
	ado_bgm.setVolume(40);
	ado_bgm.setPitch(.9f);
	ado_bgm.setLoop(true);
	ado_bgm.play();*/
	Music musc_bgm;
	if (!musc_bgm.openFromFile("Audio/bgm.wav")) {
		cout << "Loading audio failed." << endl;
	};
	musc_bgm.setVolume(40);
	musc_bgm.setPitch(.9f);
	musc_bgm.setLoop(true);
	musc_bgm.play();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::KeyPressed:
				if (event.key.code == Keyboard::Up)
					cout << "Up key pressed. ";
				if (event.key.alt)
					cout << "Alt pressed. ";
				if (event.key.control)
					cout << "Ctrl pressed. ";
				if (event.key.shift)
					cout << "Shift pressed. ";
				if (event.key.code == Keyboard::C)
				{
					p_backgroundColor = &Color(0x40, 0x40, 0x40);
				}
				if (event.key.code == Keyboard::Escape)
				{
					window.close(); return 0;
				}
				cout << endl;
				break;
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
					cout << "Left mouse button pressed. ";
				cout << "(" << event.mouseMove.x << ',' << event.mouseMove.y << ")";
				cout << endl;
				break;
			default:
				break;
			}
		}

		recimg_sg.move(0.1f, 0.1f);
		//recimg_sg.rotate(0.1);

		if (p_backgroundColor != NULL)
			window.clear(*p_backgroundColor);
		window.clear();
		//window.draw(shape);
		window.draw(recimg_sg);
		window.draw(txt_sg);
		window.display();
	}

	return 0;
}