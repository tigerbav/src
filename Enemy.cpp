#include "Enemy.h"
#include <cstdlib>
extern const int MAX;
extern char KUDRL[4];

void Enemy::createEnemy()
{
	x = rand() % (MAX - 8) + 1;
	y = rand() % (MAX - 2) + 1;
}

void Enemy::move(int value)
{
	if (value == 1)
		++x;
	else if (value == 0)
		--x;
	else if (value == 2)
		++y;
	else if (value == 3)
		--y;
}

int Enemy::returnX()
{
	return x;
}
int Enemy::returnY()
{
	return y;
}