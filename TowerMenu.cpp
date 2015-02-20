#include "TowerMenu.h"
#include "TowerDisplay.h"

/////////////////////////////////////////////////////////////////////
//  Tower Menu Methods
/////////////////////////////////////////////////////////////////////

//This method will return to us what action we are going to take. For example
//returning 1 is the "Buy New Tower" option. In the main we have a switch 
//statement that will execute this option.
int action(Session &session, string type, ErrorHandling* &errorObj)
{
	int action;
	string actionStr;

	bool actionInput = false;

	while (!actionInput)
	{
		cout << "\nThe following options are listed below:" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Buy New Tower (1)" << endl;
		cout << "Sell Existing Tower (2)" << endl;
		cout << "Upgrade Existing Tower (3)" << endl;
		cout << "View Existing Towers (4)" << endl;
		cout << "Change Attack Strategy (5)" << endl;
		if (type == "START")
			cout << "Start Next Round (6)" << endl;
		else if (type == "PAUSE") //display one of the other depending on pause or start
			cout << "Resume Game (6)" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "\nPlease enter the action you would like to take: ";

		cin >> actionStr;

		try
		{
			errorObj->testIntStringInput(actionStr, 1, 6);
			actionInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl << endl;
		}
	}


	system("CLS"); //clear the screen
	display_session(session);

	action = atoi(actionStr.c_str());

	return action;
}

/////////////////////////////////////////////////////////////////////
//  Buy Methods
/////////////////////////////////////////////////////////////////////

//buy_option will return and int from 0-3. If 0 means we aren't buying anything. If
//it is 1, 2, or 3 we are buying ArrowTower, FireTower, IceTower respectively
int buy_option(Session &session, ErrorHandling* &errorObj)
{
	int type;
	string typeStr;

	bool buyInput = false;

	while (!buyInput)
	{
		cout << "\nYou have selected the \"Buy New Tower\" option:" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Buy Arrow Tower (1) -- Price: " << ARROW_COST_1 << " gold" << endl;
		cout << "Buy Fire Tower (2)  -- Price: " << FIRE_COST_1 << " gold" << endl;
		cout << "Buy Ice Tower (3)   -- Price: " << ICE_COST_1 << " gold" << endl;
		cout << "Get Tower Info (4)" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "\nPlease enter the action you would like to take: ";
		cin >> typeStr;

		try
		{
			errorObj->testIntStringInput(typeStr, 1, 4);
			buyInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl << endl;
		}

	}

	system("CLS");
	display_session(session);

	type = atoi(typeStr.c_str());

	if (type == 1 || type == 2 || type == 3)
	{
		if (get_confirmation(type, session, "buy", errorObj)) //If user confirms return the type of tower
			return (type);
		else
			return 0; //This will cancel the request
	}
	else if (type == 4)
	{
		system("CLS");
		display_session(session);
		return get_tower_info(session, errorObj);
	}

	system("CLS");
	display_session(session);
}

//The buy_tower method will be used to returned the new list after we buy
//our tower. It will check through a switch statement which tower was requested
//Once that is checked, it will return the new list with the added tower
//If we can't afford. Sends back same list and is handled in the main
void buy_tower(int type, vector<Tower*> &tower_list, Session &session)
{
	Tower* temp = NULL;

	switch (type)
	{
	case 1: //User selects Arrow Tower
	{
		if (session.getGold() >= ARROW_COST_1)
		{
			temp = new ArrowTower();
			break;
		}
	}
	case 2: //User selects Fire Tower
	{
		if (session.getGold() >= FIRE_COST_1)
		{
			temp = new FireTower();
			break;
		}
	}
	case 3: //User selects Ice Tower
	{
		if (session.getGold() >= ICE_COST_1)
		{
			temp = new IceTower();
			break;
		}
	}
	}//end of switch
	if (temp != NULL)
		tower_list.push_back(temp); //If NULL, we can't afford so list doesn't change
}

bool display_buy_message(int type, int &list_size, vector<Tower*> &tower_list, Session &session)
{
	//check if list grew
	if (tower_list.size() == list_size)
	{
		cout << "\nYou don't have enough gold!" << endl;
		cout << "Transaction has been cancelled.\n" << endl;
		system("PAUSE");
		system("CLS");
		display_session(session);
		return false;
	}
	else
	{
		session.buy(tower_list.back()->getCost()); //Decrease the gold
		string tower = get_tower_type(type);
		cout << "\nYou have bought the " << tower << "." << endl << endl;
		list_size++;
		system("PAUSE");
		system("CLS");
		display_session(session);
		return true;
	}
}

