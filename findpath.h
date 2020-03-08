#pragma once//void SearchWay(int x, int y, int x_to, int y_to)
template <class T>
void SearchWay(T* map, int x, int y, int x_to, int y_to)
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
				matrix[i][j][0] = -2;// ������
			}
			else
			{
				matrix[i][j][0] = -1;// �� ��� ����� �� ����
			}
		}
	}
	matrix[x_to][y_to][0] = 0;// �� ������ ���� ����� - �� ���� ����� �����������
	step = 0; // ���������� �� ������� ���� �����

	// ���� ������� ���������� � �� �� ����� �� ������

	while (added && matrix[x][y][0] == -1)
	{
		added = false;// ���� ��� ������ �� ��������
		step++;// ����������� ����� �����

		for (int i = 0; i < size; i++)// ��������� �� ���� �����
		{
			for (int j = 0; j < size; j++)
			{
				// ���� (i, j) ���� ��������� �� ���������� ����
				// ��������� �� ���� ������� ��������
				if (matrix[i][j][0] == step - 1)
				{
					int _i, _j;

					_i = i + 1; _j = j;
					// ���� �� ����� �� ������� ����� -  ������������
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// ���� (_i, _j) ��� ��������� ��� �����������, �� �� ������������ 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // �����-
							matrix[_i][_j][1] = i; // ��-
							matrix[_i][_j][2] = j; // ��
							added = true; // ���-�� ��������
						}
					}
					_i = i - 1; _j = j;
					// ���� �� ����� �� ������� ����� -  ������������
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// ���� (_i, _j) ��� ��������� ��� �����������, �� �� ������������ 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // �����-
							matrix[_i][_j][1] = i; // ��-
							matrix[_i][_j][2] = j; // ��
							added = true; // ���-�� ��������
						}
					}
					_i = i; _j = j + 1;
					// ���� �� ����� �� ������� ����� -  ������������
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// ���� (_i, _j) ��� ��������� ��� �����������, �� �� ������������ 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // �����-
							matrix[_i][_j][1] = i; // ��-
							matrix[_i][_j][2] = j; // ��
							added = true; // ���-�� ��������
						}
					}
					_i = i; _j = j - 1;
					// ���� �� ����� �� ������� ����� -  ������������
					if (_i >= 0 && _j >= 0 && _i < size && _j < size)
					{
						// ���� (_i, _j) ��� ��������� ��� �����������, �� �� ������������ 
						if (matrix[_i][_j][0] == -1 && matrix[_i][_j][0] != -2)
						{
							matrix[_i][_j][0] = step; // �����-
							matrix[_i][_j][1] = i; // ��-
							matrix[_i][_j][2] = j; // ��
							added = true; // ���-�� ��������
						}
					}
				}
			}
		}
	}

	if (matrix[x][y][0] == -1)
	{
		result = false; // �� ���� �� ����������
	}


	if (result)
	{
		int _i = x, _j = y;

		while (matrix[_i][_j][0] != 0)
		{
			std::cout << std::endl;
			std::cout << _i << " " << _j << std::endl;
			// ��� ��� ��� ���  ���������� �������� ������ � ������ ������ � ������
// ���������� ���� _i _J	
			int li = matrix[_i][_j][1];
			int lj = matrix[_i][_j][2];
			_i = li; _j = lj;
		}
	}
}
