#include "LoadMap.h"

vector<string> LoadMap::getMapVector() {

	vector<string> mapList;

	system("dir \Maps /b > MapsList.txt");

	ifstream MapsNumber("MapsList.txt");

	string s;

	while (!MapsNumber.eof())
	{
		getline(MapsNumber, s);

		if (s.size() != 0)
		{
			mapList.push_back(s);
		}
	}

	return mapList;

}

void LoadMap::DisplayMap(string mapFile) {

	Map* mapObj = NULL;
	MapEditor* mapEditorObj = NULL;

	string map = string(".\\Maps\\") + mapFile;

	MapLoad(map, mapObj, mapEditorObj);

}

void LoadMap::DisplaySaveList() {

	vector<string> mapList = getMapVector();

	for (int i = 0; i < mapList.size(); i++)
	{
		cout << mapList[i] << endl << endl;

		DisplayMap(mapList[i]);

		cout << endl << endl;
	}

}

vector<string> LoadMap::split(const string Line, char delimiter)
{
	std::vector<std::string> coordinates;
	std::string coordinate;

	std::stringstream LC(Line);
	while (std::getline(LC, coordinate, delimiter))
	{
		if (!coordinate.empty())
		{
			coordinates.push_back(coordinate);
		}
	}

	return coordinates;
}

int LoadMap::getNumberoflines(string str) {

	ifstream MapsNumber(str);

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

void LoadMap::MapLoad(string mapFile, Map* &mapObj, MapEditor* &mapEditorObj)
{
	ifstream MapLines(mapFile);

	int lineNo = 0;

	int lastLine = getNumberoflines(mapFile);

	mapObj = new Map();
	mapEditorObj = new MapEditor(mapObj);


	for (string Line; getline(MapLines, Line);)
	{
		if (lineNo == 0)
		{
			std::vector<std::string> coordinates = split(Line, ',');

			int length = atoi(coordinates[0].c_str());
			int width = atoi(coordinates[1].c_str());

			mapObj->setLength(length);
			mapObj->setWidth(width);
		}

		if (lineNo != 0 && lineNo == 1)
		{
			std::vector<std::string> coordinates = split(Line, ',');

			int start_coor_x = atoi(coordinates[0].c_str());
			int start_coor_y = atoi(coordinates[1].c_str());

			mapObj->setStart(start_coor_x, start_coor_y);
		}

		if (lineNo != 0 && lineNo != 1 && lineNo <lastLine-1)
		{
			std::vector<std::string> coordinates = split(Line, ',');

			int start_coor_x = atoi(coordinates[0].c_str());
			int start_coor_y = atoi(coordinates[1].c_str());

			mapObj->setPath(start_coor_x, start_coor_y);
		}

		if (lineNo == lastLine-1)
		{
			std::vector<std::string> coordinates = split(Line, ',');


			int start_coor_x = atoi(coordinates[0].c_str());
			int start_coor_y = atoi(coordinates[1].c_str());

			mapObj->setEnd(start_coor_x, start_coor_y);
		}

		lineNo++;
	}

	mapEditorObj->drawMap();
}