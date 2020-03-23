#pragma once

#include "point.h"
#include "Items.h"
#include "images.h"
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

	void DrawMoney()
	{
		moneyText.setPosition(view.getCenter().x - 300, view.getCenter().y - 200);//задаем позицию текста, центр камеры
		window.draw(moneyText);//рисую этот текст
	}

	void AddMoney(int num)
	{
		amount += num;
		RefreshMoney();
	}

	void DeleteMoney(int num)
	{
		amount -= num;
		RefreshMoney();
	}

	void SetMoney(int num)
	{
		amount = num;
		RefreshMoney();
	}

	void RefreshMoney()
	{
		PlayerMonString << amount;
		moneyText.setString("Денег: " + PlayerMonString.str());//задает строку тексту
		PlayerMonString.str("");
	}

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
	string invString;

	template <typename T>
	void Add(const char* str, std::pair<const char*, T*> param)
	{
		Item a;
		a.set("Name", str);

		a.set(param.first, param.second);

		inv.push_back(a);

		RefreshInv();
	}

	void RefreshInv()
	{
		invString = "";
		for (int i = 0; i < inv.size(); i++)
		{
			invString += inv[i].getstr("Name") + "\n";			
		}
	}

	void DrawInv()
	{
			invText.setString(invString);
			invText.setPosition(view.getCenter().x - 300, view.getCenter().y - (180 - 20 ));//задаем позицию текста, центр камеры
			window.draw(invText);//рисую этот текст
	}

	int Find(const char* str)
	{
		for (int i = 0; i < inv.size(); i++)
		{
			if (inv[i].getstr("Name") == str)
			{
				return i;
			}
		}
		return -1;

	}
	template <typename T>
	void Set(int id, string str, T* param)
	{
		inv[id].set(str, param);
		RefreshInv();
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

struct Energy
{
	int max;
	int current;
};

struct Food
{
	int ccal;
	int carb;
	int fat;
	int prot;
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