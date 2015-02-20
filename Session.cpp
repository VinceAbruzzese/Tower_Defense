#include "Session.h"

Session::Session()
{
	lives = NUMBER_OF_LIVES;
	gold = STARTING_GOLD;
	round = 1;
}

void Session::buy(int cost) { gold -= cost; }

void Session::sell(int sell) { gold += sell; }

void Session::reward(int value) { gold += value; }

void Session::loseLife() { lives--; }

void Session::loseGold(int value){ gold -= value; }

void Session::nextRound() { round++; }

int Session::getGold() const { return gold; }

int Session::getLives() const { return lives; }

int Session::getRound() const { return round; }


