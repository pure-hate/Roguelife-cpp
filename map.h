#include <iostream>
#include <fstream>

const int SIZEX = 40;
const int SIZEY = 40;

int global_map[SIZEX][SIZEY];

void loadmap()
{

		//const int n = SIZEX, m = SIZEY;
		
		std::ifstream f("map.txt");
		for (int i = 0; i < SIZEX; i++) {
			for (int j = 0; j < SIZEY; j++) {
				f >> global_map[i][j];
			}
		}
/*
		for (int i = 0; i < SIZEX; i++)
		{
			for (int j = 0; j < SIZEY; j++)
				std::cout << global_map[i][j] << "\t";
			std::cout << "\n";
		}
*/
		f.close();

}