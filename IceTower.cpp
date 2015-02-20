#include "IceTower.h"

IceTower::IceTower() :Tower(ICE_COST_1, ICE_SELL_1, ICE_RANGE_1, ICE_POWER_1, ICE_RATE_1)
{
	attack_strategy = new AttackClosestToExit();
	slow_rate = ICE_SLOW_RATE_1;
	slow_duration = ICE_SLOW_DURATION_1;
}

void IceTower::upgradeTower()
{
	switch (level)
	{
	case Tower::Level_1: //If Level 1, upgrade to level 2
		Tower::setAttributes(ICE_COST_2, ICE_SELL_2, ICE_RANGE_2, ICE_POWER_2, ICE_RATE_2, Level_2);
		slow_rate = ICE_SLOW_RATE_2;
		slow_duration = ICE_SLOW_DURATION_2;
		notify();
		break;

	case Tower::Level_2:
		Tower::setAttributes(ICE_COST_3, ICE_SELL_3, ICE_RANGE_3, ICE_POWER_3, ICE_RATE_3, Level_3);
		slow_rate = ICE_SLOW_RATE_3;
		slow_duration = ICE_SLOW_DURATION_3;
		notify();
		break;
	}
}

string IceTower::getType() const
{
	return "Ice Tower";
}

int IceTower::getUpgradeCost() const
{
	if (level == Level_1) return ICE_COST_2;
	if (level == Level_2) return ICE_COST_3;
	return -1; //Means we reached max level
}

void IceTower::setStrategy(Strategy* attack_strategy)
{
	this->attack_strategy = attack_strategy;
}

Critter* IceTower::targetCritter(vector<Critter*> &critter_list)
{
	return attack_strategy->targetCritter(critter_list, this);
}

void IceTower::attackCritter(vector<Critter*> &critter_list)
{
	if (this->targetCritter(critter_list) != NULL)
	{
		this->targetCritter(critter_list)->takeDamage(power, this);
		//Will add slowing effect later

		rate_timer.reset();
	}
}

float IceTower::getSlowDuration() const
{
	return slow_duration;
}

float IceTower::getSlowRate() const
{
	return slow_rate;
}