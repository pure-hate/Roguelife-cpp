#include <iostream>
#include <fstream>

//int n, i = 10;
int global_map[5][5];

void loadmap()
{

		const int n = 5, m = 5;
		
		std::ifstream f("map.txt");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				f >> global_map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << global_map[i][j] << "\t";
			std::cout << "\n";
		}

}