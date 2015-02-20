//---------------------------------------------------------------------
//  Vince Abruzzese
//  Class: MapDisplay
//---------------------------------------------------------------------

#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <iostream>
#include <string>

using namespace std;

void lessThanTen(string type);

void greaterThanThirtyFive(string type);

void updateNotice();

void extraLines();

void constructPathOutput();

void enterCoordinate(string type);

void coordinateOutOfBounds();

void successMessage();

void tileFilled();

void coordinateNotAtBorder();

void constructPathMenu();

void enterChoice();

void pathOutOfBounds();

void notEndPoint();

void minimumPathLength(int minimumPathSize);

void endingPointNotAtBorder();

void invalidInput();

void enterCoordinate2(string type);

void invalidCoordinates();

void towerDisplayMessage();

void cannotRemoveStartingTile();

void successRemoveStartingTile();

void askUserIfSaveMap();

void mapSaveSuccess();

#endif