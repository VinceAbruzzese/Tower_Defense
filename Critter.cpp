#include "Critter.h"

Critter::Critter(vector<Coordinate> path, Map* map, int level)
{
	this->level = level;
	location = 0; //starting point on path

	this->map = map;
	this->path = path;
	//Set the map and path for critter to move on path

	this->y = path.at(location).getY();
	this->x = path.at(location).getX();
	//x and y coordinates of path

	map->setValue(x, y, 2);
	//display initial critter on map

	speed_timer.start();
	//start timer for movement

	setAttributes(level);
	//set the value, strength

	//Freeze values
	frozen = false;
	initial_speed = 0;
}

Critter::~Critter()
{
	map = NULL;
}

void Critter::setAttributes(int level)
{
	switch (level)
	{
	case 1:
		value = LEVEL_1_REWARD;
		strength = LEVEL_1_STRENGTH;
		break;

	case 2:
		value = LEVEL_2_REWARD;
		strength = LEVEL_2_STRENGTH;
		break;

	case 3: //BOSS
		value = LEVEL_3_REWARD;
		strength = LEVEL_3_STRENGTH;
		break;

	case 4:
		value = LEVEL_4_REWARD;
		strength = LEVEL_5_STRENGTH;
		break;

	case 5:
		value = LEVEL_5_REWARD;
		strength = LEVEL_5_STRENGTH;
		break;

	case 6: //BOSS
		value = LEVEL_6_REWARD;
		strength = LEVEL_6_STRENGTH;
		break;

	case 7:
		value = LEVEL_7_REWARD;
		strength = LEVEL_7_STRENGTH;
		break;

	case 8:
		value = LEVEL_8_REWARD;
		strength = LEVEL_8_STRENGTH;
		break;

	case 9:
		value = LEVEL_9_REWARD;
		strength = LEVEL_9_STRENGTH;
		break;

	case 10: //BOSS
		value = LEVEL_10_REWARD;
		strength = LEVEL_10_STRENGTH;
		break;

	}
}

int Critter::getHP()
{
	return hit_points;
}

float Critter::getSpeed()
{
	return speed;
}

int Critter::getX()
{
	return x;
}

int Critter::getY()
{
	return y;
}

int Critter::getLocation()
{
	return location;
}

vector<Coordinate> Critter::getPath()
{
	return path;
}

int Critter::getValue()
{
	return value;
}

int Critter::getLevel()
{
	return level;
}

int Critter::getStrength()
{
	return strength;
}

void Critter::pauseTimer()
{
	speed_timer.stop();
}

void Critter::startTimer()
{
	speed_timer.start();
}

void Critter::removeCritter(){
	map->removeCritterFromMap(y, x);
}

void Critter::move()
{
	location++;

	//Update map:
	if (location != path.size()) //if didn't reach end, move to next path
	{
		map->updateCritterOnMap(y, x, location);
		y = path.at(location).getY();
		x = path.at(location).getX();
	}

}

void Critter::check_for_update()
{
	if (speed_timer.getTime() >= speed)
	{
		move();
		speed_timer.reset();
	}
	if (frozen)
		unfreeze_check();

}

void Critter::freeze_critter(int slow_duration, float slow_rate)
{
	frozen = true;
	this->slow_duration = slow_duration;

	if (initial_speed == 0)
		initial_speed = speed;

	if (freeze_timer.isRunning())
		freeze_timer.reset();
	else
		freeze_timer.start();

	speed = (initial_speed * slow_rate); //increase makes them slower
}

void Critter::unfreeze_check()
{
	if (freeze_timer.getTime() >= slow_duration) //if time is up
	{
		frozen = false; //set everything back to default
		speed = initial_speed;
		slow_duration = 0;
		freeze_timer.stop();
	}
}

bool Critter::getFrozen()
{
	return frozen;
}