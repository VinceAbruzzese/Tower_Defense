#include "FireTower.h"

FireTower::FireTower() :Tower(FIRE_COST_1, FIRE_SELL_1, FIRE_RANGE_1, FIRE_POWER_1, FIRE_RATE_1){}

void FireTower::upgradeTower()
{
	switch (level)
	{
	case Tower::Level_1: //If Level 1, upgrade to level 2
		Tower::setAttributes(FIRE_COST_2, FIRE_SELL_2, FIRE_RANGE_2, FIRE_POWER_2, FIRE_RATE_2, Level_2);
		notify();
		break;

	case Tower::Level_2:
		Tower::setAttributes(FIRE_COST_3, FIRE_SELL_3, FIRE_RANGE_3, FIRE_POWER_3, FIRE_RATE_3, Level_3);
		notify();
		break;
	}
}

string FireTower::getType() const
{
	return "Fire Tower";
}

int FireTower::getUpgradeCost() const
{
	if (level == Level_1) return FIRE_COST_2;
	if (level == Level_2) return FIRE_COST_3;
	return -1; //Means we reached max level
}

void FireTower::attackCritter(vector<Critter*> &critter_list)
{

	int x1 = x;
	int y1 = y;

	for (int i = 0; i < critter_list.size(); i++) //loop through all critters
	{

		int x2 = critter_list.at(i)->getX();
		int y2 = critter_list.at(i)->getY();
		int distance = abs(x2 - x1) + abs(y2 - y1);

		if (range >= distance && rate_timer.getTime() >= rate)
		{
			//If in range & and has waited enough time, attack
			critter_list.at(i)->takeDamage(power, this);
		}
	}
	if (rate_timer.getTime() >= rate)
		rate_timer.reset(); //We place timer here, gives us splash damage
}