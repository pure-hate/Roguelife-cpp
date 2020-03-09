#include <iostream>
#include <fstream>


int global_map[20][20];

void loadmap()
{

		const int n = 20, m = 20;
		
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
		f.close();

}