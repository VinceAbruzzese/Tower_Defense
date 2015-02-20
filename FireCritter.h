//----------------------------------------------------
//  Vince Abruzzese 
//  Class: FireCritter
//----------------------------------------------------
//  The Fire Critter has a very strong resistance to
//  Fire towers but a weakness to arrow towers
//----------------------------------------------------

#ifndef FIRE_CRITTER_H
#define FIRE_CRITTER_H

#include "Critter.h"

class FireCritter : public Critter
{

public:
	FireCritter(vector<Coordinate> path, Map* map, int level);

	string getType();

	void setAttributes(int level);

	void takeDamage(int damage, Tower* type);

private:
	float fire_resistance;
	float arrow_weakness;
};



#endif