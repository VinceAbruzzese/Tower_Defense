#include "TowerRangeDisplay.h"

TowerRangeDisplay::TowerRangeDisplay(Tower* tower)
{
	this->tower = tower;
}

void TowerRangeDisplay::update()
{
	int range = tower->getRange();

	cout << "------------------------------------" << endl;
	cout << "Here is the range of your tower:" << endl;
	cout << "------------------------------------\n" << endl;

	//Top half of range
	for (int i = 0; i < range; i++)
	{
		for (int k = 0; k < range - i; k++)
			cout << "   ";

		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << " * ";
		}
		cout << endl;
	}

	//Middle part of range
	for (int i = 0; i < range; i++)
		cout << " * ";
	cout << " T ";
	for (int i = 0; i < range; i++)
		cout << " * ";
	cout << endl;

	int temp = 0;
	//Bottom half of range
	for (int i = range; i > 0; i--)
	{
		for (int k = 0; k <= temp; k++)
			cout << "   ";

		for (int j = 0; j < i * 2 - 1; j++)
		{
			cout << " * ";
		}
		cout << endl;
		temp++;
	}


}