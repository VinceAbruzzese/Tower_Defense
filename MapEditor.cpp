
#include "MapEditor.h"

// Constructor
MapEditor::MapEditor(Map* map) {
	this->map = map;
}

// Destructor
MapEditor::~MapEditor() {}

// Copy constructor
MapEditor::MapEditor(const MapEditor& orig) {}

// displaying the map
void MapEditor::drawMap() {

	int length = map->getLength(), width = map->getWidth();
	Coordinate** tempMap = map->getMapArray();

	drawMapBorder(length);

	for (int i = 0; i < width; i++) {

		cout << "#";
		for (int j = 0; j < length; j++) {

			switch (tempMap[i][j].getType()) {
			case 0:
				cout << white << "|";
				cout << green << "+"; // grass
				cout << white << "";
				break;

			case 1:
				cout << white << "|";
				cout << cyan << "*"; // path
				cout << white << "";
				break;

			case 2:
				cout << white << "|";
				cout << yellow << "C"; // critter
				cout << white << "";
				break;

			case 3:
				cout << white << "|";
				cout << magenta << "A"; // Arrow Tower
				cout << white << "";
				break;

			case 4:
				cout << white << "|";
				cout << cyan << "S"; // start of path
				cout << white << "";
				break;

			case 5:
				cout << white << "|";
				cout << cyan << "E"; // end of path
				cout << white << "";
				break;

			case 6:
				cout << white << "|";
				cout << lightgrey << "I"; //Ice Tower
				cout << white << "";
				break;

			case 7:
				cout << white << "|";
				cout << red << "F"; //Fire Tower
				cout << white << "";
				break;

			default:
				cout << white << "|";
				cout << green << "_"; // grass
				cout << white << "";
			}
		}
		cout << "|#" << endl;
	}
	drawMapBorder(length);
}

// border of the map
void MapEditor::drawMapBorder(int length) const {

	// will create the border of the map
	int limit = 2 * length + 3;

	for (int i = 0; i < limit; i++) {
		cout << "#";
	}
	cout << endl;
}

// overriding method definition for update()
void MapEditor::update() {
	drawMap();
}