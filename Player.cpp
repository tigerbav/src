#include "Player.h"
#include <cstdlib>
extern const int MAX;
extern char PUDRL[4];
extern char KUDRL[4];
void endGame(int temp);
Player::Player()
{
	x = MAX - 2;
	y = MAX / 2;
	lives = 3;
}


Player::~Player()
{
}

void Player::move(char temp)
{
	if (temp == KUDRL[0])
	{
		--x;
	}
	else if (temp == KUDRL[1])
	{
		++x;
	}
	else if (temp == KUDRL[3])
	{
		--y;
	}
	else if (temp == KUDRL[2])
	{
		++y;
	}
}

int Player::returnX()
{
	return x;
}

int Player::returnY()
{
	return y;
}
void Player::beDamaged()
{
	--lives;
	if (lives == 0)
		endGame(1);
}