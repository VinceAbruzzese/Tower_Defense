//---------------------------------------------------------------------
//  Vince Abruzzese
//  Class: TowerRangeDisplay
//---------------------------------------------------------------------
//  This class will be used as an observer for the Tower class. We
//  will be able to see what kind of range the tower has
//---------------------------------------------------------------------

#ifndef RANGE_DISPLAY_H
#define RANGE_DISPLAY_H

#include "Observer.h"
#include "Tower.h"

class TowerRangeDisplay : public Observer
{

public:
	TowerRangeDisplay(Tower* tower);
	virtual ~TowerRangeDisplay(){}
	void update();

private:
	Tower* tower;
};

#endif