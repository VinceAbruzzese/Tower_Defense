//--------------------------------------------------------------
//  Vince Abruzzese
//  Gameplay.h
//--------------------------------------------------------------
//  The LoadMap.h file will contain all the methods we will use 
//  to load a previously saved map .
//--------------------------------------------------------------

#ifndef LOADMAP_H
#define LOADMAP_H

#include <Windows.h>
#include "Map.h"
#include "MapEditor.h"
#include <iostream>
#include <string>
#include <stack>
#include <iterator>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class LoadMap {

public:

	void DisplaySaveList();

	vector<string> getMapVector();

	int getNumberoflines(string str);

	void MapLoad(string mapFile, Map* &mapObj, MapEditor* &mapEditorObj);

	void DisplayMap(string mapFile);

	vector<string> split(const string Line, char delimiter);

};



#endif
//End of LoadMap.h