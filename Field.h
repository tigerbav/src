#pragma once
#include <vector>
#include "Bullet.h"
#include "Enemy.h"
#include "Gold.h"
#include "Player.h"
#include "Time.h"
#include "Wall.h"
extern const int MAX;
extern char WALLS[4];
extern char PUDRL[4];
extern char KUDRL[4];
extern const char BULLET;
extern const char GOLD;
extern const char ENEMY;
extern const char SHUT;
extern int gameStatus;

class Field
{
	std::vector<std::string> field;
	Player player;
	Gold gold;
	Enemy enemy[5];
	Wall wall[20];
	Time time;
public:
	Field();
	void drawField();
};

