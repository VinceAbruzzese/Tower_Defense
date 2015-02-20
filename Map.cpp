
/* IMPORTANT : map2d[width][length] */

#include "Map.h"
#include "MapEditor.h"
#include <iostream>
#include "Attributes.h"
#include "MapDisplay.h"

using namespace std;

// Constructor
Map::Map(int length, int width) : length(length), width(width) {

	bool badInput = false;

	// handling bad input
	if (length < 10) {
		lessThanTen("Length");
		this->length = DEFAULT_VALUE_MIN;
		badInput = true;
	}
	else if (length > 35) {
		greaterThanThirtyFive("Length");
		this->length = DEFAULT_VALUE_MAX;
		badInput = true;
	}

	if (width < 10) {
		lessThanTen("Width");
		this->width = DEFAULT_VALUE_MIN;
		badInput = true;
	}
	else if (width > 35) {
		greaterThanThirtyFive("Width");
		this->width = DEFAULT_VALUE_MAX;
		badInput = true;
	}

	// creating 2d array
	map2D = new Coordinate*[this->width];

	for (int i = 0; i < this->width; i++)
		map2D[i] = new Coordinate[this->length];

	// initializing to map tiles to 0s
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->length; j++) {
			map2D[i][j].setX(i);
			map2D[i][j].setY(j);
		}
	}

	if (badInput) {
		extraLines();
		system("pause");
	}
}

// Destructor
Map::~Map() {

	for (int i = 0; i < Map::getWidth(); i++)
		delete[] map2D[i];

	delete[] map2D;
}

// Copy constructor
Map::Map(const Map& orig) {}

// setter for length
void Map::setLength(int length) {
	this->length = length;
	notify(); // notifies observer that length has changed
}

// setter for width
void Map::setWidth(int width) {
	this->width = width;
	notify(); // notifies observer that width has changed
}

// sets value of the critter on the map
void Map::setValue(int x, int y, int value)
{
	map2D[y][x].setType(value);
}

// getter for length
int Map::getLength() const {
	return length;
}

// getter for width
int Map::getWidth() const {
	return width;
}

// getter for map array
Coordinate** Map::getMapArray() const {
	return map2D;
}

// getter for path vector
vector<Coordinate> Map::getPathVector() const {
	return path;
}

// creating a default path
void Map::createDefaultPath() {

	int pathLength = 0;

	if ((length % 2) == 0)
		pathLength = length / 2; // if length is even
	else
		pathLength = (length / 2) + 1; // if length is odd


	// start point of path
	Coordinate c(0, 0);
	path.push_back(c);
	map2D[0][0].setType(4);

	// creating path for the a[0][]
	for (int i = 1; i < pathLength; i++) {
		Coordinate c1(i, 0);
		map2D[0][i].setType(1);
		path.push_back(c1);
	}

	// creating path vertically down a[][middle]
	for (int i = 1; i < width; i++) {
		Coordinate c1(pathLength - 1, i);
		map2D[i][pathLength - 1].setType(1);
		path.push_back(c1);
	}

	// creating path for the a[last][]
	for (int i = pathLength; i < length - 1; i++) {
		Coordinate c1(i, width - 1);
		map2D[width - 1][i].setType(1);
		path.push_back(c1);
	}

	// end point of path
	Coordinate c2(length - 1, width - 1);
	map2D[(width - 1)][(length - 1)].setType(5);
	path.push_back(c2);

	// notifies observer that a default path has been created
	updateNotice();
	notify();
	extraLines();
}

