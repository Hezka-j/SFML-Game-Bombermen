#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

const int height_map = 15;//константная переменная для высоты
const int width_map = 25;//константная переменная для ширины
String main_map[height_map] = {
"0000000000000000000000000",
"0ss                     0",
"0s                      0",
"0                       0",
"0                       0",
"0                       0",
"0                       0",
"0                       0",
"0                       0",
"0                       0",
"0                       0",//0 - белая стена
"0                       0",//w - кирпичная стена
"0                      s0",//s - место где появляется перс или где должен уходить
"0                     sl0",// l - люк 
"0000000000000000000000000" };//сфмл класс и идентификация переменной

void GenerateMap()
{
	int rand_y = 0;
	int rand_x = 0;
	int random_number = 0;
	for (int i = 0; i < height_map; i++)
	{
		for (int j = 0; j < width_map; j++)
		{
			rand_y = 1 + rand() % (height_map - 1);
			rand_x = 1 + rand() % (width_map - 1);
			random_number = rand() % 2;
			if (main_map[rand_y][rand_x] != '0' && main_map[rand_y][rand_x] != 'l' && main_map[rand_y][rand_x] != 's')
			{
				if (random_number == 0)
					main_map[rand_y][rand_x] = 'w';
			}
		}
	}
}

void DrawMap(RenderWindow& window, Sprite& map_sprite) {
    for (int i = 0; i < height_map; i++)//цикл for для рисовки карты
    {
        for (int j = 0; j < width_map; j++)
        {
            if (main_map[i][j] == '0')//если main_map[i][j] == '0' то это стена
                map_sprite.setTextureRect(IntRect(64, 0, 32, 32));
            else if (main_map[i][j] == ' ' || main_map[i][j] == 's')//иначе если main_map[i][j] == ' ' то это просто поле
                map_sprite.setTextureRect(IntRect(0, 0, 32, 32));
            else if (main_map[i][j] == 'w')
                map_sprite.setTextureRect(IntRect(32, 0, 32, 32));
            else if (main_map[i][j] == 'l')
                map_sprite.setTextureRect(IntRect(128, 0, 32, 32));
            else if (main_map[i][j] == 'h')
                map_sprite.setTextureRect(IntRect(96, 0, 32, 32));
            else if (main_map[i][j] == 'b')
                map_sprite.setTextureRect(IntRect(0, 32, 32, 32));
            else if (main_map[i][j] == 'c')
                map_sprite.setTextureRect(IntRect(32, 32, 32, 32));
            else if(main_map[i][j] == 'k')   
                map_sprite.setTextureRect(IntRect(96, 32, 32, 32));
            map_sprite.setPosition(j * 32 + 100, i * 32 + 130);//устанавливаем спрайт на позицию в окне
            window.draw(map_sprite);//отрисовываем спрайт для карты
        }
    }
}
