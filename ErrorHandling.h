//--------------------------------------------------------------
//  Vince Abruzzese 
//  Gameplay.h
//--------------------------------------------------------------
//  The ErrorHandling.h file will contain all the methods we will use 
//  to handle & output potential errors during the game.
//--------------------------------------------------------------

#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

#include <string>
#include <fstream>
#include <regex>
using namespace std;

class ErrorHandling {

public:

	void testYesNo(string s);

	void checkAvailableMaps();

	void checkMapName(string mapName);

	void testMapRange(int length, int width);

	void testIntStringInput(string x, int start, int end);

	void testTowerChoosingOption(string s, int x);

	void testDigitString(string s);

	void testStartCoordinates(int x, int y, int length, int width);

	void testTowerCoordinates(int x, int y, int length, int width);

	void testBorder(int x, int y, int length, int width);

};



#endif
//End of ErrorHandling.h