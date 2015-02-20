
#include "Observable.h"

// Constructor
Observable::Observable() {
	observers = new list<Observer*>;
}

// Destructor
Observable::~Observable() {
	delete observers;
}

// adding an observer to list
void Observable::addObserver(Observer* obs) {

	//check if already in
	for (list<Observer*>::iterator i = observers->begin(); i != observers->end(); i++) {
		if (*i == obs)  // checking memory address
			return;
	}

	observers->push_back(obs);
}

// removing an observer from the list
void Observable::removeObserver(Observer* obs) {

	//check if already in
	for (list<Observer*>::iterator i = observers->begin(); i != observers->end(); i++) {
		if (*i == obs) { // checking memory address
			observers->remove(*i);
			return;
		}
	}
}

// notifying all observers
void Observable::notify() const {

	// updates every observer
	for (list<Observer*>::iterator i = observers->begin(); i != observers->end(); i++)
		(*i)->update();
}

