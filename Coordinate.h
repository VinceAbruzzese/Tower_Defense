//--------------------------------------------------------------
//  Vince Abruzzese 
//  Class: Coordinate
//--------------------------------------------------------------
//  The Coordinate class will be used for the map. It will 
//  keep track of the x,y values in the 2Dmap.
//--------------------------------------------------------------

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {

public:

	/** Contructor, destructor, copy construtor **/
	Coordinate();
	Coordinate(int x, int y);
	virtual ~Coordinate();
	Coordinate(const Coordinate& orig);

	/** getters **/
	int getX()    const;
	int getY()    const;
	int getType() const;

	/** setters **/
	void setX(int x);
	void setY(int y);
	void setType(int type);

private:

	/** instance variables **/
	int x, y; // x and y coordinates
	int type; // will determine if the coordinate is a path, grass, tower, critter
};

#endif