// creating a custom path
void Map::createCustomPath(ErrorHandling* &errorObj) {

	bool valid = false;
	MapEditor* tempObj = new MapEditor(this);

	// Part 1: for starting coordinates
	do {

		int x, y; // coordinates
		string x_str, y_str;

		bool testStartCoordinates = false;

		while (!testStartCoordinates)
		{
			constructPathOutput();
			tempObj->drawMap();
			extraLines();
			extraLines();
			enterCoordinate("X");
			cin >> x_str;
			enterCoordinate("Y");
			cin >> y_str;

			try
			{
				errorObj->testDigitString(x_str);
				errorObj->testDigitString(y_str);

				x = atoi(x_str.c_str());
				y = atoi(y_str.c_str());

				errorObj->testStartCoordinates(x, y, length, width);
				errorObj->testBorder(x, y, length, width); 
				testStartCoordinates = true;
			}
			catch (string e){ system("CLS"); cout << endl << e << endl << endl; }
		}

		x = atoi(x_str.c_str());
		y = atoi(y_str.c_str());

		try
		{
			if (map2D[y][x].getType() == 0) { // succesfully adding the starting path
				Coordinate c(x, y);
				map2D[y][x].setType(4);
				path.push_back(c); // adding to path vector
				valid = true;
				cout << "\nSuccessfully Added!\n\n" << endl;
				cout << "Updated the game's map:\n" << endl;
				notify(); // notifies observer that starting point has been added
				cout << "\n\n" << endl;
			}
			else
			{
				throw string("\nThat tile is already filled. Enter alternative coordinates.\n\n");
			}
		}
		catch (string e){ system("CLS"); cout << endl << e << endl << endl; }

		system("pause");

	} while (!valid);


	valid = false;


	// Part 2: path coordinates from user input
	int coordinateX = path[0].getX();
	int coordinateY = path[0].getY();
	vector<int> positionType; // will keep track of the whether the coordinate is up (1), down (2), left (3) or right (4) from the poreviously added coordinate

	do {

		int tempX = coordinateX, tempY = coordinateY;	// will hold temporary x and y coordinates
		char key;										// the user's choice

		system("cls");
		constructPathMenu();

		tempObj->drawMap();

		enterChoice();
		cin >> key;

		key = tolower(key);

		switch (key) {

		case 'w':
			// move UP
			tempY -= 1;

			if (tempX < 0 || tempY < 0 || tempX >(length - 1) || tempY >(width - 1))
				pathOutOfBounds();
			else {

				if (map2D[tempY][tempX].getType() == 0) { // succesfully adding the starting path

					Coordinate c(tempX, tempY);
					map2D[tempY][tempX].setType(1);
					path.push_back(c); // adding to path vector

					successMessage();
					updateNotice();
					notify(); // notifies observer that path tile has been added

					extraLines();
					coordinateY = tempY;
					positionType.push_back(1);
				}
				else
					tileFilled();
			}
			break;

		case 's':
			// move DOWN
			tempY += 1;

			if (tempX < 0 || tempY < 0 || tempX >(length - 1) || tempY >(width - 1))
				pathOutOfBounds();
			else {

				if (map2D[tempY][tempX].getType() == 0) { // succesfully adding the starting path

					Coordinate c(tempX, tempY);
					map2D[tempY][tempX].setType(1);
					path.push_back(c); // adding to path vector

					successMessage();
					updateNotice();
					notify(); // notifies observer that path tile has been added

					coordinateY = tempY;
					positionType.push_back(2);
				}
				else
					tileFilled();
			}
			break;

		case 'a':
			// move LEFT
			tempX -= 1;

			if (tempX < 0 || tempY < 0 || tempX >(length - 1) || tempY >(width - 1))
				pathOutOfBounds();
			else {

				if (map2D[tempY][tempX].getType() == 0) { // succesfully adding the starting path

					Coordinate c(tempX, tempY);
					map2D[tempY][tempX].setType(1);
					path.push_back(c); // adding to path vector

					successMessage();
					updateNotice();
					notify(); // notifies observer that path tile has been added

					coordinateX = tempX;
					positionType.push_back(3);
				}
				else
					tileFilled();
			}
			break;

		case 'd':
			// move RIGHT
			tempX += 1;

			if (tempX < 0 || tempY < 0 || tempX >(length - 1) || tempY >(width - 1))
				pathOutOfBounds();
			else {

				if (map2D[tempY][tempX].getType() == 0) { // succesfully adding the starting path

					Coordinate c(tempX, tempY);
					map2D[tempY][tempX].setType(1);
					path.push_back(c); // adding to path vector

					successMessage();
					updateNotice();
					notify(); // notifies observer that path tile has been added

					coordinateX = tempX;
					positionType.push_back(4);
				}
				else
					tileFilled();
			}
			break;

		case 'e':
			// END
			if (checkEndPoint()) {
				valid = true;
				map2D[tempY][tempX].setType(5);
			}
			else {

				int minimumPathSize;

				if (length > width)
					minimumPathSize = width;
				else if (length < width)
					minimumPathSize = length;
				else // length == width
					minimumPathSize = length;


				// path error handling
				if (path.size() == 1)
					notEndPoint();
				else if (path.size() < minimumPathSize)
					minimumPathLength(minimumPathSize);
				else
					endingPointNotAtBorder();
			}

			break;

		case 'r':
			// call remove tile function
			if (removeTile()) {

				int type = positionType[positionType.size() - 1];
				// reset the counter for the coordinate values on the map 
				switch (type) {
				case 1:
					coordinateY += 1;
					break;

				case 2:
					coordinateY -= 1;
					break;

				case 3:
					coordinateX += 1;
					break;

				case 4:
					coordinateX -= 1;
					break;
				}

				positionType.erase(positionType.begin() + (positionType.size() - 1));
			}
			break;

		default:
			invalidInput();
		}

		extraLines();
		system("pause");

	} while (!valid);

	delete tempObj;
}

