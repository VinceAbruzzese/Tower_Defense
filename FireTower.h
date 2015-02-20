//--------------------------------------------------
//  Vince Abruzzese 
//  Class: FireTower
//--------------------------------------------------
//  The Fire Tower has an extra feature from its
//  super class which is the splash or area of 
//  effect damage. This allows the tower to damage
//  more than one critter if they are nearby
//--------------------------------------------------

#ifndef FIRE_TOWER_H
#define FIRE_TOWER_H
#include "Tower.h"

class FireTower : public Tower
{

public:
	FireTower();
	virtual ~FireTower(){}

	void upgradeTower();

	//Tower Info Methods
	string getType() const;
	int getUpgradeCost() const;

	void attackCritter(vector<Critter*> &critter_list);
	//No added attribute but will attack all critters in range
};

#endif
//End of FireTower.h