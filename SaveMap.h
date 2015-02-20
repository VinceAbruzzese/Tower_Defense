//--------------------------------------------------------------
//  Vince Abruzzese
//  Gameplay.h
//--------------------------------------------------------------
//  The SaveMap.h file will contain all the methods we will use 
//  to save a map .
//--------------------------------------------------------------

#ifndef SAVEMAP_H
#define SAVEMAP_H

#include <Windows.h>
#include "ErrorHandling.h"
#include "Map.h"
#include <iostream>
#include <string>
#include <iterator>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

class SaveMap {

public:

	void MapSave(Map* map, ErrorHandling* &errorObj);

	void SaveMaptoFile(Map* map, int mapNum);

	void setMapList();

	int getSaveMapNumber();
};



#endif
//End of SaveMap.h