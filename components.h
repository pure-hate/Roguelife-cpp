#pragma once

struct Position
{
	int x, y;
};

struct Playable
{
	bool isPlayer;
};

struct Main_Sprite
{
	Sprite main_sprite1;
};

struct Health
{
	int max;
	int current;
};