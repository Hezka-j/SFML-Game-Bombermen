#include"Game.h"
int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Bomberman!"/*, Style::Fullscreen*/);// редактируем окно сфмл
	StartGame(window);
}
