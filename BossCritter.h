//----------------------------------------------------
//  Vince Abruzzese
//  Class: BossCritter
//----------------------------------------------------
//  The Boss Critter has really high hit points and 
//  takes off lives equal to their level.
//	It only spawns one boss critter. They also have
//  resistances for fire, arrow, and ice towers. 
//  They will be different depending on the round of
//  bosses. The boss critter will be a singleton 
//  pattern as we do not want more than one instance
//  of it at a time
//----------------------------------------------------

#ifndef BOSS_CRITTER_H
#define BOSS_CRITTER_H

#include "Critter.h"

class BossCritter : public Critter
{

public:
	static BossCritter* Instance(vector<Coordinate> path, Map* map, int level); //returns boss critter pointer

protected:
	BossCritter(vector<Coordinate> path, Map* map, int level);
	~BossCritter();

	string getType();

	void setAttributes(int level);

	void takeDamage(int damage, Tower* type);

private:
	float fire_resistance;
	float ice_resistance;
	float arrow_resistance;

	static BossCritter* pinstance;
};


#endif