//----------------------------------------------
//  Vince Abruzzese 
//  Class: Session
//----------------------------------------------
//  The Session class contains all the needed
//  variables for the user to play the game.
//  This includes the cost, amount of lives, etc
//----------------------------------------------

#ifndef SESSION_H
#define SESSION_H

#include "Attributes.h"
#include <iostream>
using namespace std;

class Session
{
public:
	Session();

	//Mutators
	void buy(int cost);
	void sell(int sell);
	void reward(int value);
	void loseGold(int value);
	void loseLife();
	void nextRound();

	//Getters
	int getGold() const;
	int getLives() const;
	int getRound() const;

private:
	int lives;
	int gold;
	int round;
};

#endif
//End of Session.h