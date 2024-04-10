#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

View view;//создание переменной для камеры
/// <summary>
/// Настройка камеры чтобы камера следила за персонажем
/// </summary>
/// <param name="x">Координата персонажа X</param>
/// <param name="y">Координата персонажа Y</param>
/// <returns>Возвращает копию камеры</returns>
View GetPlayerCordinate(float x, float y)
{
	view.setCenter(x + 100, y);
	//cout << x << " ";
	//cout << y << " ";
	return view;
}
/// <summary>
/// Устанавливает горячие клавиши на которые можно менять вид
/// </summary>
/// <returns>Возвращает копию камеры</returns>
View ChangeView() {
	if (Keyboard::isKeyPressed(Keyboard::Z)) // zoom out view
	{
		view.zoom(1.0006f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::N)) // normal view
	{
		view.setSize(1000, 700);
	}
	//else if (Keyboard::isKeyPressed(Keyboard::B))// zoom in view
	//{
	//	view.setSize(500, 300);
	//}
	return view;
}
