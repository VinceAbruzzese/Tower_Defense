//--------------------------------------------------------------
//  Vince Abruzzese
//  Class: Observable
//--------------------------------------------------------------

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include "Observer.h"
#include <list>

using namespace std;

class Observable {

public:

	/** Contructor, destructor **/
	Observable();
	virtual ~Observable();

	/** Observable related methods **/
	void addObserver(Observer* obs);
	void removeObserver(Observer* obs);

protected:

	/** Observable related methods **/
	void notify() const;

private:

	/** instance variables **/
	list<Observer*>* observers;
};

#endif 
