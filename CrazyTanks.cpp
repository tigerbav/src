#include "Field.h"
#include <ctime>
#include <iostream>
#include <Windows.h>

const int MAX = 25;
const char ENEMY = '#';
const char BULLET = 'o';
const char GOLD = 36;
const char SHUT = 32;
char PUDRL[4] = {193, 194, 195, 180};//PLAYER_UP_DOWN_RIGHT_LEFT
char KUDRL[4] = { 72, 80, 77, 75 };//KEY_UP_DOWN_RIGHT_LEFT
char WALLS[4] = {219, 176, 177, 178};
int gameStatus = 0;


int main()
{
	srand(time(NULL));
	if (gameStatus == 0)
	{
		Field field;
		field.drawField();
	}
	else if (gameStatus == 1)
		std::cout << "\nGame over!";
	else if (gameStatus == 2)
		std::cout << "\nVictory!";
	Sleep(5000);
	exit(-1);
    return 0;
}