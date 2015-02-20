#include "ErrorHandling.h"

void ErrorHandling::testIntStringInput(string x, int start, int end)
{

	bool found = false;

	int newX = atoi(x.c_str());

	for (int i = start; i <= end; i++)
	{
		if (newX == i)
		{
			found = true;
		}
	}

	if (!found)
	{
		throw string("Invalid input, please enter a correct value: ");
	}
}

void ErrorHandling::testDigitString(string s)
{
	regex e("[0-9]*");

	if (!regex_match(s, e))
	{
		throw string("Invalid input, please enter a correct value: ");
	}
}

void ErrorHandling::testTowerCoordinates(int x, int y, int length, int width)
{
	if (x < 0 || y < 0 || x > (length) || y > (width))
	{
		throw string("Wrong Coordinates, please enter the correct values : ");
	}
}

void ErrorHandling::testStartCoordinates(int x, int y, int length, int width)
{
	if (x < 0 || y < 0 || x > (length - 1) || y > (width - 1))
	{
		throw string("Wrong Starting Coordinates, please enter a correct value (must be placed at border of map) : ");
	}
}

void ErrorHandling::testBorder(int x, int y, int length, int width)
{

	bool testBorder = false;

	if (x == 0 || y == 0 || x == (length - 1) || y == (width - 1))
	{
		testBorder = true;
	}

	if (!testBorder)
	{
		throw string("Wrong Coordinates, Starting point must be at border ");
	}
}


void ErrorHandling::testTowerChoosingOption(string s, int x)
{
	int newS = atoi(s.c_str());

	regex e("[0-9]*");

	if (!regex_match(s, e))
	{
		throw string("Invalid input, please enter a correct value: ");
	}
	else if (newS < 0 || newS > x)
	{
		throw string("Invalid input, please enter a correct value: ");
	}
}

void ErrorHandling::testYesNo(string s)
{
	if (s != "y" && s != "n")
	{
		throw string("Wrong Input - Please Try Again");
	}
}

void ErrorHandling::checkAvailableMaps()
{
	system("dir \Maps /b > MapsList.txt");

	ifstream MapsNumber("MapsList.txt");

	int lineNum = 0;

	string s;

	while (!MapsNumber.eof())
	{
		getline(MapsNumber, s);

		if (s.size() != 0)
		{
			lineNum++;
		}
	}

	if (lineNum == 0)
	{
		throw string("No Maps Found - You need to Create one first then save it.");
	}

}


void ErrorHandling::checkMapName(string mName)
{
	system("dir \Maps /b > MapsList.txt");

	ifstream MapsNumber("MapsList.txt");

	string s;
	int value = 0;

	bool found = false;

	while (!MapsNumber.eof())
	{
		getline(MapsNumber, s);

		if (s == mName + ".txt")
		{
			found = true;
		}
	}

	if (!found)
	{
		throw string("Map Entered has not been found - please try again.");
	}
}

void ErrorHandling::testMapRange(int length, int width)
{
	if (!(((length >= 10) && (length <= 15)) && ((width >= 10) && (width <= 15))))
	{
		throw string("Error . The Length & Width must be between 10-15 . Please try Again");
	}
}