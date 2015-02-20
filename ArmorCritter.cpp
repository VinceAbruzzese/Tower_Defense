#include "ArmorCritter.h"
#include "IceTower.h"

ArmorCritter::ArmorCritter(vector<Coordinate> path, Map* map, int level) : Critter(path, map, level)
{
	//The common values are set in the 'Critter' constructor
	setAttributes(level);
}

void ArmorCritter::setAttributes(int level)
{
	speed = ARMOR_LEVEL_SPEED;
	switch (level)
	{
	case 1:

		hit_points = ARMOR_LEVEL_1_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_1;
		break;

	case 2:

		hit_points = ARMOR_LEVEL_2_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_2;
		break;

	case 4:

		hit_points = ARMOR_LEVEL_4_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_4;
		break;

	case 5:

		hit_points = ARMOR_LEVEL_5_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_5;
		break;

	case 7:

		hit_points = ARMOR_LEVEL_7_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_7;
		break;

	case 8:

		hit_points = ARMOR_LEVEL_8_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_8;
		break;

	case 9:

		hit_points = ARMOR_LEVEL_9_HP;
		arrow_resistance = ARROW_RESISTANCE_LEVEL_9;
		break;
	}
}

void ArmorCritter::takeDamage(int damage, Tower* type)
{
	if (type->getType() == "Arrow Tower")
		hit_points -= (damage * arrow_resistance); //reduce damage by %
	else if (type->getType() == "Ice Tower")
	{
		hit_points -= damage;
		freeze_critter(dynamic_cast<IceTower*>(type)->getSlowDuration(), dynamic_cast<IceTower*>(type)->getSlowRate()); // freeze critter
	}
	else 
		hit_points -= damage; //no special effects

	if (hit_points <= 0)
		map->removeCritterFromMap(y, x);
}

string ArmorCritter::getType()
{
	return "Armor Critter";
}