// adding custom towers
void Map::addTowerToMap(Tower* &tower, ErrorHandling* &errorObj) {

	bool valid = false;
	MapEditor* tempObj = new MapEditor(this);

	int x, y; // coordinates and option for adding coordinates

	system("CLS");
	tempObj->drawMap();

	while (1)
	{
		string x_str, y_str;

		bool testTowerCoordinates = false;

		while (!testTowerCoordinates)
		{
			extraLines();
			enterCoordinate2("X");
			cin >> x_str;
			enterCoordinate2("Y");
			cin >> y_str;

			try
			{
				errorObj->testDigitString(x_str);
				errorObj->testDigitString(y_str);

				x = atoi(x_str.c_str());
				y = atoi(y_str.c_str());

				errorObj->testTowerCoordinates(x, y, length, width);
				testTowerCoordinates = true;
			}
			catch (string e){ system("CLS"); cout << endl << e << endl << endl; }
		}

		x = atoi(x_str.c_str());
		y = atoi(y_str.c_str());

		try
		{
			if (map2D[y][x].getType() == 0)
			{ 
				tower->setX(x);
				tower->setY(y);
				Coordinate c(x, y);

				if (tower->getType() == "Arrow Tower")
					map2D[y][x].setType(3); //change display to arrow tower
				else if (tower->getType() == "Ice Tower")
					map2D[y][x].setType(6);  //change display to ice tower
				else if (tower->getType() == "Fire Tower")
					map2D[y][x].setType(7); //change display to fire tower

				system("CLS");
				cout << "\nSuccessfully Added!\n" << endl;
				cout << "Below is a view of your towers on the map:\n" << endl;
				notify(); // notifies observer that a tower has been added (will display map again)
				system("PAUSE");
				system("CLS");
				break;
			}
			else
			{
				throw string("\nThat tile is already filled. Enter alternative coordinates.");
			}
		}
		catch (string e){ system("CLS"); cout << endl << e << endl << endl; }

	}

}//end of addTowerToMap()

//Removes the tower from the map
void Map::removeTowerFromMap(Tower* tower)
{
	//int* tower_index = tower->getIndex();
	int x = tower->getX();
	int y = tower->getY();
	map2D[y][x].setType(0); //Set the display to grass
	towerDisplayMessage();
	notify(); //notifies observer of changes to map
}

// removing the last path tile from the map
bool Map::removeTile() {

	int pathSize = path.size() - 1;

	if (pathSize == 0) { // starting path
		cannotRemoveStartingTile();
		return false;
	}
	else {
		map2D[path[pathSize].getY()][path[pathSize].getX()].setType(0);
		path.erase(path.begin() + pathSize);

		successRemoveStartingTile();
		updateNotice();

		notify(); // notifies observer that path tile has been removed
		extraLines();
		return true;
	}
}

// checks if the last coordinate in the path vector is at the border or not
bool Map::checkEndPoint() {

	int pathSize = path.size() - 1; // size of path vector
	int x = path[pathSize].getX(), y = path[pathSize].getY(); // x and y coordinates of the last tile in path vector
	int minimumPathSize;

	if (length > width)
		minimumPathSize = width;
	else if (length < width)
		minimumPathSize = length;
	else // length == width
		minimumPathSize = length;

	// path size must be at least the minimum value from length or width
	if (++pathSize < minimumPathSize)
		return false;
	else {
		if (x == 0 || y == 0 || x == (length - 1) || y == (width - 1))
			return true;
		else
			return false;
	}
}

void Map::updateCritterOnMap(int y, int x, int location)
{
	if ((location - 1) == 0)
		map2D[y][x].setType(4);
	else
		map2D[y][x].setType(1);

	if ((map2D[path.at(location).getY()][path.at(location).getX()]).getType() == 1)
		map2D[path.at(location).getY()][path.at(location).getX()].setType(2);
	//else if ((map2D[path.at(location).getY()][path.at(location).getX()]) == 5);
	//system("PAUSE");

}//Called in move()

void Map::removeCritterFromMap(int y, int x)
{
	map2D[y][x].setType(1); //Removes critter from map display
}

// Loading File Methods

void Map::setPath(int x, int y)
{
	
		map2D[y][x].setType(1);
		Coordinate c(x, y);
		path.push_back(c);
	
}

void Map::setStart(int x, int y)
{
	map2D[y][x].setType(4);
	Coordinate c(x, y);
	path.push_back(c);
}

void Map::setEnd(int x, int y)
{
	map2D[y][x].setType(5);
	Coordinate c(x, y);
	path.push_back(c);
}