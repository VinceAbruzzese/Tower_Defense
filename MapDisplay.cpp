#include "MapDisplay.h"

void lessThanTen(string type) {
	cout << type << " is less than 10. Using default value of 10 instead." << endl;
}

void greaterThanThirtyFive(string type) {
	cout << type << " is greater than 35. Using default value of 35 instead." << endl;
}

void updateNotice() {
	cout << "Updated the game's map:\n" << endl;
}

void extraLines() {
	cout << "\n\n" << endl;
}

void constructPathOutput() {
	cout << "CONSTRUCT A PATH\n" << endl;
	cout << "\nStarting and Ending coordinates must be placed at the border region of the Map!\n\nEmpty map:\n" << endl;
}

void enterCoordinate(string type) {
	cout << "Enter the Start " << type << " coordinate: ";
}

void coordinateOutOfBounds() {
	cout << "\nCoordinate out of Bounds. Enter the correct values.\n\n" << endl;
}

void successMessage() {
	cout << "\nSuccessfully Added!\n\n" << endl;
}

void tileFilled() {
	cout << "\nThat tile is already filled. Enter alternative coordinates.\n\n" << endl;
}

void coordinateNotAtBorder() {
	cout << "\nThat coordinate is not at the border of the map. Enter valid coordinates.\n\n" << endl;
}

void constructPathMenu() {
	cout << "CONSTRUCT A PATH\n" << endl;
	cout << "Here are your options beginning from the STARTING point:\n" << endl;
	cout << "\tW - Up\n" << endl;
	cout << "\tS - Down\n" << endl;
	cout << "\tA - Left\n" << endl;
	cout << "\tD - Right\n" << endl;
	cout << "\tR - Remove previous path tile\n" << endl;
	cout << "\tE - Path completed\n\n\n" << endl;
}

void enterChoice() {
	cout << "\n\nEnter your choice: (w/s/a/d/r/e): ";
}

void pathOutOfBounds() {
	cout << "\nInvalid Coordinate. Out of Bounds\n" << endl;
}

void notEndPoint() {
	cout << "\nThe starting point cannot be the ending point!\nRedesign your path!\n" << endl;
}

void minimumPathLength(int minimumPathSize) {
	cout << "\nYour path must have at least " << minimumPathSize << " tiles!\nRedesign your path!\n" << endl;
}

void endingPointNotAtBorder() {
	cout << "\nThis cannot be an ending point! It has to be at a border.\nEither remove path tiles or redesign your path!\n" << endl;
}

void invalidInput() {
	cout << "\nInvalid Input. Try again\n";
}

void enterCoordinate2(string type) {
	cout << "Enter the " << type << " coordinate: ";
}

void invalidCoordinates() {
	cout << "\nInvalid coordinates. Enter the correct values." << endl;
}

void towerDisplayMessage() {
	cout << "Below is a view of your towers on the map:\n" << endl;
}

void cannotRemoveStartingTile() {
	cout << "\nCannot remove the starting path tile!\n" << endl;
}

void successRemoveStartingTile() {
	cout << "\nSuccessfully removed the tile!\n\n" << endl;
}

void askUserIfSaveMap() {
	cout << "\nWould you like to save the map? (y/n): ";
}

void mapSaveSuccess() {
	cout << "\n\nMap Saved Successfully!\n\n" << endl;
}