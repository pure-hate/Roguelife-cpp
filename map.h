#include <iostream>
#include <fstream>
#include "Constants.h"


int global_map[SIZEX][SIZEY];

void loadmap()
{
		
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