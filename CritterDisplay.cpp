#include "CritterDisplay.h"

void displayCritter(Critter* critter)
{
	string type = critter->getType();
	int hp = critter->getHP();


	if (type == "Armor Critter")
		cout << "Armored Critter ";
	else if (type == "Fire Critter")
		cout << "Fire Critter    ";
	else if (type == "Speed Critter")
		cout << "Speed Critter   ";
	else if (type == "BOSS")
		cout << "BOSS ";

	if (hp >= 100)
		cout << "HP: ";
	else if (hp < 100 && hp >= 10)
		cout << "HP:  ";
	else if (hp < 10)
		cout << "HP:   ";

	cout << hp;
	cout << " | Critter Speed: " << critter->getSpeed();
	
	if (critter->getFrozen() == true) //if frozen
		cout << " (Frozen)";
	cout << endl;
}