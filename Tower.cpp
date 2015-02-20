#include "Tower.h"

Tower::Tower(int cost, int sell, int range, int power, float rate)
{
	this->cost = cost;
	this->sell = sell;
	this->range = range;
	this->power = power;
	this->rate = rate;
	level = Level_1;
	rate_timer.start();

	this->x = 0;
	this->y = 0;
}

Tower::~Tower()
{
	delete attack_strategy;
}

void Tower::setAttributes(int cost, int sell, int range, int power, float rate, Level level)
{
	this->cost = cost;
	this->sell = sell;
	this->range = range;
	this->power = power;
	this->rate = rate;
	this->level = level;
}

void Tower::setX(int x)
{
	this->x = x;
}

void Tower::setY(int y)
{
	this->y = y;
}

int Tower::getCost() 
{ 
	return cost; 
}

int Tower::getSell()
{
	return sell; 
}

int Tower::getRange()
{
	return range;
}

int Tower::getPower()
{
	return power;
}

int Tower::getX()
{
	return x;
}

int Tower::getY()
{
	return y;
}

Timer Tower::getTimer()
{
	return rate_timer;
}

int Tower::getRate()
{
	return rate;
}

string Tower::getLevel() const
{
	if (level == Level_1) return "Level 1";
	if (level == Level_2) return "Level 2";
	if (level == Level_3) return "Level 3";
	return "";
}

Strategy* Tower::getStrategy()
{
	return attack_strategy;
}

void Tower::setStrategy(Strategy* attack_strategy)
{
	this->attack_strategy = attack_strategy;
}

void Tower::pauseTimer()
{
	rate_timer.stop();
}

void Tower::startTimer()
{
	rate_timer.start();
}

void Tower::resetTimer()
{
	rate_timer.reset();
}


