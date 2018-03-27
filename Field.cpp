#include "Field.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>
#include <cstdlib>
#include <Windows.h>
int count = 0;
Bullet bullet(0, 0);
int main();
static int point = 0;

void drowField(std::vector<std::string>& field, Player& player)
{
	while (count < MAX)
	{
		std::cout << field[count] << std::endl;
		++count;
	}
	std::cout << "Player lives: " << player.lives << std::endl;
	count = 0;
}

void endGame(int temp)
{
	
		gameStatus = temp;
		main();
}

void createField(std::vector<std::string>& field)
{
	std::string field_border;
	std::string field_between;
	while (count < MAX)
	{
		if (count != 0 && count != MAX - 1)
			field_between += " ";
		else
			field_between += WALLS[0];
		field_border += WALLS[0];
		++count;
	}
	count = 0;
	while (count < MAX)
	{
		if (count != 0 && count != MAX - 1)
			field.push_back(field_between);
		else
			field.push_back(field_border);
		++count;
	}
	count = 0;
}

void createWall(Wall* wall, std::vector<std::string>& field)
{
	for (int i = 0; i < 20; i++)
	{
		wall[i].createWall();
		if (field[wall[i].returnX()][wall[i].returnY()] != ' ')
		{
			--i;
			continue;
		}
		field[wall[i].returnX()][wall[i].returnY()] = WALLS[3];
	}
}

void createGold(Gold& gold, std::vector<std::string>& field)
{
	gold.createGold();
	for (int i = gold.returnY() - 1; i < gold.returnY() + 2; i++)
		for (int j = gold.returnX() - 1; j < gold.returnX() + 2; j++)
			field[j][i] = WALLS[3];
	field[gold.returnX()][gold.returnY()] = GOLD;
}

void createEnemies(Enemy* enemy, std::vector<std::string>& field)
{
	for (int i = 0; i < 5; i++)
	{
		enemy[i].createEnemy();
		if (field[enemy[i].returnX()][enemy[i].returnY()] != ' ')
		{
			--i;
			continue;
		}
		field[enemy[i].returnX()][enemy[i].returnY()] = ENEMY;
	}
}

void changePlayerPosition(char key, int x, int y, std::vector<std::string>& field, Player& player, char look)
{
	field[player.returnX()][player.returnY()] = look;
	std::swap(field[x][y], field[player.returnX()][player.returnY()]);
	player.move(key);
}

void generateBullet(int x, int y)
{
	bullet.generateBullet(x, y);
}

void shutingRoad(int x, int y, Bullet& bullet, std::vector<std::string>& field, char look, Player& player)
{
	if (field[bullet.returnX()][bullet.returnY()] == ' ')
	{
		while (field[bullet.returnX() + x][bullet.returnY() + y] == ' ')
		{
			field[bullet.returnX()][bullet.returnY()] = BULLET;
			if (field[bullet.returnX() + x][bullet.returnY() + y] != ' ')
				field[bullet.returnX()][bullet.returnY()] = ' ';				
			else
			{
				Sleep(0.00001);
				system("cls");
				drowField(field, player);
			}
			std::swap(field[bullet.returnX() + x][bullet.returnY() + y], field[bullet.returnX()][bullet.returnY()]);
			bullet.move(look);
		}
		if (field[bullet.returnX() + x][bullet.returnY() + y] != ' ' &&
			field[bullet.returnX()][bullet.returnY()] == BULLET)
			field[bullet.returnX()][bullet.returnY()] = ' ';
		if (field[bullet.returnX() + x][bullet.returnY() + y] == PUDRL[0] ||
			field[bullet.returnX() + x][bullet.returnY() + y] == PUDRL[1] ||
			field[bullet.returnX() + x][bullet.returnY() + y] == PUDRL[2] ||
			field[bullet.returnX() + x][bullet.returnY() + y] == PUDRL[3])
			player.beDamaged();
		if (field[bullet.returnX() + x][bullet.returnY() + y] == WALLS[0])
			field[bullet.returnX()][bullet.returnY()] = ' ';
		else if (field[bullet.returnX() + x][bullet.returnY() + y] == WALLS[3])
			field[bullet.returnX() + x][bullet.returnY() + y] = WALLS[2];
		else if (field[bullet.returnX() + x][bullet.returnY() + y] == WALLS[2])
			field[bullet.returnX() + x][bullet.returnY() + y] = WALLS[1];
		else if (field[bullet.returnX() + x][bullet.returnY() + y] == WALLS[1] ||
			field[bullet.returnX() + x][bullet.returnY() + y] == ENEMY ||
			field[bullet.returnX() + x][bullet.returnY() + y] == GOLD)
		{
			field[bullet.returnX() + x][bullet.returnY() + y] = ' ';
			++point;
		}
					
	}
	else if (field[bullet.returnX()][bullet.returnY()] == WALLS[3])
		field[bullet.returnX()][bullet.returnY()] = WALLS[2];
	else if (field[bullet.returnX()][bullet.returnY()] == WALLS[2])
		field[bullet.returnX()][bullet.returnY()] = WALLS[1];
	else if (field[bullet.returnX()][bullet.returnY()] == WALLS[1] ||
		field[bullet.returnX()][bullet.returnY()] == ENEMY ||
		field[bullet.returnX()][bullet.returnY()] == GOLD)
	{
		field[bullet.returnX()][bullet.returnY()] = ' ';
		++point;
	}
	
}