/////////////////////////////////////////////////////////////////////
//  Sell Methods
/////////////////////////////////////////////////////////////////////

int sell_option(int list_size, vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj)
{

	if (tower_list.size() == 0)
	{
		cout << "You don't have any towers to sell!\n" << endl;
		system("PAUSE");
		system("CLS");
		display_session(session);
		return -1;   //return that we don't have any towers
	}
	else
	{
		int selling_index;
		string selling_index_str;

		bool sellTowerInput = false;

		while (!sellTowerInput)
		{
			display_tower_list(tower_list, "sell");

			cout << "\nPlease enter the tower number to sell (0 to cancel): ";
			cin >> selling_index_str;

			try
			{
				errorObj->testTowerChoosingOption(selling_index_str, list_size);
				sellTowerInput = true;
			}
			catch (string e)
			{
				system("CLS");
				cout << endl << e << endl << endl;
			}

		}

		selling_index = atoi(selling_index_str.c_str());

		if (selling_index != 0)
		{
			system("CLS");
			display_session(session);
			if (!get_confirmation(1, session, "sell", errorObj))
				selling_index = 0; //to cancel request
		}
		
		if (selling_index == 0)
		{
			system("CLS");
			display_session(session);
			cout << "\nYou have cancelled your request" << endl;
			system("PAUSE");
			system("CLS");
			display_session(session);
			return -1; //tell the main to break
		}
		else
		{
			return selling_index;
		}
	}
}

void sell_tower(int selling_index, vector<Tower*> &tower_list)
{
	Tower* temp = tower_list.at(selling_index - 1);
	tower_list.erase(tower_list.begin() + selling_index - 1);
	delete temp;
	temp = NULL;
	//return tower_list;
}

void sell_message(int selling_index, vector<Tower*> &tower_list, Session &session)
{
	system("CLS");
	display_session(session);
	cout << "\nYou have sold the following tower:\n";
	cout << "----------------------------------------------------" << endl;
	cout << tower_list.at(selling_index - 1)->getType() << " "
		<< tower_list.at(selling_index - 1)->getLevel() << " "
		<< "at index (" << selling_index << ")." << endl;
	cout << "----------------------------------------------------\n" << endl;
	system("PAUSE");
	system("CLS");
}

/////////////////////////////////////////////////////////////////////
//  Upgrade Methods
/////////////////////////////////////////////////////////////////////

int upgrade_option(int list_size, vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj)
{

	if (tower_list.size() == 0)
	{
		cout << "You don't have any towers to upgrade!" << endl << endl;
		system("PAUSE");
		system("CLS");
		display_session(session);
		return -1;
	}
	else
	{
		int upgrading_index;
		string upgrading_index_str;

		bool upgradeTowerInput = false;

		while (!upgradeTowerInput)
		{
			display_tower_list(tower_list, "upgrade");

			cout << "\nPlease enter the tower number to upgrade (0 to cancel): ";
			cin >> upgrading_index_str;

			try
			{
				errorObj->testTowerChoosingOption(upgrading_index_str, list_size);
				upgradeTowerInput = true;
			}
			catch (string e)
			{
				system("CLS");
				cout << endl << e << endl << endl;
			}

		}

		upgrading_index = atoi(upgrading_index_str.c_str());

		system("CLS");
		display_session(session);

		if (upgrading_index != 0)
		{
			system("CLS");
			display_session(session);
			upgradeInfo(tower_list.at(upgrading_index - 1)); //display info of the upgrade
			if (!get_confirmation(1, session, "upgrade", errorObj))
				upgrading_index = 0; //to cancel request
		}

		if (upgrading_index == 0)
		{
			cout << "You have cancelled your request.\n" << endl;
			system("PAUSE");
			system("CLS");
			display_session(session);
			return -1;
		}
		else
		{
			if (tower_list.at(upgrading_index - 1)->getLevel() == "Level 3")
			{
				system("CLS");
				display_session(session);
				cout << "\nThis tower is at its max level. You can't upgrade it." << endl;
				cout << "Transaction has been cancelled.\n" << endl;
				system("PAUSE");
				system("CLS");
				display_session(session);
				return -1;
			}//check if it can be upgraded
			return upgrading_index;
		}
	}
}

