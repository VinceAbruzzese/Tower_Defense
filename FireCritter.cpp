#include "FireCritter.h"
#include "IceTower.h"

FireCritter::FireCritter(vector<Coordinate> path, Map* map, int level) : Critter(path, map, level)
{
	//The common values are set in the 'Critter' constructor
	setAttributes(level);
}

void FireCritter::setAttributes(int level)
{
	speed = FIRE_LEVEL_SPEED;
	switch (level)
	{
	case 1:

		hit_points = FIRE_LEVEL_1_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_1;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_1;
		break;

	case 2:

		hit_points = FIRE_LEVEL_2_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_2;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_2;
		break;

	case 4:

		hit_points = FIRE_LEVEL_4_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_4;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_4;
		break;

	case 5:

		hit_points = FIRE_LEVEL_5_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_5;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_5;
		break;

	case 7:

		hit_points = FIRE_LEVEL_7_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_7;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_7;
		break;

	case 8:

		hit_points = FIRE_LEVEL_8_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_8;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_8;
		break;

	case 9:

		hit_points = FIRE_LEVEL_9_HP;
		fire_resistance = FIRE_RESISTANCE_LEVEL_9;
		arrow_weakness = ARROW_WEAKNESS_LEVEL_9;
		break;
	}
}

void FireCritter::takeDamage(int damage, Tower* type)
{
	if (type->getType() == "Arrow Tower")
		hit_points -= (damage * (1 + arrow_weakness)); //adds % to the damage
	else if (type->getType() == "Fire Tower")
		hit_points -= (damage * fire_resistance); //reduce damage by a percentage
	else if (type->getType() == "Ice Tower")
	{
		hit_points -= damage;
		freeze_critter(dynamic_cast<IceTower*>(type)->getSlowDuration(), dynamic_cast<IceTower*>(type)->getSlowRate()); //freeze critter
	}
		
	if (hit_points <= 0)
		map->removeCritterFromMap(y, x);
}

string FireCritter::getType()
{
	return "Fire Critter";
}