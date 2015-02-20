#include "SaveMap.h"
#include "MapDisplay.h"

void SaveMap::setMapList() {
	system("dir \Maps /b > MapsList.txt");
}

int SaveMap::getSaveMapNumber() {

	ifstream MapsNumber("MapsList.txt");

	int lineNum = 0;
	string s;

	while (!MapsNumber.eof())
	{
		getline(MapsNumber, s);

		if (s.size() != 0)
		{
			lineNum++;
		}
	}

	return lineNum;
}

void SaveMap::SaveMaptoFile(Map* map, int mapNum) {

	string MapName = string("map") + to_string(mapNum) + string(".txt");

	ofstream saveMaptoFile(".\\Maps\\" + MapName);

	saveMaptoFile << map->getLength();
	saveMaptoFile << ",";
	saveMaptoFile << map->getWidth() << endl;

	vector<Coordinate> path = map->getPathVector();

	for (int i = 0; i < path.size(); i++){

		saveMaptoFile << path[i].getX();
		saveMaptoFile << ",";
		saveMaptoFile << path[i].getY();
		saveMaptoFile << endl;
	}

	saveMaptoFile.close();
}

void SaveMap::MapSave(Map* map,ErrorHandling* &errorObj)
{
	string savemap;
	system("cls");

	bool saveMapInput = false;

	while (!saveMapInput)
	{
		// checks if a custom path is required
		askUserIfSaveMap();
		cin >> savemap;
		transform(savemap.begin(), savemap.end(), savemap.begin(), ::tolower);

		// Error Handling For User Input
		try
		{
			errorObj->testYesNo(savemap);
			saveMapInput = true;
		}
		catch (string e)
		{
			system("CLS");
			cout << endl << e << endl;
		}
	}

	if (savemap == "y")
	{

		setMapList();

		SaveMaptoFile(map, getSaveMapNumber());

		mapSaveSuccess();

		system("pause");

	}
}