void steppingEnemy(int number, int x, int y, Enemy* enemy, std::vector<std::string>& field, int way)
{
	if (field[x][y] == ' ')
	{
		std::swap(field[x][y], field[enemy[number].returnX()][enemy[number].returnY()]);
		enemy[number].move(way);
	}
}

Field::Field()
{
	//Create FIELD
	createField(field);
	//create WALL
	createWall(wall, field);
	//create GOLD
	createGold(gold, field);
	//create Player
	field[player.returnX()][player.returnY()] = PUDRL[0];
	//create Enemies
	createEnemies(enemy, field);

}

void Field::drawField()
{
	char temp = NULL;
	int j = 0;
	while (true)
	{
		while (!_kbhit())
		{
			Sleep(200);
			system("cls");
			drowField(field, player);
			++j;;
			if (j % 5 == 0)
				time.showTime();
			std::cout << time.returnM() << ':' << time.returnS() << std::endl << "Points: " << point;

			//enemies` steping
			while (count != 5)
			{
				if (field[enemy[count].returnX()][enemy[count].returnY()] == ENEMY)
				{
					int enemy_step = rand() % 5;
					int value = rand() % 30;
					if (enemy_step == 0)
					{
						steppingEnemy(count, enemy[count].returnX() - 1, enemy[count].returnY(), enemy, field, 0);
						generateBullet(enemy[count].returnX() - 1, enemy[count].returnY());
						if (value == 0)
							shutingRoad(-1, 0, bullet, field, PUDRL[0], player);
					}
					else if (enemy_step == 1)
					{
						steppingEnemy(count, enemy[count].returnX() + 1, enemy[count].returnY(), enemy, field, 1);
						generateBullet(enemy[count].returnX() + 1, enemy[count].returnY());
						if (value == 0)
							shutingRoad(1, 0, bullet, field, PUDRL[1], player);
					}
					else if (enemy_step == 2)
					{
						steppingEnemy(count, enemy[count].returnX(), enemy[count].returnY() + 1, enemy, field, 2);
						generateBullet(enemy[count].returnX(), enemy[count].returnY() + 1);
						if (value == 0)
							shutingRoad(0, 1, bullet, field, PUDRL[2], player);
					}
					else if (enemy_step == 3)
					{
						steppingEnemy(count, enemy[count].returnX(), enemy[count].returnY() - 1, enemy, field, 3);
						generateBullet(enemy[count].returnX(), enemy[count].returnY() - 1);
						if (value == 0)
							shutingRoad(0, 1, bullet, field, PUDRL[3], player);
					}
				}
				++count;

			}
			if (field[gold.returnX()][gold.returnY()] != GOLD)
				endGame(1);

			if (point == 5)
				endGame(2);
			count = 0;
		}

		temp = _getch();
		if (temp == KUDRL[0] && field[player.returnX() - 1][player.returnY()] == ' ')
		{
			changePlayerPosition(temp, player.returnX() - 1, player.returnY(), field, player, PUDRL[0]);
		}
		else if (temp == KUDRL[1] && field[player.returnX() + 1][player.returnY()] == ' ')
		{
			changePlayerPosition(temp, player.returnX() + 1, player.returnY(), field, player, PUDRL[1]);
		}
		else if (temp == KUDRL[2] && field[player.returnX()][player.returnY() + 1] == ' ')
		{
			changePlayerPosition(temp, player.returnX(), player.returnY() + 1, field, player, PUDRL[2]);
		}
		else if (temp == KUDRL[3] && field[player.returnX()][player.returnY() - 1] == ' ')
		{
			changePlayerPosition(temp, player.returnX(), player.returnY() - 1, field, player, PUDRL[3]);
		}
		else if (temp == SHUT)
		{
			if (field[player.returnX()][player.returnY()] == PUDRL[0])
			{
				generateBullet(player.returnX() - 1, player.returnY());
				shutingRoad(-1, 0, bullet, field, PUDRL[0], player);
			}
			else if (field[player.returnX()][player.returnY()] == PUDRL[1])
			{
				generateBullet(player.returnX() + 1, player.returnY());
				shutingRoad(1, 0, bullet, field, PUDRL[1], player);
			}
			else if (field[player.returnX()][player.returnY()] == PUDRL[2])
			{
				generateBullet(player.returnX(), player.returnY() + 1);
				shutingRoad(0, 1, bullet, field, PUDRL[2], player);
			}
			else if (field[player.returnX()][player.returnY()] == PUDRL[3])
			{
				generateBullet(player.returnX(), player.returnY() - 1);
				shutingRoad(0, -1, bullet, field, PUDRL[3], player);
			}
		}
	}
}
