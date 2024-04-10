#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
using namespace sf;
void Menu(RenderWindow& window, Music& music_menu) {
	music_menu.play();
	music_menu.setLoop(true);
	Image text_play;
	Image text_exit;
	text_play.loadFromFile("Play_white.png");
	text_exit.loadFromFile("Exit_white.png");
	text_play.createMaskFromColor(Color(255, 255, 255));
	text_exit.createMaskFromColor(Color(255, 255, 255));
	Texture texture_play;
	Texture texture_exit;
	Texture texture_background;
	texture_play.loadFromImage(text_play);
	texture_exit.loadFromImage(text_exit);
	texture_background.loadFromFile("Menu.png");
	Sprite play(texture_play);
	Sprite exit(texture_exit);
	Sprite background(texture_background);

	bool in_menu = true;
	int menu_num = 0;
	play.setPosition(300, 600);
	exit.setPosition(300, 700);
	background.setPosition(0, 0);
	while (in_menu)
	{
		play.setColor(Color::Black);
		exit.setColor(Color::Black);
		menu_num = 0;

		if (IntRect(300, 600, 270, 100).contains(Mouse::getPosition(window))){
			
			play.setColor(Color::Blue);
			menu_num = 1;
		}
		if (IntRect(300, 700, 270, 100).contains(Mouse::getPosition(window))) {
			exit.setColor(Color::Blue);
			menu_num = 2;
		}
		if(Mouse::isButtonPressed(Mouse::Left))
		{
			if (menu_num == 1) {
				sound_button.play();
				music_menu.stop();
				in_menu = false;
			}
			else if (menu_num == 2) {
				sound_button.play();
				music_menu.stop();
				window.close();
				in_menu = false;
			}
		}
		window.draw(background);
		window.draw(play);
		window.draw(exit);
		window.display();
	}
}