//---------------------------------------------------------------------
//  Vince Abruzzese
//  Class: Tower
//---------------------------------------------------------------------
//  This is the main class that we will use for inheritance. Many
//  towers will have similar features. The ones mentioned in this class
//  will be used for all the other towers.
//---------------------------------------------------------------------

#ifndef TOWER_H //This will avoid duplicate includes
#define TOWER_H

class Tower;
class Map;
class Critter;
class Strategy;
//Avoid circular dependency

#include "Observable.h"
#include "Attributes.h"
#include "Timer.h"
#include "Map.h"
#include "Critter.h"
#include <iostream>
#include <string>
#include <cmath>
#include "AttackStrategy.h"

using namespace std;

class Tower : public Observable
{
public:
	//Level Enumerator
	enum Level { Level_1, Level_2, Level_3 };

	//Constructor
	Tower(int cost, int sell, int range, int power, float rate);
	virtual ~Tower();

	//Setters
	virtual void upgradeTower() = 0; //Will be used in child classes
	void setAttributes(int cost, int sell, int range, int power, float rate, Level level);
	void setX(int x);
	void setY(int y);

	//Getters
	int getCost();
	int getSell();
	int getRange();
	int getPower();
	int getX();
	int getY();
	Timer getTimer();
	int getRate();

	virtual string getType() const = 0;
	virtual int getUpgradeCost() const = 0;
	string getLevel() const;

	Strategy* getStrategy();
	void setStrategy(Strategy* attack_strategy);

	//Timer methods
	void pauseTimer();
	void startTimer();
	void resetTimer();

	virtual	void attackCritter(vector<Critter*> &critter_list) = 0;


	//Variables
protected:
	int cost;
	int sell;
	int range;
	int power;
	float rate;
	int x;
	int y;
	Level level;
	Timer rate_timer;
	Strategy* attack_strategy;
	//Inherits Observers** observers, int number_of_observers
};

#endif
//End of Tower.h