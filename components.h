#pragma once

struct Position
{
	int x, y;
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

struct Components
{
	Positions positions;
	Main_Sprites main_sprites;
	Healths healths;
};