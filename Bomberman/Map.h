#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

const int height_map = 15;//����������� ���������� ��� ������
const int width_map = 25;//����������� ���������� ��� ������
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
"0                       0",//0 - ����� �����
"0                       0",//w - ��������� �����
"0                      s0",//s - ����� ��� ���������� ���� ��� ��� ������ �������
"0                     sl0",// l - ��� 
"0000000000000000000000000" };//���� ����� � ������������� ����������

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
    for (int i = 0; i < height_map; i++)//���� for ��� ������� �����
    {
        for (int j = 0; j < width_map; j++)
        {
            if (main_map[i][j] == '0')//���� main_map[i][j] == '0' �� ��� �����
                map_sprite.setTextureRect(IntRect(64, 0, 32, 32));
            else if (main_map[i][j] == ' ' || main_map[i][j] == 's')//����� ���� main_map[i][j] == ' ' �� ��� ������ ����
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
            map_sprite.setPosition(j * 32 + 100, i * 32 + 130);//������������� ������ �� ������� � ����
            window.draw(map_sprite);//������������ ������ ��� �����
        }
    }
}
