#pragma once
#include "Bullet.h"

class Enemy
{
	int x; 
	int y;
public:
	void createEnemy();
	void move(int);
	void shut();
	int returnX();
	int returnY();
};
