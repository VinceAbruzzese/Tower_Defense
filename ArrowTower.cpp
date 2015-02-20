#include "ArrowTower.h"


ArrowTower::ArrowTower() :Tower(ARROW_COST_1, ARROW_SELL_1, ARROW_RANGE_1, ARROW_POWER_1, ARROW_RATE_1)
{
	critical_strike = ARROW_CS_PERCENTAGE_1;
	attack_strategy = new AttackClosestToExit(); //this is the default attack strategy
}

void ArrowTower::upgradeTower()
{
	switch (level)
	{
	case Tower::Level_1: //If Level 1, upgrade to level 2
		Tower::setAttributes(ARROW_COST_2, ARROW_SELL_2, ARROW_RANGE_2, ARROW_POWER_2, ARROW_RATE_2, Level_2);
		critical_strike = ARROW_CS_PERCENTAGE_2;
		notify();
		break;

	case Tower::Level_2:
		Tower::setAttributes(ARROW_COST_3, ARROW_SELL_3, ARROW_RANGE_3, ARROW_POWER_3, ARROW_RATE_3, Level_3);
		critical_strike = ARROW_CS_PERCENTAGE_3;
		notify();
		break;
	}
}

string ArrowTower::getType() const
{
	return "Arrow Tower";
}

int ArrowTower::getUpgradeCost() const
{
	if (level == Level_1) return ARROW_COST_2;
	if (level == Level_2) return ARROW_COST_3;
	return -1; //Means we reached max level
}

void ArrowTower::setStrategy(Strategy* attack_strategy)
{
	this->attack_strategy = attack_strategy;
}

Critter* ArrowTower::targetCritter(vector<Critter*> &critter_list)
{
	return attack_strategy->targetCritter(critter_list, this);
}

void ArrowTower::attackCritter(vector<Critter*> &critter_list)
{
	if (this->targetCritter(critter_list) != NULL)
	{
		int random = rand() % 101; //value between 0 and 100

		if (random <= critical_strike * 100)
			this->targetCritter(critter_list)->takeDamage((power * 2), this); //if between 0 and %, deal double
		else
			this->targetCritter(critter_list)->takeDamage(power, this);

		rate_timer.reset();
	}
}

float ArrowTower::getCriticalStrike()
{
	return critical_strike;
}