//--------------------------------------------------
//  Vince Abruzzese
//  Class: Observer
//--------------------------------------------------
//  The Observer class will be the base class for our
//  Tower Observer. We want to refresh the tower and
//  Check the values in its range to see if it can
//  find a critter to shoot at. This class is abstract
//  and contains only a pure virtual method update()
//--------------------------------------------------

#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
	virtual void update() = 0;
};

#endif
