
#include "Coordinate.h"

// Constructor
Coordinate::Coordinate() {
	x = 0;
	y = 0;
	type = 0;
}

// Constructor
Coordinate::Coordinate(int x, int y) : x(x), y(y) {
	type = 0;
}

// Destructor
Coordinate::~Coordinate() {}

// Copy constructor
Coordinate::Coordinate(const Coordinate& orig) {
	this->x = orig.x;
	this->y = orig.y;
	this->type = orig.type;
}

// getter for X
int Coordinate::getX() const{
	return x;
}

// getter for Y
int Coordinate::getY() const{
	return y;
}

// getter for type of coordinate
int Coordinate::getType() const{
	return type;
}

// setter for X
void Coordinate::setX(int x) {
	this->x = x;
}

// setter for Y
void Coordinate::setY(int y) {
	this->y = y;
}

// setter for type of coordinate
void Coordinate::setType(int type) {
	this->type = type;
}