//----------------------------------------------------
//  Vince Abruzzese 
//  Class: SpeedCritter
//----------------------------------------------------
//  The Speed Critter increases its speed when it has
//  half the hit points left.
//----------------------------------------------------

#ifndef SPEED_CRITTER_H
#define SPEED_CRITTER_H

#include "Critter.h"

class SpeedCritter : public Critter
{

public:
	SpeedCritter(vector<Coordinate> path, Map* map, int level);

	string getType();

	void setAttributes(int level);

	void takeDamage(int damage, Tower* type);

private:
	int starting_hit_points; //keep track of starting HP
	bool speed_up;
};



#endif