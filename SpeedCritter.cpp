#include "SpeedCritter.h"
#include "IceTower.h"

SpeedCritter::SpeedCritter(vector<Coordinate> path, Map* map, int level) : Critter(path, map, level)
{
	//The common values are set in the 'Critter' constructor
	speed_up = false;
	setAttributes(level);
}

void SpeedCritter::setAttributes(int level)
{
	speed = SPEED_LEVEL_SPEED;
	initial_speed = SPEED_LEVEL_SPEED;
	switch (level)
	{
	case 1:

		hit_points = SPEED_LEVEL_1_HP;
		starting_hit_points = SPEED_LEVEL_1_HP;
		break;

	case 2:

		hit_points = SPEED_LEVEL_2_HP;
		starting_hit_points = SPEED_LEVEL_2_HP;
		break;

	case 4:

		hit_points = SPEED_LEVEL_4_HP;
		starting_hit_points = SPEED_LEVEL_4_HP;
		break;

	case 5:

		hit_points = SPEED_LEVEL_5_HP;
		starting_hit_points = SPEED_LEVEL_5_HP;
		break;

	case 7:

		hit_points = SPEED_LEVEL_7_HP;
		starting_hit_points = SPEED_LEVEL_7_HP;
		break;

	case 8:

		hit_points = SPEED_LEVEL_8_HP;
		starting_hit_points = SPEED_LEVEL_8_HP;
		break;

	case 9:

		hit_points = SPEED_LEVEL_9_HP;
		starting_hit_points = SPEED_LEVEL_9_HP;
		break;
	}
}

void SpeedCritter::takeDamage(int damage, Tower* type) //Tower not needed but using for polymorphism
{
	if (type->getType() == "Ice Tower")
	{
		hit_points -= damage;
		freeze_critter(dynamic_cast<IceTower*>(type)->getSlowDuration(), dynamic_cast<IceTower*>(type)->getSlowRate()); // freeze critter
	}
	else 
		hit_points -= damage;

	if (hit_points <= 0)
		map->removeCritterFromMap(y, x);
	else if (hit_points <= (starting_hit_points / 2)) //if less than or equal half
	{
		if (speed_up == false) //check so only speeds up once (must be not frozen as well)
		{
			if (speed != initial_speed) //frozen (removes the frozen)
			{
				frozen = false;
				speed = initial_speed;
				slow_duration = 0;
				freeze_timer.stop();
			}
			else
			{
				speed_up = true;
				speed = (speed / 2); //changes speed to double as fast (removes frozen)
			}
		}
	}
}


string SpeedCritter::getType()
{
	return "Speed Critter";
}