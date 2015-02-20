#include "MapMenu.h"

// will display the game's main menu
void display_map_options() {

	system("cls");

	cout << "To get started, we must configure the properties of the map:\n" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "Here is a guide as to what each tile of the map does:\n" << endl;
	cout << "-|+| indicates the tiles where towers can be added" << endl;
	cout << "-|*| indicates the tiles where path is outlined\n" << endl;
	cout << "-|S| indicates the start of the outlined path" << endl;
	cout << "-|E| indicates the end of the outlined path\n" << endl;
	cout << "-|A| indicates the tiles where an Arrow Tower is placed" << endl;
	cout << "-|F| indicates the tiles where a Fire Tower is placed" << endl;
	cout << "-|I| indicates the tiles where an Ice Tower is placed\n" << endl;
	cout << "-|C| indicates the tiles where a critter is moving from" << endl;
	cout << "---------------------------------------------------------------" << endl;
}

// options if the user wants add a custom path and custom towers
void customMapOptions(Map* map, ErrorHandling* errorObj) {

	string customPath;
	bool customPathInput = false;

	while (!customPathInput)
	{
		// checks if a custom path is required
		cout << "\n\nDo you want to create a custom path? (y/n): ";
		cin >> customPath;
		transform(customPath.begin(), customPath.end(), customPath.begin(), ::tolower);

		// Error Handling For User Input
		try
		{
			errorObj->testYesNo(customPath);
			customPathInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl;
		}
	}

	if (customPath == "y")
		map->createCustomPath(errorObj); // custom path called
	else {
		cout << "\n\nCreated a default path\n\n" << endl;
		map->createDefaultPath(); // default path called
		cout << "End of map menu\n" << endl;
		system("pause");
	}

	system("cls");
}

void loadSavedMap(string& loadmap, LoadMap* loadMapObj, SaveMap* saveMapObj, string mapName, Map* &mapObj, MapEditor* &mapEditorObj, ErrorHandling* errorObj, string& custom, int& length, int& width)
{

	bool loadMapInput = false;

	while (!loadMapInput)
	{
		cout << "\nWould you like to load a map? (y/n): ";
		cin >> loadmap;
		transform(loadmap.begin(), loadmap.end(), loadmap.begin(), ::tolower);

		// Error Handling For User Input
		try
		{
			errorObj->testYesNo(loadmap);
			loadMapInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl;
		}

	}

	if (loadmap == "y")
	{
		// Error Handling For Checking if Saved Maps Exists
		try
		{
			errorObj->checkAvailableMaps();

			cout << endl << "\nWhich map would you like to load from the following list?\n\n" << endl;
			loadMapObj->DisplaySaveList();

			bool testMapName = false;

			while (!testMapName)
			{
				cout << endl << "Which map would you like to load? (ex: map1): ";
				cin >> mapName;

				try
				{
					errorObj->checkMapName(mapName);
					testMapName = true;

					string LoadMapName = string(".\\Maps\\") + mapName + string(".txt");

					cout << "\n" << endl;

					loadMapObj->MapLoad(LoadMapName, mapObj, mapEditorObj);
					mapObj->addObserver(mapEditorObj);
				}
				catch (string e)
				{
					cout << endl << e << endl;
				}
			}

		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl;
			createCustomMap(custom, length, width, mapObj, mapEditorObj, errorObj, saveMapObj);
		}
	}
	else if (loadmap == "n")
	{
		createCustomMap(custom, length, width, mapObj, mapEditorObj, errorObj, saveMapObj);
	}

}

void createCustomMap(string& custom, int& length, int& width, Map* &mapObj, MapEditor* &mapEditorObj, ErrorHandling* errorObj, SaveMap* saveMapObj)
{

	bool CreateMapInput = false;

	while (!CreateMapInput)
	{

		cout << "\nWould you like a custom map? (y/n): ";
		cin >> custom;
		transform(custom.begin(), custom.end(), custom.begin(), ::tolower);

		// Error Handling For User Input
		try
		{
			errorObj->testYesNo(custom);
			CreateMapInput = true;
		}
		catch (string e){ system("CLS"); cout << endl << e << endl; }

	}

	if (custom == "y")
	{
		system("cls");
		cout << "Enter a length and width for the Map of the Game" << endl;
		cout << "Length and width must be greater than 10 but no more than 15\n" << endl;

		bool testMapRange = false;

		string length_str;
		string width_str;

		while (!testMapRange)
		{
			cout << "Length: ";
			cin >> length_str;

			cout << "\nWidth:  ";
			cin >> width_str;

			try
			{
				errorObj->testDigitString(length_str);
				errorObj->testDigitString(width_str);

				length = atoi(length_str.c_str());
				width = atoi(width_str.c_str());

				errorObj->testMapRange(length, width);
				testMapRange = true;
			}
			catch (string e){ system("CLS"); cout << endl << e << endl << endl; }
		}

		length = atoi(length_str.c_str());
		width = atoi(width_str.c_str());

		/* Initializing the objects */
		mapObj = new Map(length, width);
		mapEditorObj = new MapEditor(mapObj);
		mapObj->addObserver(mapEditorObj);	// adding an obersever

		// if user wants a custom path and/or custom towers
		customMapOptions(mapObj, errorObj);
		saveMapObj->MapSave(mapObj,errorObj);
	}
	else if (custom == "n")
	{
		cout << "\n\nCreating a default Map!" << endl;
		createDefaultMap(mapObj, mapEditorObj);
	}

}

void createDefaultMap(Map* &mapObj, MapEditor* &mapEditorObj)
{
	mapObj = new Map();
	mapEditorObj = new MapEditor(mapObj);
	mapObj->addObserver(mapEditorObj);	// adding an obersever

	cout << "\nEmpty map:\n" << endl;
	mapEditorObj->drawMap();

	// creating a default path
	cout << "\n\nCreated a default path!\n" << endl;
	mapObj->createDefaultPath();

	cout << "End of map menu\n" << endl;
	system("PAUSE");
}

void map_menu(int& length, int& width, string& custom, Map* &mapObj, MapEditor* &mapEditorObj, string& loadmap, string mapName, SaveMap* saveMapObj, LoadMap* loadMapObj, ErrorHandling* errorObj)
{
	// Outputs the Main Menu of the game 
	display_map_options();

	///////////////////////////////////////////////////
	// ASK if the user would like to load/create a map
	///////////////////////////////////////////////////

	loadSavedMap(loadmap, loadMapObj, saveMapObj, mapName, mapObj, mapEditorObj, errorObj, custom, length, width);

	system("CLS");
}