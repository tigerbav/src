#pragma once

class Bullet
{
	int x;
	int y;
	char face;
public:
	Bullet();
	Bullet(int, int);
	void generateBullet(int, int);
	void move(char); 
	int returnX();
	int returnY();
};

