#include "TowerDisplay.h"
#include "ArrowTower.h"
#include "IceTower.h"

void towerInfo(int cost, int power, int range, float rate, bool upgrade)
{
	if (upgrade)
		cout << "Cost of Upgrade: " << cost << endl;
	else
		cout << "Cost of Tower: " << cost << endl;

	cout << "Attack Damage: " << power << endl;
	cout << "Range: " << range << endl;
	cout << "Rate of Fire: " << rate << endl;


}

void buyInfo(int type)
{
	switch (type)
	{
		case 1:
			cout << "\nBelow are the attributes of the Arrow Tower:" << endl;
			cout << "--------------------------------------------" << endl;
			towerInfo(ARROW_COST_1, ARROW_POWER_1, ARROW_RANGE_1, ARROW_RATE_1, 0);
			cout << "Chance of Critical Strike: " << ARROW_CS_PERCENTAGE_1 * 100 << "%" << endl;
			cout << "--------------------------------------------" << endl;
			break;
		case 2:
			cout << "\nBelow are the attributes of the Fire Tower:" << endl;
			cout << "-------------------------------------------" << endl;
			towerInfo(FIRE_COST_1, FIRE_POWER_1, FIRE_RANGE_1, FIRE_RATE_1, 0);
			cout << "-------------------------------------------" << endl;
			break;
		case 3:
			cout << "\nBelow are the attributes of the Ice Tower:" << endl;
			cout << "------------------------------------------" << endl;
			towerInfo(ICE_COST_1, ICE_POWER_1, ICE_RANGE_1, ICE_RATE_1, 0);
			cout << "Slow Rate: " << ICE_SLOW_RATE_1 * 100 << "%" << endl;
			cout << "Slow Duration: " << ICE_SLOW_DURATION_1 << " seconds" << endl;
			cout << "------------------------------------------" << endl;
			break;
		default:
			cout << "You entered an invalid input..." << endl;
	}	
}

void upgradeInfo(Tower* tower)
{
	string type = tower->getType();
	string level = tower->getLevel();

	if (type == "Arrow Tower")
	{
		if (level == "Level 1")
		{
			cout << "\nBelow are the attributes of the level 2 Arrow Tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			towerInfo(ARROW_COST_2, ARROW_POWER_2, ARROW_RANGE_2, ARROW_RATE_2, 1);
			cout << "Chance of Critical Strike: " << ARROW_CS_PERCENTAGE_2 * 100 << "%" << endl;
			cout << "----------------------------------------------------" << endl;
		}
		else if (level == "Level 2")
		{
			cout << "\nBelow are the attributes of the level 3 Arrow Tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			towerInfo(ARROW_COST_3, ARROW_POWER_3, ARROW_RANGE_3, ARROW_RATE_3, 1);
			cout << "Chance of Critical Strike: " << ARROW_CS_PERCENTAGE_3 * 100 << "%" << endl;
			cout << "----------------------------------------------------" << endl;
		}
	}//end of arrow
	else if (type == "Fire Tower")
	{
		if (level == "Level 1")
		{
			cout << "\nBelow are the attributes of the level 2 Fire Tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			towerInfo(FIRE_COST_2, FIRE_POWER_2, FIRE_RANGE_2, FIRE_RATE_2, 1);
			cout << "----------------------------------------------------" << endl;
		}
		else if (level == "Level 2")
		{
			cout << "\nBelow are the attributes of the level 3 Fire Tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			towerInfo(FIRE_COST_3, FIRE_POWER_3, FIRE_RANGE_3, FIRE_RATE_3, 1);
			cout << "----------------------------------------------------" << endl;
		}
		else
			cout << "\nTower has reached its highest level..." << endl;
	}
	else if (type == "Ice Tower")
	{
		if (level == "Level 1")
		{
			cout << "\nBelow are the attributes of the level 2 Ice Tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			towerInfo(ICE_COST_2, ICE_POWER_2, ICE_RANGE_2, ICE_RATE_2, 1);
			cout << "Slow Rate: " << ICE_SLOW_RATE_2 * 100 << "%" << endl;
			cout << "Slow Duration: " << ICE_SLOW_DURATION_2 << " seconds" << endl;
			cout << "----------------------------------------------------" << endl;
		}
		else if (level == "Level 2")
		{
			cout << "\nBelow are the attributes of the level 3 Ice Tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			towerInfo(ICE_COST_3, ICE_POWER_3, ICE_RANGE_3, ICE_RATE_3, 1);
			cout << "Slow Rate: " << ICE_SLOW_RATE_3 * 100 << "%" << endl;
			cout << "Slow Duration: " << ICE_SLOW_DURATION_3 << " seconds" << endl;
			cout << "----------------------------------------------------" << endl;
		}
		else
			cout << "\nTower has reached its highest level..." << endl;
	}
}

void viewTower(Tower* tower)
{
	string lvl = tower->getLevel();
	string type = tower->getType();

	if (type == "Arrow Tower")
	{
		cout << "\nBelow are the attributes of your " << lvl << " Arrow Tower:" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Attack Damage: " << tower->getPower() << endl;
		cout << "Range: " << tower->getRange() << endl;
		cout << "Rate of Fire: " << tower->getRate() << endl;
		cout << "Chance of Critical Strike: " << dynamic_cast<ArrowTower*>(tower)->getCriticalStrike() * 100 << "%" << endl;
		cout << "----------------------------------------------------" << endl;
	}
	else if (type == "Fire Tower")
	{
		cout << "\nBelow are the attributes of your " << lvl << " Fire Tower:" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Attack Damage: " << tower->getPower() << endl;
		cout << "Range: " << tower->getRange() << endl;
		cout << "Rate of Fire: " << tower->getRate() << endl;
		cout << "----------------------------------------------------" << endl;
	}
	else if (type == "Ice Tower")
	{
		cout << "\nBelow are the attributes of your " << lvl << " Ice Tower:" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Attack Damage: " << tower->getPower() << endl;
		cout << "Range: " << tower->getRange() << endl;
		cout << "Rate of Fire: " << tower->getRate() << endl;
		cout << "Slow Rate: " << dynamic_cast<IceTower*>(tower)->getSlowRate() * 100 << "%" << endl;
		cout << "Slow Duration: " << dynamic_cast<IceTower*>(tower)->getSlowDuration() << " seconds" << endl;
		cout << "----------------------------------------------------" << endl;
	}
}