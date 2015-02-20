//----------------------------------------------------
//  Vince Abruzzese 
//  Class: ArrowTower
//----------------------------------------------------
//  The Arrow Tower is different to other towers as it 
//  has an extra function critical strike which allows
//  it to do double the damage. It also has more range
//  compared to other towers
//----------------------------------------------------

#ifndef ARROW_TOWER_H
#define ARROW_TOWER_H

#include "Tower.h"

class ArrowTower : public Tower
{

public:
	ArrowTower();
	virtual ~ArrowTower(){}

	void upgradeTower();

	//Tower Info Methods:
	string getType() const;
	int getUpgradeCost() const;

	float getCriticalStrike();

	//attack methods
	void setStrategy(Strategy* attack_strategy);
	Critter* targetCritter(vector<Critter*> &critter_list);
	void attackCritter(vector<Critter*> &critter_list);

private:
	float critical_strike;

};

#endif