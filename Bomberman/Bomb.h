#pragma once
#include"Player.h"
//#include<SFML/Audio.hpp>

using namespace std;
using namespace sf;
class Bomb {
    Image image;
    Sprite sprite;
    string file;
    Texture texture;
    Clock timer;
    int x;
    int y;
public:
    Bomb(std::string file);

    Bomb();
    
    /// <summary>
    /// ������ ��� �������
    /// ������������� ������ �� �����-�� ��������
    /// </summary>
    /// <param name="texture">�������� ���������</param>
    void SetSprite(Texture& texture);

    void SetY(int y);

    int GetY() const;

    void SetX(int x);

    int GetX() const;

    /// <summary>
    /// ������ ��� �������
    /// </summary>
    /// <returns>���������� �������� �������</returns>
    Sprite& GetSprite();

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
    void SetFile(string file);

    /// <summary>
    /// ������ ��� ���������� ����
    /// </summary>
    /// <returns>����</returns>
    std::string GetFile() const;

    void PlantBomb(Player& player, int x, int y, String* main_map);

    void Explosion(Player& player, Sound& sound_bomb2, Sound& sound_damage, String* main_map, int height_map, int width_map);

    void Prise(Player& player, Sound& sound_bomb2, Sound& sound_explosion, Sound& sound_damage, String* main_map, int height_map, int width_map);

    void Damage(Player& player, Sound& sound_damage);
    
};

