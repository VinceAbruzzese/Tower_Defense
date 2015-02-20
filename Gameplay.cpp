#include "Gameplay.h"
#include "Map.h"
#include "MapEditor.h"
#include "Tower.h"
#include "ArrowTower.h"
#include "IceTower.h"
#include "FireTower.h"
#include <conio.h>
#include "FireCritter.h"
#include "ArmorCritter.h"
#include "SpeedCritter.h"
#include "CritterFactory.h"
#include "CritterDisplay.h"

void welcome_message()
{
	cout << "\n----------------------------------------------------" << endl;
	cout << "Welcome to COMP345 Tower Defense!" << endl;
	cout << "----------------------------------------------------\n" << endl;
	system("PAUSE");
	system("CLS");
	//We will do display_session everytime we clear the screen
	//This will update our info for gold, lives, etc.
}

//We will check if a new critter should be spawned
void check_for_spawn(Timer &timer, vector<Critter*> &critter_list, vector<Coordinate> &path, Map* &map, int &critter_count, int level, float spawn_rate, int &critter_type)
{
	if (timer.getTime() >= spawn_rate && critter_count != 0)
	{
		Critter* critter = NULL;

		CritterFactory Factory;
		critter = Factory.getCritter(path, map, level, critter_type);
		critter_list.push_back(critter); //spawn new critter
		critter_type = (critter_type + 1) % 3; //change to next critter type
		
		timer.reset();
		critter_count--; //decrement the count (once 0 all monsters have spawned for the round)
	}
}

//If a critter's HP has gone below 0, we must remove them from the list. This method checks that
// and removes the critter if applicable
void clean_critter_list(vector<Critter*> &critter_list, int path_size, Session &session)
{
	Critter* temp = NULL;
	for (int i = 0; i < critter_list.size(); i++)
	{
		if (critter_list.at(i)->getHP() <= 0)
		{
			session.reward(critter_list.at(i)->getValue()); //Add critter gold value
			temp = critter_list.at(i);
			critter_list.erase(critter_list.begin() + i);
		}
		else if (critter_list.at(i)->getLocation() == path_size)
		{
			session.loseLife();
			if (session.getGold() >= critter_list.at(i)->getStrength())
				session.loseGold(critter_list.at(i)->getStrength()); //reduces gold by strength
			else
				session.loseGold(session.getGold()); //brings down to 0 (avoid having (-) gold
			temp = critter_list.at(i);
			critter_list.erase(critter_list.begin() + i);
		} //if critter reaches end, lose a life and gold based on strength
		if (temp != NULL)
		{
			delete temp;
			temp = NULL;
		}
	}
}

//Different levels have different quantity of critters. This method will return the 
//quantity for that round
int get_spawn_quantity(int round)
{
	switch (round)
	{
	case 1:
		return LEVEL_1_QUANTITY;
	case 2:
		return LEVEL_2_QUANTITY;
	case 3:
		return LEVEL_3_QUANTITY;
	case 4:
		return LEVEL_4_QUANTITY;
	case 5:
		return LEVEL_5_QUANTITY;
	case 6:
		return LEVEL_6_QUANTITY;
	case 7:
		return LEVEL_7_QUANTITY;
	case 8:
		return LEVEL_8_QUANTITY;
	case 9:
		return LEVEL_9_QUANTITY;
	case 10:
		return LEVEL_10_QUANTITY;
	}
}

int get_reward(int round)
{
	switch (round)
	{
	case 1:
		return ROUND_1_REWARD;
	case 2:
		return ROUND_2_REWARD;
	case 3:
		return ROUND_3_REWARD;
	case 4:
		return ROUND_4_REWARD;
	case 5:
		return ROUND_5_REWARD;
	case 6:
		return ROUND_6_REWARD;
	case 7:
		return ROUND_7_REWARD;
	case 8:
		return ROUND_8_REWARD;
	case 9:
		return ROUND_9_REWARD;
	case 10:
		return ROUND_10_REWARD;
	}
}

//If user pauses the game will the round is in action, we will display the pause menu below and allow
//the user to buy, sell, upgrade towers
void pause_menu(Session &session, vector<Tower*> &tower_list, int &list_size, bool &start, Map* &map, vector<Critter*> &critter_list, ErrorHandling* &errorObj)
{
	string option;

	bool inputTest = false;

	while (!inputTest)
	{
		system("CLS");
		cout << "You have paused the game. Select an option below:" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Tower Menu (1): " << endl;
		cout << "Critter Interface (2): " << endl;
		cout << "Resume Game (3): " << endl;
		cout << "End Game (4): " << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "\nPlease enter the action you would like to take: ";
		cin >> option;

		try
		{
			errorObj->testIntStringInput(option, 1, 4);
			inputTest = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl << endl;
		}

		if (option == "1")
		{
			system("CLS");
			tower_menu(session, tower_list, list_size, start, map, "PAUSE", errorObj); //display tower menu
			break;
		}
		else if (option == "2")
		{
			system("CLS");
			critter_interface(critter_list);
			system("PAUSE");
			break;
		}
		else if (option == "3")
			break; //return game
		else if (option == "4")
		{
			system("CLS");
			cout << "GAME OVER\n" << endl;
			system("PAUSE");
			exit(0);
		}

	}
}

