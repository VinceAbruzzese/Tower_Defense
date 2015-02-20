//------------------------------------------
//  Vince Abruzzese 
//  Class: IceTower
//------------------------------------------
//  The Ice Tower has the slow feature. The
//  tower will decrease the speed of the 
//  critters allowing other towers to get
//  more attacks in
//------------------------------------------

#ifndef ICE_TOWER_H
#define ICE_TOWER_H

#include "Tower.h"

class IceTower : public Tower
{

public:
	IceTower();
	virtual ~IceTower(){}

	void upgradeTower();

	//Tower Info Methods
	string getType() const;
	int getUpgradeCost() const;
	float getSlowDuration() const;
	float getSlowRate() const;

	Strategy* getStrategy();

	void setStrategy(Strategy* attack_strategy);
	Critter* targetCritter(vector<Critter*> &critter_list);
	void attackCritter(vector<Critter*> &critter_list);

private:
	float slow_rate;
	float slow_duration;
};

#endif
//IceTower.h