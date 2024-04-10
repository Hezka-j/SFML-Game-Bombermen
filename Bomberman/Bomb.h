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
    /// Сеттер для спрайта
    /// Устанавливает спрайт на какую-то текстуру
    /// </summary>
    /// <param name="texture">Текстура персонажа</param>
    void SetSprite(Texture& texture);

    void SetY(int y);

    int GetY() const;

    void SetX(int x);

    int GetX() const;

    /// <summary>
    /// Геттер для спрайта
    /// </summary>
    /// <returns>Возвращает оригинал спрайта</returns>
    Sprite& GetSprite();

    /// <summary>
   /// Сеттер для текстуры
   /// </summary>
   /// <param name="image">Изображение с которого берём текстуру</param>
    void SetTexture(Image& image);

    /// <summary>
    /// Геттер для текстуры
    /// </summary>
    /// <returns>Возвращает текстуру для обьекта</returns>
    Texture& GetTexture();

    /// <summary>
    /// Сеттер для image
    /// Устанавливает файл для нашей переменной image
    /// </summary>
    /// <param name="file">Файл который будет передан image</param>
    void SetImage(string filename);

    /// <summary>
    /// Геттер для image
    /// </summary>
    /// <returns>Возвращает оригинал image</returns>
    Image& GetImage();
    /// <summary>
    /// Сеттер для файла
    /// </summary>
    /// <param name="file">Файл который передаёт пользователь</param>
    void SetFile(string file);

    /// <summary>
    /// Геттер для переменной файл
    /// </summary>
    /// <returns>Файл</returns>
    std::string GetFile() const;

    void PlantBomb(Player& player, int x, int y, String* main_map);

    void Explosion(Player& player, Sound& sound_bomb2, Sound& sound_damage, String* main_map, int height_map, int width_map);

    void Prise(Player& player, Sound& sound_bomb2, Sound& sound_explosion, Sound& sound_damage, String* main_map, int height_map, int width_map);

    void Damage(Player& player, Sound& sound_damage);
    
};

