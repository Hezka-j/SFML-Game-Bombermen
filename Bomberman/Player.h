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
    Texture texture;// переменная для текстуры на персонажа
    string file;// переменная для файла
    Sprite sprite;// переменная для спрайтов
    Image image;// переменная для изображений
    float x;//координата x
    float y;//координата y
    float speed;//скорость
    float dx;//скорость с какой персонаж идёт в какое-то направление по x
    float dy;//скорость с какой персонаж идёт в какое-то направление по y
    float height;// высота одного персонажа
    float width;// ширина одного персонажа
    int direction;// направление
    int health_score;
    int bomb_score;
    int key_score;
    Clock timer_step1;
    View view;//создание переменной для камеры
public:
    /// <summary>
    /// Главный конструктор с 5 параметрами
    /// </summary>
    /// <param name="file">Путь к файлу или к картинке с персонажем</param>
    /// <param name="x">Координата где персонаж появится по x</param>
    /// <param name="y">Координата где персонаж появится по y</param>
    /// <param name="width">Ширина персонажа</param>
    /// <param name="height">Высота персонажа</param>
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
    /// Сеттер для направления
    /// </summary>
    /// <param name="direction">Направление куда идёт персонаж</param>
    void SetDirection(int direction);

    /// <summary>
    /// Геттер для направления
    /// </summary>
    /// <returns>Возвращает направление куда пошёл персонаж</returns>
    int GetDirection() const;

    /// <summary>
    /// Сеттер для скорости
    /// Устанавливает скорость передвижения персонажа
    /// </summary>
    /// <param name="speed">Скорость с которой будет перемещаться персонаж</param>
    void SetSpeed(float speed);

    /// <summary>
    /// Геттер для скорости
    /// </summary>
    /// <returns>Возвращает скорость перемещения персонажа</returns>
    float GetSpeed() const;

    /// <summary>
    /// Сеттер для спрайта
    /// Устанавливает спрайт на какую-то текстуру
    /// </summary>
    /// <param name="texture">Текстура персонажа</param>
    void SetSprite(Texture& texture);

    /// <summary>
    /// Геттер для спрайта
    /// </summary>
    /// <returns>Возвращает оригинал спрайта</returns>
    Sprite& GetSprite();

    /// <summary>
    /// Сеттер для высоты персонажа
    /// </summary>
    /// <param name="height">Высота персонажа</param>
    void SetHeight(float height);

    /// <summary>
    /// Геттер для высоты персонажа
    /// </summary>
    /// <returns>Возвращает высоту персонажа</returns>
    float GetHeight() const;

    /// <summary>
    /// Сеттер для ширины
    /// Устанавливает ширину персонажа
    /// </summary>
    /// <param name="width">Ширина персонажа</param>
    void SetWidth(float width);

    /// <summary>
    /// Геттер для ширины персонажа
    /// </summary>
    /// <returns>Возвращает ширину персонажа</returns>
    float GetWidth() const;

    /// <summary>
    /// Сеттер для координаты X
    /// Устанавливает координату X
    /// </summary>
    /// <param name="x">Координата X</param>
    void SetX(float x);

    /// <summary>
    /// Геттер для координаты X
    /// </summary>
    /// <returns>Возвращает координату X</returns>
    float GetX() const;

    /// <summary>
    /// Сеттер для координаты Y
    /// Устанавливает координату Y
    /// </summary>
    /// <param name="y">Координата Y</param>
    void SetY(float y);

    /// <summary>
    /// Геттер для координаты Y
    /// </summary>
    /// <returns>Возвращает координату Y</returns>
    float GetY() const;

    /// <summary>
    /// Сеттер для скорости в определённое направление по X
    /// </summary>
    /// <param name="dx">Направление по X в которое персонаж идёт</param>
    void SetDx(float dx);

    /// <summary>
    /// Геттер для скорости в определённое направление по X
    /// </summary>
    /// <returns>Возвращает скорость в направление по X</returns> //-speed это влево
    float GetDx() const;

    /// <summary>
    /// Сеттер для скорости в определённое направление по Y
    /// </summary>
    /// <param name="dy">Направление по Y в которое персонаж идёт</param>
    void SetDy(float dy);

    /// <summary>
    /// Геттер для скорости в определённое направление по Y
    /// </summary>
    /// <returns>Возвращает скорость d направление по Y</returns>
    float GetDy() const;

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
    void SetFile(string filename);

    /// <summary>
    /// Геттер для переменной файл
    /// </summary>
    /// <returns>Файл</returns>
    string GetFile() const;

    /// <summary>
    /// Позволяет нашему персонажу двигаться
    /// </summary>
    /// <param name="time">Время из библиотеки сфмл</param>
    void Move(float time, Sound& sound_walk1, Sound& sound_walk2, Sound& sound_heal, Sound& sound_collide, String* main_map, int height_map, int width_map);

    /// <summary>
    /// Анимирует нашего персонажа
    /// </summary>
    /// <param name="player">Игрок</param>
    /// <param name="current_frame">Кадр</param>
    /// <param name="time">Время из библиотеки сфмл</param>
    void Animation(Player& player, float& current_frame, float& time, Sound& sound_walk1, Sound& sound_walk2);

   
    void InteractionWithMap(Sound& sound_heal, Sound& sound_collide, String* main_map, int height_map, int width_map);

    View ChangeView();

    View GetView() const;
};

