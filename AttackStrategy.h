//---------------------------------------------------------------------
//  Vince Abruzzese
//---------------------------------------------------------------------
//  Classes:
//  AttackWeakest
//  AttackNearest
//  AttackClosestToExit
//  AttackStrongest
//---------------------------------------------------------------------

#ifndef ATTACK_STRATEGY_H
#define ATTACK_STRATEGY_H

#include "Strategy.h"

class AttackWeakest : public Strategy
{
public:
	Critter* targetCritter(vector<Critter*> &critter_list, Tower* tower);
	/*
	* The AttackWeakest strategy will be designed in such a way that
	* it will loop through the critter list and first find the ones
	* in range. Once found it will attack the critter depending on
	* what strategy is assigned to that tower
	*/

	string get_strategy_string(){ return "Attack Weakest Critter"; }
};

class AttackNearest : public Strategy
{
public:
	Critter* targetCritter(vector<Critter*> &critter_list, Tower* tower);
	/*
	* The AttackNearest strategy will be designed to go through
	* the critter list and find the ones nearest in range. If there
	* are two in the same range, it will attack the one closest to
	* exit
	*/

	string get_strategy_string(){ return "Attack Nearest Critter"; }
};

class AttackClosestToExit : public Strategy
{
public:
	Critter* targetCritter(vector<Critter*> &critter_list, Tower* tower);
	/*
	* The AttackClosestToExit strategy is the one that will be
	* assigned to the Tower by default. It will work by selecting
	* the first critter in the list that is in range.
	*/

	string get_strategy_string(){ return "Attack Closest Critter to Exit"; }
};

class AttackStrongest : public Strategy
{
public:
	Critter* targetCritter(vector<Critter*> &critter_list, Tower* tower);
	/*
	* The AttackStrongest strategy keeps track of the critters in range
	* and the one with the most HP will get attacked. IF there are two
	* that are the highest, it will attack closest to exit
	*/

	string get_strategy_string(){ return "Attack Strongest Critter"; }
};

#endif