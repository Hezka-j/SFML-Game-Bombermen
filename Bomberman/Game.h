#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include"Sounds.h"
#include"Map.h"
#include"Mission.h"
#include"View.h"
#include"Menu.h"
#include"Bomb.h"
#include"Player.h"
using namespace std;
using namespace sf;

void StartGame(RenderWindow& window){
    srand(time(0));
    setlocale(0, "");
    Music music;
    Music music_menu;
    music_menu.openFromFile("����.ogg");
    music_menu.setVolume(10);
    music.openFromFile("����.ogg");
    music.setVolume(3);

    buffer_heal.loadFromFile("������������ ��.ogg");
    buffer_collide.loadFromFile("������������ �� �������.ogg");
    buffer_explosion.loadFromFile("�����.ogg");
    buffer_bomb2.loadFromFile("�� ���������������.ogg");
    buffer_tab.loadFromFile("��������� ������� �� ���.ogg");
    buffer_bomb.loadFromFile("��������� �����.ogg");
    buffer_walk2.loadFromFile("������2.ogg");
    buffer_walk1.loadFromFile("������1.ogg");
    buffer_victory.loadFromFile("������.ogg");
    buffer_defeat.loadFromFile("��������.ogg");
    buffer_damage.loadFromFile("����.ogg");
    buffer_button.loadFromFile("������.ogg");

    sound_button.setVolume(30);
    sound_damage.setVolume(30);
    sound_heal.setVolume(35);
    sound_victory.setVolume(30);
    sound_defeat.setVolume(30);
    sound_collide.setVolume(30);
    sound_walk2.setVolume(100);
    sound_explosion.setVolume(10);
    sound_bomb2.setVolume(50);
    sound_tab.setVolume(70);
    sound_bomb.setVolume(40);
    sound_walk1.setVolume(100);

    Clock clock;// ���� ����� Clock ��������� �������� � ��������
    Clock timer;
    Clock detonation;
    Menu(window, music_menu);
    music.play();
    music.setLoop(true);
    view.reset(FloatRect(0, 0, 1000, 700));//����������� ���� ������ ����
    Player player("hero2.0.png", 120, 130, 64, 64);//�������� ���������
    bool show_text = true;

    Image mission_image;
    mission_image.loadFromFile("D:\\�������\\Bomberman\\tablemissions.png");
    mission_image.createMaskFromColor(Color(255, 255, 255));
    mission_image.createMaskFromColor(Color(201, 201, 201));
    Texture mission_texture;
    mission_texture.loadFromImage(mission_image);
    Sprite mission_sprite(mission_texture);
    mission_sprite.setTextureRect(IntRect(0, 0, 89, 89));
    mission_sprite.setScale(4.f, 4.f);

    Image map_image;//�������� ���������� ��� �������� �����
    map_image.loadFromFile("D:\\�������\\Bomberman\\field.png");//��������� �������� ��� �����
    Texture texture_map;//�������� ����������� ��� �������� �����
    texture_map.loadFromImage(map_image);//�������� �������� ��� �����
    Sprite map_sprite;// �������� ������� ��� �����
    map_sprite.setTexture(texture_map);//������������� ������ �� ��������
    GenerateMap();

    Bomb bomb("bomb.png");

    Font font;
    font.loadFromFile("������\\signategrotesk-black.ttf");
    Text text_timer("", font, 32);
    text_timer.setFillColor(Color::White);
    Text text("", font, 32);
    text.setFillColor(Color::White);

    Text mission_text("", font, 30);
    mission_text.setFillColor(Color::Black);
    //text.setOutlineColor(Color::Red);
    //text.setStyle(Text::Bold);
    Image image_heart;
    image_heart.loadFromFile("D:\\�������\\Bomberman\\Heart.png");
    image_heart.createMaskFromColor(Color(255, 255, 255));
    //image_heart.createMaskFromColor(Color(0, 0, 0));
    Texture texture_heart;
    texture_heart.loadFromImage(image_heart);
    Sprite heart_sprite1(texture_heart);
    heart_sprite1.setPosition(70, 30);
    heart_sprite1.setScale(1.5, 1.5);
    Sprite heart_sprite2(texture_heart);
    heart_sprite2.setPosition(118, 30);
    heart_sprite2.setScale(1.5, 1.5);
    Sprite heart_sprite3(texture_heart);
    heart_sprite3.setPosition(166, 30);
    heart_sprite3.setScale(1.5, 1.5);

    Image image_bomb;
    image_bomb.loadFromFile("D:\\�������\\Bomberman\\bomb.png");
    image_bomb.createMaskFromColor(Color(255, 255, 255));
    Texture texture_bomb;
    texture_bomb.loadFromImage(image_bomb);
    Sprite bomb_sprite1(texture_bomb);
    bomb_sprite1.setPosition(310, 30);
    bomb_sprite1.setTextureRect(IntRect(0, 0, 32, 32));
    bomb_sprite1.setScale(1.5, 2);
    Sprite bomb_sprite2(texture_bomb);
    bomb_sprite2.setPosition(342, 30);
    bomb_sprite2.setScale(1.5, 2);
    bomb_sprite2.setTextureRect(IntRect(0, 0, 32, 32));
    Sprite bomb_sprite3(texture_bomb);
    bomb_sprite3.setPosition(374, 30);
    bomb_sprite3.setScale(1.5, 2);
    bomb_sprite3.setTextureRect(IntRect(0, 0, 32, 32));

    int count = 0;
    int timer_life = 0;
    float current_frame_bomb = 0;
    float current_frame = 0;// ������ ���������� ���� ��� ��������
    bool plant = false;
    bool defeat = true;
    Clock death;
    bool enter_death = false;
    while (window.isOpen())// ���� ���� ���� ���� �������
    {
        float time = clock.getElapsedTime().asMicroseconds();//������ ���������� ����� ������� ����� �������� ����� ���� � ���������� restart() � �������������
        clock.restart();
        float timer_detonation = detonation.getElapsedTime().asSeconds();
        float timer_death = detonation.getElapsedTime().asSeconds();
        //detonation.restart();
        if (player.GetIsAlive()) timer_life = timer.getElapsedTime().asSeconds();
        //cout << timer_life << " ";
        time = time / 800;//����� ����� �� 800 ����� �������� �������
        Event event;// ������ ���������� ������� ����� ��������� ��� �������
        while (window.pollEvent(event))// ���� ������� ������� ���������� � event(����� ������ ���������)
        {
            if (event.type == event.Closed)//���� ��� ������� ��� �������� ���� 
            {
                window.close();// ��������� ����               
            }
            if (event.type == event.KeyPressed)
            {
                if (event.key.code == Keyboard::Tab)
                {
                    switch (show_text)
                    {
                    case true:
                    {
                        sound_tab.play();
                        ostringstream mission;
                        mission << MissionText(GetMission(player.GetKeyScore()));
                        mission_text.setString(mission.str());
                        show_text = false;
                        break;
                    }
                    case false:
                    {
                        mission_text.setString(" ");
                        show_text = true;
                        break;
                    }
                    }
                }
                else if (event.key.code == Keyboard::Enter && !plant)
                {

                    if (player.GetBombScore() > 0 && main_map[int((player.GetY() - 130) / 32 + 1)][int((player.GetX() - 100) / 32 + 1)] != 'l' && main_map[int(((player.GetY() - 130) / 32 + 1) + 1)][int((player.GetX() - 100) / 32 + 1)] != 'l' && main_map[int((player.GetY() - 130) / 32 + 1)][int(((player.GetX() - 100) / 32 + 1) + 1)] != 'l')
                    {
                        /*detonation.restart();
                        timer_detonation = timer_detonation / 800;*/
                        //player.PlantBomb(bomb, player);
                        bomb.PlantBomb(player, player.GetX(), player.GetY(), main_map);
                        sound_bomb.play();
                        plant = true;
                        detonation.restart();
                        timer_detonation = detonation.getElapsedTime().asSeconds();
                        if (player.GetBombScore() == 0)
                            count++;
                    }
                    else
                    {
                        sound_bomb2.play();
                        //���� �� ���������� ����������
                    }
                }
                else if (event.key.code == Keyboard::Enter && plant)
                {
                    sound_bomb2.play();
                }

            }
        }
        //cout << player.GetX() << "X " << player.GetY() << "Y\n";           
        if (plant && timer_detonation >= 5)
        {
            bomb.Prise(player, sound_bomb2, sound_explosion, sound_damage, main_map, height_map, width_map);
            DrawMap(window, map_sprite);
            plant = false;
        }

        //cout << timer_death << " ";
        if (player.GetKeyScore() == 0 && int((player.GetY() - 130) / 32 + 1) == 13 && int((player.GetX() - 100) / 32 + 1) == 23 && defeat)
        {
            music.setVolume(1);
            player.SetIsAlive(false);
            sound_victory.play();       
        }

        if (player.GetHealthScore() == 0 && defeat)
        {
            sound_defeat.play();
            defeat = false;
            player.SetIsAlive(false);         
        }

        if (player.GetBombScore() == 0 && defeat) {
            //enter_death = true;
            if (player.GetBombScore() == 0 && count > 0)
            {
                death.restart();
                timer_death = death.getElapsedTime().asSeconds();
                count--;
            }
            if (timer_death >= 10 && player.GetBombScore() == 0) {
                defeat = false;
                player.SetIsAlive(false);
                player.SetHealthScore(0);
                sound_defeat.play();               
            }
        }
        player.Animation(player, current_frame, time, sound_walk1, sound_walk2);//�������� ��� ���������
        player.Move(time, sound_walk1, sound_walk2, sound_heal, sound_collide, main_map, height_map, width_map);//�������� ���������
        ChangeView();//����� ������� ���
        window.setView(view);//��������� ������
        window.clear(Color(95, 95, 95));// ������� ���� � �������� � �����
        DrawMap(window, map_sprite);
        window.draw(player.GetSprite());//������������ ������ ��� ���������
        if (!show_text) {
            mission_text.setPosition(view.getCenter().x + 145, view.getCenter().y - 130);
            mission_sprite.setPosition(view.getCenter().x + 115, view.getCenter().y - 150);
            window.draw(mission_sprite);
            window.draw(mission_text);
        }
        ostringstream game_timer;
        game_timer << timer_life;       
        text_timer.setString(game_timer.str());
        text_timer.setPosition(900, 30);
        if (player.GetBombScore() == 3)
        {
            window.draw(bomb_sprite1);
            window.draw(bomb_sprite2);
            window.draw(bomb_sprite3);
        }
        else if (player.GetBombScore() == 2)
        {
            window.draw(bomb_sprite1);
            window.draw(bomb_sprite2);
        }
        else if (player.GetBombScore() == 1)
        {
            window.draw(bomb_sprite1);
        }
        else
        {
        }
        if (player.GetHealthScore() == 3)
        {
            window.draw(heart_sprite1);
            window.draw(heart_sprite2);
            window.draw(heart_sprite3);
        }
        else if (player.GetHealthScore() == 2)
        {
            window.draw(heart_sprite1);
            window.draw(heart_sprite2);
        }
        else if (player.GetHealthScore() == 1)
        {
            window.draw(heart_sprite1);
        }
        else
        {
        }
        
        window.draw(text_timer);    
        window.display();//���������� �� �����
    }
   
}