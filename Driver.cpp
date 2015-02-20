#include "TowerMenu.h"
#include "Timer.h"
#include "Critter.h"
#include "Gameplay.h"
#include "Map.h"
#include "TowerRangeDisplay.h"
#include "MapMenu.h"

int main()
{
	Session session; //used to display gold, lives, etc..
	Timer timer;
	int round = 1;

	//Tower:
	vector<Tower*> tower_list;
	int list_size = 0; //Size of tower list
	bool start = false; //determines when to start round

	//Map:
	int length, width;	// length and width of map
	string custom;		// either yes or no on custum map
	Map* mapObj = NULL;
	MapEditor* mapEditorObj = NULL;
	SaveMap* saveMapObj = NULL;
	LoadMap* loadMapObj = NULL;
	ErrorHandling* errorObj = NULL;
	vector<Coordinate> path;

	string mapName;
	string loadmap;

	//Critter
	vector<Critter*> critter_list;

	welcome_message(); //Introduction to the game
	map_menu(length, width, custom, mapObj, mapEditorObj, loadmap, mapName, saveMapObj, loadMapObj, errorObj); //Start with creating/loading the map

	path = mapObj->getPathVector(); //Get the path of the map

	for (int i = 0; i < MAX_NUMBER_OF_ROUNDS; i++)
	{
		tower_menu(session, tower_list, list_size, start, mapObj, "START",errorObj); //display tower menu
		start_next_round(path, critter_list, mapObj, mapEditorObj, tower_list, session, list_size, start,errorObj);
	}//Loop for the total amount of rounds

	cout << "Congratulations! You have completed the game.\n" << endl;
	system("PAUSE");
	return 0;
}//end of main