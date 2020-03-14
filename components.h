#pragma once

#include "point.h"
#include "Items.h"
#include <stdarg.h>
#include <vector>




struct Position
{
	int x, y;
};

struct Name
{
	string name;
};

struct Money
{
	int amount;
};

struct State
{
	string state;
};

struct Trader
{
	string type;
};

struct Inventory
{
	std::vector<Item> inv;


	template <typename T>
	void Add(const char* str, std::pair<const char*,T*> param)
	{
		Item a;
		a.set("Name", str);
		
		
			a.set(param.first, param.second);
		
		
		inv.push_back(a);
		//cout << param.first << param.second;
	
	}
};


struct Path
{
	std::vector<Point> path;

	void add(int x, int y)
	{
		Point b;
		b.x = x, b.y = y;
		
		path.push_back(b);
	}

};

struct Main_Sprite
{
	string main_sprite1;
};

struct Health
{
	int max;
	int current;
};


using EntityID = int64_t;

template <typename Type>
using ComponentMap = unordered_map<EntityID, Type>;

using Main_Sprites = ComponentMap<Main_Sprite>;
using Positions = ComponentMap<Position>;
using Healths = ComponentMap<Health>;
using States = ComponentMap<State>;
using Paths = ComponentMap<Path>;
using Traders = ComponentMap<Trader>;
using Names = ComponentMap<Name>;
using Moneys = ComponentMap<Money>;
using Inventories = ComponentMap<Inventory>;

struct Components
{
	Positions positions;
	Main_Sprites main_sprites;
	Healths healths;
	States states;
	Paths paths;
	Traders traders;
	Names names;
	Moneys moneys;
	Inventories inventories;
};