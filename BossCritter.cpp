#include "BossCritter.h"
#include "IceTower.h"

BossCritter* BossCritter::pinstance = 0; //initialize pointer

BossCritter* BossCritter::Instance(vector<Coordinate> path, Map* map, int level)
{
	if (pinstance == 0)
	{
		pinstance = new BossCritter(path, map, level);
	}
	return pinstance; //returns sole boss critter instance
}

BossCritter::BossCritter(vector<Coordinate> path, Map* map, int level) : Critter(path, map, level)
{
	//The common values are set in the 'Critter' constructor
	setAttributes(level);
}

BossCritter::~BossCritter()
{
	pinstance = 0;
}

void BossCritter::setAttributes(int level)
{
	speed = BOSS_LEVEL_SPEED;
	switch (level)
	{
	case 3:
		hit_points = BOSS_LEVEL_3_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_3;
		ice_resistance = ICE_RESISTANCE_LEVEL_3;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_3;
		break;
	case 6:
		hit_points = BOSS_LEVEL_6_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_6;
		ice_resistance = ICE_RESISTANCE_LEVEL_6;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_6;
		break;
	case 10:
		hit_points = BOSS_LEVEL_10_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_10;
		ice_resistance = ICE_RESISTANCE_LEVEL_10;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_10;
		break;
	}
}

void BossCritter::takeDamage(int damage, Tower* type)
{
	if (type->getType() == "Arrow Tower")
		hit_points -= (damage * arrow_resistance); //reduce damage by %
	else if (type->getType() == "Fire Tower")
		hit_points -= (damage * fire_resistance);
	else if (type->getType() == "Ice Tower")
	{
		hit_points -= (damage * ice_resistance);
		freeze_critter(dynamic_cast<IceTower*>(type)->getSlowDuration(), dynamic_cast<IceTower*>(type)->getSlowRate()); // freeze critter
	}
	if (hit_points <= 0)
		map->removeCritterFromMap(y, x);
}

string BossCritter::getType()
{
	return "BOSS";
}