void upgrade_tower(int upgrading_index, vector<Tower*> &tower_list, Session &session)
{
	cout << "\nYour tower has been upgraded!" << endl;
	tower_list.at(upgrading_index - 1)->upgradeTower(); //upgrade tower
	viewTower(tower_list.at(upgrading_index - 1)); //print out tower

	cout << endl;
	system("PAUSE");
	system("CLS");
	display_session(session);
	//return tower_list;
}

/////////////////////////////////////////////////////////////////////
//  Information Methods
/////////////////////////////////////////////////////////////////////

//If the user wants more information on the tower, they will select the 
//"Get Tower Info" option. This will call this method and this method will
//return 0-3, depending on if user buys tower or not
int get_tower_info(Session &session, ErrorHandling* &errorObj)
{
	int type;
	string typeStr;

	bool towerInfoInput = false;

	while (!towerInfoInput)
	{
		cout << "\nYou have selected the \"Get Tower Info\" option:" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Arrow Tower (1)\nFire Tower (2)\nIce Tower (3)" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Please enter the tower you would like to see: ";
		cin >> typeStr;

		try
		{
			errorObj->testIntStringInput(typeStr, 0, 3);
			towerInfoInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl << endl;
		}

		system("CLS");
		display_session(session);
	}

	type = atoi(typeStr.c_str());

	if (type == 0)
		return 0; //cancels request

	buyInfo(type);

	if (get_confirmation(type, session, "buy", errorObj)) //If user confirms return the type of tower
		return (type);
	else
		return 0; //This will cancel the request
}

//Simply returns a string of which tower we have. Used repetitively
string get_tower_type(int type)
{
	string tower;

	if (type == 1) tower = "Arrow Tower";
	if (type == 2) tower = "Fire Tower";
	if (type == 3) tower = "Ice Tower";

	return tower;
}

