//---------------------------------------------------------------------
//  Vince Abruzzese
//---------------------------------------------------------------------
//  Class: Strategy
//---------------------------------------------------------------------
//  We will use the strategy design pattern to determine which attack 
//  method we will be using. We will have three derived strategies at the 
//  moment: AttackWeakest, AttackNearest, AttackClosestToExit
//---------------------------------------------------------------------

#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "Critter.h"
#include "Tower.h"

class Strategy
{
public:
	virtual Critter* targetCritter(vector<Critter*> &critter_list, Tower* tower) = 0;
	/*
	* This method will be used by the towers. It will
	* determine which critter to attack based on the
	* strategy set to that tower and then deal damage
	* do the critter depending on the towers power
	*/

	virtual string get_strategy_string() = 0;
	//We will use in the game to determine the type of strategy we have
};

#endif STRATEGY_H