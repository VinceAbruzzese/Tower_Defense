#include "AttackStrategy.h"

Critter* AttackWeakest::targetCritter(vector<Critter*> &critter_list, Tower* tower)
{
	int x1 = tower->getX(); //store the towers x,y values
	int y1 = tower->getY();
	Critter* critter = NULL;

	for (int i = 0; i < critter_list.size(); i++) //loop through critters
	{
		int x2 = critter_list.at(i)->getX(); //store critter x,y values
		int y2 = critter_list.at(i)->getY();
		int distance = abs(x2 - x1) + abs(y2 - y1); //calculate distance between critter and tower at this point

		if (tower->getRange() >= distance && tower->getTimer().getTime() >= tower->getRate()) //if its in range and can shoot
		{
			if (critter == NULL)
				critter = critter_list.at(i); //if not pointing to anything point to first critter

			if (critter->getHP() > critter_list.at(i)->getHP()) //if HP is lower then set new critter
				critter = critter_list.at(i);
		}
	}
	return critter;
}

Critter* AttackNearest::targetCritter(vector<Critter*> &critter_list, Tower* tower)
{
	int x1 = tower->getX();
	int y1 = tower->getY();
	int nearest;
	Critter* critter = NULL;

	for (int i = 0; i < critter_list.size(); i++)
	{
		int x2 = critter_list.at(i)->getX();
		int y2 = critter_list.at(i)->getY();
		int distance = abs(x2 - x1) + abs(y2 - y1);

		if (tower->getRange() >= distance && tower->getTimer().getTime() >= tower->getRate()) //if in range and can shoot
		{
			if (critter == NULL) //first critter in range
			{
				critter = critter_list.at(i); //set first critter in range
				nearest = distance; //set nearest value
			}
			if (nearest > distance)
			{
				critter = critter_list.at(i); //set new nearest critter
				nearest = distance;
			}
		}
	}
	return critter;
}

Critter* AttackClosestToExit::targetCritter(vector<Critter*> &critter_list, Tower* tower)
{
	int x1 = tower->getX();
	int y1 = tower->getY();
	Critter* critter = NULL;
	int location = -1;

	for (int i = 0; i < critter_list.size(); i++)
	{
		int x2 = critter_list.at(i)->getX();
		int y2 = critter_list.at(i)->getY();
		int distance = abs(x2 - x1) + abs(y2 - y1);

		if (tower->getRange() >= distance && tower->getTimer().getTime() >= tower->getRate()) //if in range and can shoot
		{
			if (location == -1)
			{
				location = critter_list.at(i)->getLocation();
				critter = critter_list.at(i);
			}
			else if (critter_list.at(i)->getLocation() > location)
			{
				location = critter_list.at(i)->getLocation();
				critter = critter_list.at(i);
			}
		}
	}
	return critter; //no critters in range
}

Critter* AttackStrongest::targetCritter(vector<Critter*> &critter_list, Tower* tower)
{
	int x1 = tower->getX();
	int y1 = tower->getY();
	Critter* critter = NULL;

	for (int i = 0; i < critter_list.size(); i++) //loop through critters
	{
		int x2 = critter_list.at(i)->getX(); //store critter x,y values
		int y2 = critter_list.at(i)->getY();
		int distance = abs(x2 - x1) + abs(y2 - y1); //calculate distance between critter and tower at this point

		if (tower->getRange() >= distance && tower->getTimer().getTime() >= tower->getRate()) //if its in range and can shoot
		{
			if (critter == NULL)
				critter = critter_list.at(i); //if not pointing to anything point to first critter

			if (critter->getHP() < critter_list.at(i)->getHP()) //if HP is higher then set new critter
				critter = critter_list.at(i);
		}
	}
	return critter;
}