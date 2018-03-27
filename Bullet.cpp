#include "Bullet.h"
#include <cstdlib>
extern char WALLS[4];
extern char PUDRL[4];
extern const char SHUT;
extern const char BULLET;
extern const char ENEMY;
Bullet::Bullet() {}
Bullet::Bullet(int x_, int y_) : x(x_), y(y_){}

void Bullet::move(char temp)
{
	int value;
	if (temp == PUDRL[0])
		--x;
	else if (temp == PUDRL[1])
		++x;
	else if (temp == PUDRL[2])
		++y;
	else if (temp == PUDRL[3])
		--y;
}
void Bullet::generateBullet(int tempx, int tempy)
{
	x = tempx;
	y = tempy;
}
int Bullet::returnX()
{
	return x;
}

int Bullet::returnY()
{
	return y;
}