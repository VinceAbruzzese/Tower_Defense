//----------------------------------------------------
//  Vince Abruzzese 
//  Class: ArmorCritter
//----------------------------------------------------
//  The Armor Critter is a really slow critter but has
//  higher hit points and resistance to arrow towers.
//----------------------------------------------------

#ifndef ARMOR_CRITTER_H
#define ARMOR_CRITTER_H

#include "Critter.h"

class ArmorCritter : public Critter
{

public:
	ArmorCritter(vector<Coordinate> path, Map* map, int level);

	string getType();

	void setAttributes(int level);

	void takeDamage(int damage, Tower* type);

private:
	float arrow_resistance;

};


#endif