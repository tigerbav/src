#pragma once
#include "Gold.h"
extern const int MAX;
class Wall
{
	int x;
	int y;
	Gold gold;
public:
	Wall();
	~Wall();
	void createWall();
	int returnX();
	int returnY();
};

