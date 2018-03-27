#pragma once
#include "Bullet.h"

class Player
{
	int x;
	int y;
public:
	Player();
	~Player();
	void move(char);
	void beDamaged();
	int returnX();
	int returnY();
	int lives;
};

