//---------------------------------------------------------------------
//  Vince Abruzzese 
//  Class: Critter
//---------------------------------------------------------------------
// The critter class will contain several different variables and 
// for the monsters in the game. It will keep track of the map and path
// as well as HP, speed, x and y location, strength, levels, etc.
//---------------------------------------------------------------------

#ifndef CRITTER_H
#define CRITTER_H

#include "Attributes.h"
#include "Map.h"
#include "Observable.h"

class Critter
{
public:
	Critter(vector<Coordinate> path, Map* map, int level);
	virtual ~Critter();

	//Getters
	int getHP();
	float getSpeed();
	int getX();
	int getY();
	int getLocation();
	vector<Coordinate> getPath();
	int getValue();
	int getLevel();
	int getStrength();
	virtual string getType() = 0;

	//Timer methods
	void pauseTimer();
	void startTimer();

	//Set attributes based on lvl (used in constructor)
	void setAttributes(int level);

	//Take damage from tower
	virtual void takeDamage(int damage, Tower* type) = 0;
	void removeCritter();

	//Movement
	void move();
	void check_for_update();

	//Freeze methods
	void freeze_critter(int slow_duration, float slow_rate);
	void unfreeze_check();
	bool getFrozen();


protected:
	int hit_points;
	float speed;
	int x;
	int y;
	int location; //location on path
	int value; //gold value when killed
	int level;
	int strength;
	vector<Coordinate> path; //keep track of path
	Map* map; //used to update display
	Timer speed_timer;

	//freeze
	bool frozen;
	int slow_duration;
	float initial_speed;
	Timer freeze_timer;
};

#endif
//End of Critter.h