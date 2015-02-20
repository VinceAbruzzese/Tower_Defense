//--------------------------------------------------------------
//  Vince Abruzzese 
//  Class: Map
//--------------------------------------------------------------

#ifndef MAP_H
#define MAP_H

#include "Coordinate.h"
#include "Observable.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>
#include "ErrorHandling.h"
#include <conio.h>
#include "Tower.h"
#include <sstream>
#include <stdlib.h>
#include <iterator>
#include <stdio.h>
#include <algorithm>
#include <fstream>

using namespace std;

class Observable;
class MapEditor;

class Map : public Observable {

public:

	/** Contructor, destructor, copy construtor **/
	Map(int length = 15, int width = 15);	// default values for length and width is 15
	virtual ~Map();
	Map(const Map& orig);

	/** getters **/
	int getLength()	    const;
	int getWidth()	    const;
	Coordinate** getMapArray()	        const;
	vector<Coordinate> getPathVector()	const;

	/** setters **/
	void setLength(int length);
	void setWidth(int width);
	void setValue(int x, int y, int value);

	/** Map related methods **/
	void createDefaultPath();
	void createCustomPath(ErrorHandling* &errorObj);
	void addTowerToMap(Tower* &tower, ErrorHandling* &errorObj);
	void removeTowerFromMap(Tower* tower);

	/** output methods **/
	void updateCritterOnMap(int x, int y, int location);
	void removeCritterFromMap(int y, int x);

	void setPath(int x, int y);
	void setStart(int x, int y);
	void setEnd(int x, int y);

private:

	/** instance variables **/
	int length, width;

	// 2D array for the map of the game
	Coordinate** map2D;

	// vectors will hold coordinates of path, towers and a single critter (for the purpose of the assignment)
	vector<Coordinate> path;

	/** private methods **/
	void removeTower(Coordinate c);
	bool removeTile();
	bool checkEndPoint();
};

#endif