//This method is for the sell/upgrade/display option. We want to display all the contents of the
//vector list.
void display_tower_list(vector<Tower*> &tower_list, string type)
{
	cout << "\nBelow is the information of your towers:" << endl;
	cout << "--------------------------------------------------------------" << endl;

	for (int i = 0; i < tower_list.size(); i++)
	{
		cout << "Tower " << i + 1 << ": " << tower_list.at(i)->getType();
		cout << " " << tower_list.at(i)->getLevel();

		if (type == "sell")
			cout << " -- Sell Value: " << tower_list.at(i)->getSell() << endl;
		else if (type == "upgrade")
		{
			if (tower_list.at(i)->getLevel() != "Level 3")
				cout << " -- Upgrade Cost: " << tower_list.at(i)->getUpgradeCost() << endl;
			else
				cout << " -- Max Level" << endl;
		}
		else if (type == "strategy")
		{
			if (tower_list.at(i)->getType() == "Fire Tower")
				cout << " -- Cannot Modify" << endl;
			else
				cout << " -- " << tower_list.at(i)->getStrategy()->get_strategy_string() << endl;
		}
		else if (type == "display")
			cout << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
}

int display_option(vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj)
{

	if (tower_list.size() == 0)
	{
		cout << "You don't have any towers to display!" << endl << endl;
		system("PAUSE");
		system("CLS");
		display_session(session);
		return -1;
	}
	else
	{
		int index;
		string index_str;

		int list_size = tower_list.size();

		bool listTowerInput = false;

		while (!listTowerInput)
		{
			cout << "\nYou selected the \"View Existing Towers\" option" << endl;
			display_tower_list(tower_list, "display");

			cout << "Enter the index to view the information of this tower (0 to cancel):";
			cin >> index_str;

			try
			{
				errorObj->testTowerChoosingOption(index_str, list_size);
				listTowerInput = true;
			}
			catch (string e)
			{
				system("CLS");
				cout << endl << e << endl << endl;
			}

		}

		index = atoi(index_str.c_str());

		if (index == 0)
		{
			cout << "You have cancelled your request";
			system("CLS");
			display_session(session);
			return -1;
		}
		else
		{
			system("CLS");
			display_session(session);
			viewTower(tower_list.at(index - 1));
			cout << endl;
			system("PAUSE");
			system("CLS");
			display_session(session);
			return -1;
		}

	}
}

void attack_strategy_option(vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj)
{
	if (tower_list.size() == 0)
	{
		cout << "You don't have any towers to display!" << endl << endl;
		system("PAUSE");
		system("CLS");
		display_session(session);
	}
	else
	{

		int index;
		string index_str;

		int list_size = tower_list.size();

		bool listStrategyInput = false;

		while (!listStrategyInput)
		{
			cout << "\nYou selected the \"Change Tower Strategy\" option" << endl;
			display_tower_list(tower_list, "strategy");
			cout << "Enter the index of the tower you would like to modify (0 to cancel):";
			cin >> index_str;

			try
			{
				errorObj->testTowerChoosingOption(index_str, list_size);
				listStrategyInput = true;
			}
			catch (string e)
			{
				system("CLS");
				cout << endl << e << endl << endl;
			}

		}

		index = atoi(index_str.c_str());

		if (index == 0)
		{
			system("CLS");
			display_session(session);
			cout << "You have cancelled your request!" << endl;
			system("PAUSE");
			system("CLS");
			display_session(session);
			return;
		}
		else if (tower_list.at(index - 1)->getType() == "Fire Tower")
		{
			system("CLS");
			display_session(session);
			cout << "You cannot modify this tower!" << endl;
		}
		else
		{
			system("CLS");
			display_session(session);
			cout << "\nYou have selected the following tower:" << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "Tower " << index << ": ";
			cout << tower_list.at(index - 1)->getType() << ": ";
			cout << tower_list.at(index - 1)->getStrategy()->get_strategy_string();
			tower_list.at(index - 1)->getStrategy();
			cout << endl;

			int strategy;
			string strategy_str;

			bool listStrategyNumInput = false;

			while (!listStrategyNumInput)
			{
				cout << "\nBelow are the different strategies for this Tower:" << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "(1) Attack Closest Critter to Exit";
				if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Closest Critter to Exit") cout << " (Current Strategy)";
				cout << "\n(2) Attack Nearest Enemy Critter";
				if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Nearest Critter") cout << " (Current Strategy)";
				cout << "\n(3) Attack Weakest Enemy Critter";
				if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Weakest Critter") cout << " (Current Strategy)";
				cout << "\n(4) Attack Strongest Critter";
				if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Strongest Critter") cout << " (Current Strategy)";
				cout << "\n----------------------------------------------------" << endl;
				cout << "Which Strategy would you like to use (0 to cancel): ";
				cin >> strategy_str;

				try
				{
					errorObj->testIntStringInput(strategy_str, 0, 4);
					listStrategyNumInput = true;
				}
				catch (string e)
				{
					system("CLS");
					cout << endl << e << endl << endl;
				}

			}

			strategy = atoi(strategy_str.c_str());

			if (strategy == 0)
			{
				system("CLS");
				display_session(session);
				cout << "\nYou have cancelled your request." << endl;
			}
			else
			{
				switch (strategy)
				{
				case 1:
					if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Closest Critter to Exit")
					{
						system("CLS");
						display_session(session);
						cout << "This is already your current strategy!" << endl;
					}
					else
					{
						tower_list.at(index - 1)->setStrategy(new AttackClosestToExit());
						system("CLS");
						display_session(session);
						cout << "\nThe strategy for this tower has been changed!" << endl;
					}
					break;
				case 2:
					if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Nearest Critter")
					{
						system("CLS");
						display_session(session);
						cout << "This is already your current strategy!" << endl;
					}
					else
					{
						system("CLS");
						display_session(session);
						tower_list.at(index - 1)->setStrategy(new AttackNearest());
						cout << "\nThe strategy for this tower has been changed!" << endl;
					}
					break;
				case 3:
					if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Weakest Critter")
					{
						system("CLS");
						display_session(session);
						cout << "This is already your current strategy!" << endl;
					}
					else
					{
						system("CLS");
						display_session(session);
						tower_list.at(index - 1)->setStrategy(new AttackWeakest());
						cout << "\nThe strategy for this tower has been changed!" << endl;
					}
					break;
				case 4:
					if (tower_list.at(index - 1)->getStrategy()->get_strategy_string() == "Attack Strongest Critter")
					{
						system("CLS");
						display_session(session);
						cout << "This is already your current strategy!" << endl;
					}
					else
					{
						system("CLS");
						display_session(session);
						tower_list.at(index - 1)->setStrategy(new AttackStrongest());
						cout << "\nThe strategy for this tower has been changed!" << endl;
					}
				}
			}
		}
		cout << endl;
		system("PAUSE");
		system("CLS");
		display_session(session);
	}

}

/////////////////////////////////////////////////////////////////////
//   Other
/////////////////////////////////////////////////////////////////////

//The get_confirmation method will be used to confirm with the user
//whether or not they want to buy the tower. Returns true or false
bool get_confirmation(int type, Session &session, string option, ErrorHandling* &errorObj)
{
	string confirmation;
	string tower = get_tower_type(type);

	bool confirmationInput = false;

	while (!confirmationInput)
	{
		if (option == "buy")
			cout << "\nWould you like to buy the " << tower << "? (y/n): ";
		if (option == "sell")
			cout << "\nWould you like to sell this tower ? (y/n): ";
		if (option == "upgrade")
			cout << "\nWould you like to upgrade this tower? (y/n): ";

		cin >> confirmation;

		try
		{
			errorObj->testYesNo(confirmation);
			confirmationInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl << endl;
		}


	}

	system("CLS");
	display_session(session);

	if (confirmation == "y") return true;
	else if (confirmation == "n") return false;

}

//This method will display values of the session at all times. Such as gold,
//lives, etc.
void display_session(Session &session)
{
	cout << "\n----------------------------------------------------" << endl;
	cout << "Gold: " << session.getGold() << "\nLives: " << session.getLives() << endl;
	cout << "Round: " << session.getRound() << endl;
	cout << "----------------------------------------------------" << endl;
}

void print_tower_list(vector<Tower*> &tower_list)
{
	for (int i = 0; i < tower_list.size(); i++)
	{
		if (tower_list.at(i)->getType() == "Arrow Tower")
			cout << "A ";
		if (tower_list.at(i)->getType() == "Fire Tower")
			cout << "F ";
		if (tower_list.at(i)->getType() == "Ice Tower")
			cout << "I ";
	}
}

//The tower_menu method is the method we will use in the main for buying, selling, upgrading,
//or simply viewing the towers information. This method implements all the methods above.
//For each new round. This menu will be called again to add/remove/upgrade your towers
void tower_menu(Session &session, vector<Tower*> &tower_list, int &list_size, bool &start, Map* map, string type, ErrorHandling* &errorObj)
{
	while (!start)
	{
		switch (action(session, type, errorObj)) //Determine which action to take
		{
			//Buy New Tower option (case 1)
		case 1:
		{
			int type = buy_option(session, errorObj);

			if (type) //will evaluate to true if 1,2,3 (false if 0)
			{
				buy_tower(type, tower_list, session); //Updates the list
				if (display_buy_message(type, list_size, tower_list, session)){ //Display bought/can't afford
					map->addTowerToMap(tower_list.back(),errorObj); //adds the tower to the view
					//Index
				};
			}
			else //We get 0 and request is cancelled
			{
				cout << "\nYou have cancelled your request.\n" << endl;
				system("PAUSE");
				system("CLS");
				display_session(session);
			}
			break;
		}
			//Sell Existing Tower option (case 2)
		case 2:
		{
			int selling_index = sell_option(list_size, tower_list, session, errorObj);

			if (selling_index == -1)
				break; //either we have no towers or cancelled request (given from sell_option)
			else
			{
				session.sell(tower_list.at(selling_index - 1)->getSell()); //increase gold
				sell_message(selling_index, tower_list, session);
				map->removeTowerFromMap(tower_list.at(selling_index - 1)); //remove from view

				sell_tower(selling_index, tower_list); //get new list
				list_size--;

				system("PAUSE");
				system("CLS");
				display_session(session);

			}
			break;
		}
			//Upgrade Existing Tower option (case 3)
		case 3:
		{
			int upgrading_index = upgrade_option(list_size, tower_list, session, errorObj);

			if (upgrading_index == -1) //either there are no towers, or user cancelled request
				break;

			if (session.getGold() >= tower_list.at(upgrading_index - 1)->getUpgradeCost())
				session.buy(tower_list.at(upgrading_index - 1)->getUpgradeCost());
			//if you can afford. decrease the gold
			else //or else cancel request
			{
				cout << "You don't have enough gold." << endl;
				cout << "Transaction has been cancelled.\n" << endl;
				system("PAUSE");
				system("CLS");
				display_session(session);
				break;
			}

			upgrade_tower(upgrading_index, tower_list, session); //Tower is upgraded here
			break;
		}
			//View Existing Towers option (case 4)
		case 4:
		{
			display_option(tower_list, session, errorObj);
			break;
		}
			//Change Attack Strategy option (case 5)
		case 5:
		{
			attack_strategy_option(tower_list, session, errorObj);
			break;
		}
			//Start Next Round option (case 6)
		case 6:
		{
			start = true; //Will break out of while loop
			break;
		}
		default:
		{
			cout << "\nYou entered an invalid input..." << endl;
			cout << "Please enter one of the valid options below." << endl;
			break;
		}

		}//End of switch method
	}//End of while (!start) / Main Menu
	start = false; //reset
}