//--------------------------------------------------------------
//  Vince Abruzzese
//  Class: MapEditor
//--------------------------------------------------------------

/** MapEditor "has a" Map **/

#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "Map.h"
#include "Observer.h"
#include "Color.h"

class MapEditor : public Observer {

public:

	/** Contructor, destructor, copy construtor **/
	MapEditor(Map* map);
	MapEditor(const MapEditor& orig);
	virtual ~MapEditor();

	/** Overriding Observer's update() method **/
	void update();

	/** Map display **/
	void drawMap();

private:

	/** instance variable **/
	Map* map;

	/** private method **/
	void drawMapBorder(int length) const; // used in drawMap()
};

#endif