//If user pauses game, we want to pause all the timers of our critters, towers, and spawn_rate
void pause_all_timers(vector<Critter*> &critter_list, vector<Tower*> &tower_list, Timer &spawn_timer)
{
	for (int i = 0; i < critter_list.size(); i++)
		critter_list.at(i)->pauseTimer();

	for (int i = 0; i < tower_list.size(); i++)
		tower_list.at(i)->pauseTimer();

	spawn_timer.stop();
}

//Resume all our timers
void resume_all_timers(vector<Critter*> &critter_list, vector<Tower*> &tower_list, Timer &spawn_timer)
{
	for (int i = 0; i < critter_list.size(); i++)
		critter_list.at(i)->startTimer();

	for (int i = 0; i < tower_list.size(); i++)
		tower_list.at(i)->startTimer();

	spawn_timer.start();
}

//This method will check if the user has run out of lives, if it has it will exit
void game_over(Session &session)
{
	if (session.getLives() == 0)
	{
		system("CLS");
		cout << "You have run out of lives." << endl;
		cout << "\nGAME OVER" << endl;
		system("PAUSE");
		exit(0);
	}
}

void critter_interface(vector<Critter*> &critter_list)
{
	cout << "\nCritter Interface:" << endl;
	cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < critter_list.size(); i++)
	{
		cout << i << ": ";
		displayCritter(critter_list.at(i));
	}
	cout << "---------------------------------------------------------" << endl;
}

//The main method of the gameplay. It will loop every 800ms and refresh the console will the updated display of the map. Through each loop
//the critters check if enough time has passed for them to move, the towers check if a critter is in range and we check if another critter should
//be spawned. We also display the critters and their health & speed as they traverse the path
void start_next_round(vector<Coordinate> &path, vector<Critter*> &critter_list, Map* &map, MapEditor* &display, vector<Tower*> &tower_list, Session &session, int &list_size, bool &start, ErrorHandling* &errorObj)
{
	Timer spawn_timer; //timer used between spawning new critters
	spawn_timer.start();
	int critter_count = get_spawn_quantity(session.getRound()); //max number of critters
	float spawn_rate = SPAWN_RATE;
	int path_size = path.size();
	int critter_type = 0;

	while (1)
	{
		if (_kbhit()) //if true user has paused the game
		{
			pause_all_timers(critter_list, tower_list, spawn_timer);
			pause_menu(session, tower_list, list_size, start, map, critter_list,errorObj);
			resume_all_timers(critter_list, tower_list, spawn_timer);
		}
		Sleep(800);
		system("CLS");
		cout << red << "PRESS ANY KEY TO PAUSE THE GAME" << white << endl;
		display_session(session);
		display->drawMap();

		for (int i = 0; i < critter_list.size(); i++)
			critter_list.at(i)->check_for_update();
		 //Go through critter list and see if you can update

		for (int i = 0; i < tower_list.size(); i++)
			tower_list.at(i)->attackCritter(critter_list);
		//Go through tower list and see if any towers can attack

		check_for_spawn(spawn_timer, critter_list, path, map, critter_count, session.getRound(), spawn_rate, critter_type);
		//check if time to spawn new critter

		clean_critter_list(critter_list, path_size, session); //remove dead critters

		//Critter Interface
		critter_interface(critter_list);
		
		game_over(session); //check if lives are 0
		
		if (critter_count == 0 && critter_list.size() == 0)
			break; //round is over	
	
	}
	
	Coordinate endCoordinate = map->getPathVector()[map->getPathVector().size() - 1];
	
	int endX = endCoordinate.getX();
	int endY = endCoordinate.getY();
	
	map->setEnd(endX, endY);

	system("CLS");
	display_session(session);
	display->drawMap();
	cout << "\nEnd of Round " << session.getRound() << "." << endl;
	cout << "You have earned " << get_reward(session.getRound()) << " gold for completing the round!" << endl;
	session.reward(get_reward(session.getRound()));
	session.nextRound(); //brings us next round (increment)
	system("PAUSE");
	system("CLS");
}