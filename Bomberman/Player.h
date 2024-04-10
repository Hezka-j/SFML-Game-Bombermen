#pragma once
#include<iostream>
#include<string>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Player {
    bool is_alive;
    int health;
    Texture texture;// ���������� ��� �������� �� ���������
    string file;// ���������� ��� �����
    Sprite sprite;// ���������� ��� ��������
    Image image;// ���������� ��� �����������
    float x;//���������� x
    float y;//���������� y
    float speed;//��������
    float dx;//�������� � ����� �������� ��� � �����-�� ����������� �� x
    float dy;//�������� � ����� �������� ��� � �����-�� ����������� �� y
    float height;// ������ ������ ���������
    float width;// ������ ������ ���������
    int direction;// �����������
    int health_score;
    int bomb_score;
    int key_score;
    Clock timer_step1;
    View view;//�������� ���������� ��� ������
public:
    /// <summary>
    /// ������� ����������� � 5 �����������
    /// </summary>
    /// <param name="file">���� � ����� ��� � �������� � ����������</param>
    /// <param name="x">���������� ��� �������� �������� �� x</param>
    /// <param name="y">���������� ��� �������� �������� �� y</param>
    /// <param name="width">������ ���������</param>
    /// <param name="height">������ ���������</param>
    Player(string filename, float x, float y, float width, float height);

    void SetHealthScore(int health_score);

    int GetHealthScore() const;

    void SetIsAlive(bool is_life);

    bool GetIsAlive() const;

    void SetBombScore(int bomb_score);

    int GetBombScore() const;

    void SetKeyScore(int key_score);

    int GetKeyScore() const;

    /// <summary>
    /// ������ ��� �����������
    /// </summary>
    /// <param name="direction">����������� ���� ��� ��������</param>
    void SetDirection(int direction);

    /// <summary>
    /// ������ ��� �����������
    /// </summary>
    /// <returns>���������� ����������� ���� ����� ��������</returns>
    int GetDirection() const;

    /// <summary>
    /// ������ ��� ��������
    /// ������������� �������� ������������ ���������
    /// </summary>
    /// <param name="speed">�������� � ������� ����� ������������ ��������</param>
    void SetSpeed(float speed);

    /// <summary>
    /// ������ ��� ��������
    /// </summary>
    /// <returns>���������� �������� ����������� ���������</returns>
    float GetSpeed() const;

    /// <summary>
    /// ������ ��� �������
    /// ������������� ������ �� �����-�� ��������
    /// </summary>
    /// <param name="texture">�������� ���������</param>
    void SetSprite(Texture& texture);

    /// <summary>
    /// ������ ��� �������
    /// </summary>
    /// <returns>���������� �������� �������</returns>
    Sprite& GetSprite();

    /// <summary>
    /// ������ ��� ������ ���������
    /// </summary>
    /// <param name="height">������ ���������</param>
    void SetHeight(float height);

    /// <summary>
    /// ������ ��� ������ ���������
    /// </summary>
    /// <returns>���������� ������ ���������</returns>
    float GetHeight() const;

    /// <summary>
    /// ������ ��� ������
    /// ������������� ������ ���������
    /// </summary>
    /// <param name="width">������ ���������</param>
    void SetWidth(float width);

    /// <summary>
    /// ������ ��� ������ ���������
    /// </summary>
    /// <returns>���������� ������ ���������</returns>
    float GetWidth() const;

    /// <summary>
    /// ������ ��� ���������� X
    /// ������������� ���������� X
    /// </summary>
    /// <param name="x">���������� X</param>
    void SetX(float x);

    /// <summary>
    /// ������ ��� ���������� X
    /// </summary>
    /// <returns>���������� ���������� X</returns>
    float GetX() const;

    /// <summary>
    /// ������ ��� ���������� Y
    /// ������������� ���������� Y
    /// </summary>
    /// <param name="y">���������� Y</param>
    void SetY(float y);

    /// <summary>
    /// ������ ��� ���������� Y
    /// </summary>
    /// <returns>���������� ���������� Y</returns>
    float GetY() const;

    /// <summary>
    /// ������ ��� �������� � ����������� ����������� �� X
    /// </summary>
    /// <param name="dx">����������� �� X � ������� �������� ���</param>
    void SetDx(float dx);

    /// <summary>
    /// ������ ��� �������� � ����������� ����������� �� X
    /// </summary>
    /// <returns>���������� �������� � ����������� �� X</returns> //-speed ��� �����
    float GetDx() const;

    /// <summary>
    /// ������ ��� �������� � ����������� ����������� �� Y
    /// </summary>
    /// <param name="dy">����������� �� Y � ������� �������� ���</param>
    void SetDy(float dy);

    /// <summary>
    /// ������ ��� �������� � ����������� ����������� �� Y
    /// </summary>
    /// <returns>���������� �������� d ����������� �� Y</returns>
    float GetDy() const;

    /// <summary>
    /// ������ ��� ��������
    /// </summary>
    /// <param name="image">����������� � �������� ���� ��������</param>
    void SetTexture(Image& image);

    /// <summary>
    /// ������ ��� ��������
    /// </summary>
    /// <returns>���������� �������� ��� �������</returns>
    Texture& GetTexture(); 

    /// <summary>
    /// ������ ��� image
    /// ������������� ���� ��� ����� ���������� image
    /// </summary>
    /// <param name="file">���� ������� ����� ������� image</param>
    void SetImage(string filename);

    /// <summary>
    /// ������ ��� image
    /// </summary>
    /// <returns>���������� �������� image</returns>
    Image& GetImage();

    /// <summary>
    /// ������ ��� �����
    /// </summary>
    /// <param name="file">���� ������� ������� ������������</param>
    void SetFile(string filename);

    /// <summary>
    /// ������ ��� ���������� ����
    /// </summary>
    /// <returns>����</returns>
    string GetFile() const;

    /// <summary>
    /// ��������� ������ ��������� ���������
    /// </summary>
    /// <param name="time">����� �� ���������� ����</param>
    void Move(float time, Sound& sound_walk1, Sound& sound_walk2, Sound& sound_heal, Sound& sound_collide, String* main_map, int height_map, int width_map);

    /// <summary>
    /// ��������� ������ ���������
    /// </summary>
    /// <param name="player">�����</param>
    /// <param name="current_frame">����</param>
    /// <param name="time">����� �� ���������� ����</param>
    void Animation(Player& player, float& current_frame, float& time, Sound& sound_walk1, Sound& sound_walk2);

   
    void InteractionWithMap(Sound& sound_heal, Sound& sound_collide, String* main_map, int height_map, int width_map);

    View ChangeView();

    View GetView() const;
};

