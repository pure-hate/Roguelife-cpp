#pragma once//void SearchWay(int x, int y, int x_to, int y_to)

#include "point.h"

template <class T, class S>
void SearchWay(T* map, S& path , int x, int y, int x_to, int y_to)
{




	const int size = 50;
	int matrix[size][size][3];

	int step;
	bool added = true, result = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j] != 0)
			{
				matrix[i][j][0] = -2;// занято
			}
			else
			{
				matrix[i][j][0] = -1;// Мы еще нигде не были
			}
		}
	}
	matrix[x_to][y_to][0] = 0;// До финиша ноль шагов - от него будем разбегаться
	step = 0; // Изначально мы сделали ноль шагов

	// Пока вершины добаляются и мы не дошли до старта

	while (added && matrix[x][y][0] == -1)
	{
		added = false;// Пока что ничего не добавили
		step++;// Увеличиваем число шагов

		for (int i = 0; i < size; i++)// Пробегаем по всей карте
		{
			for (int j = 0; j < size; j++)
			{
				// Если (i, j) была добавлена на предыдущем шаге
				// Пробегаем по всем четырем сторонам
				if (matrix[i][j][0] == step - 1)
				{
					int _i, _j;

					_i = i + 1; _j = j;
					// Если не вышли за пределы карты -  обрабатываем
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// Если (_i, _j) уже добавлено или непроходимо, то не обрабатываем 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // Добав-
							matrix[_i][_j][1] = i; // ля-
							matrix[_i][_j][2] = j; // ем
							added = true; // Что-то добавили
						}
					}
					_i = i - 1; _j = j;
					// Если не вышли за пределы карты -  обрабатываем
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// Если (_i, _j) уже добавлено или непроходимо, то не обрабатываем 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // Добав-
							matrix[_i][_j][1] = i; // ля-
							matrix[_i][_j][2] = j; // ем
							added = true; // Что-то добавили
						}
					}
					_i = i; _j = j + 1;
					// Если не вышли за пределы карты -  обрабатываем
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// Если (_i, _j) уже добавлено или непроходимо, то не обрабатываем 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // Добав-
							matrix[_i][_j][1] = i; // ля-
							matrix[_i][_j][2] = j; // ем
							added = true; // Что-то добавили
						}
					}
					_i = i; _j = j - 1;
					// Если не вышли за пределы карты -  обрабатываем
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// Если (_i, _j) уже добавлено или непроходимо, то не обрабатываем 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // Добав-
							matrix[_i][_j][1] = i; // ля-
							matrix[_i][_j][2] = j; // ем
							added = true; // Что-то добавили
						}
					}
				}
			}
		}
	}

	if (matrix[x][y][0] == -1)
	{
		result = false; // то пути не существует
	}


	if (result)
	{
		int _i = x, _j = y;

		while (matrix[_i][_j][0] != 0)
		{
			//std::cout << std::endl;
			//std::cout << _i << " " << _j << std::endl;

			//Point point2;
			//point2.x = _i;
			Point point;
			point.x = _i;
			point.y = _j;
			
			path.push_back(point);
			// тут ваш код где  записываем значение клеток и шагаем дальше к началу
// записывать надо _i _J	
			int li = matrix[_i][_j][1];
			int lj = matrix[_i][_j][2];
			_i = li; _j = lj;
		}
	}
}
