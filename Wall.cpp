#include "Wall.h"
#include <cstdlib>
#include <algorithm>

//static int temp[20];
//int tmp[2];
//static int count = 0;
//int* ptr = NULL;

Wall::Wall()
{
	
}


Wall::~Wall()
{
}


void Wall::createWall()
{
	while (true)
	{
		x = rand() % (MAX - 2) + 1;
		y = rand() % (MAX - 2) + 1;
		if (x != MAX - 2 && y != MAX / 2)
			break;
	}
}
int Wall::returnX()
{
	return x;
}
int Wall::returnY()
{
	return y;
}