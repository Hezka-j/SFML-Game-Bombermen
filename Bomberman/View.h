#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

View view;//�������� ���������� ��� ������
/// <summary>
/// ��������� ������ ����� ������ ������� �� ����������
/// </summary>
/// <param name="x">���������� ��������� X</param>
/// <param name="y">���������� ��������� Y</param>
/// <returns>���������� ����� ������</returns>
View GetPlayerCordinate(float x, float y)
{
	view.setCenter(x + 100, y);
	//cout << x << " ";
	//cout << y << " ";
	return view;
}
/// <summary>
/// ������������� ������� ������� �� ������� ����� ������ ���
/// </summary>
/// <returns>���������� ����� ������</returns>
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
