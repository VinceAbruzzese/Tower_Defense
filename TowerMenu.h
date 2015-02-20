//--------------------------------------------------------------
//  Vince Abruzzese
//  TowerMenu.h
//--------------------------------------------------------------
// The TowerMenu h and cpp file will include all the methods we
// will use in the Driver.cpp file. This is to avoid confusion 
// and not have them all in the same cpp file
//--------------------------------------------------------------

#ifndef TOWER_MENU_H
#define TOWER_MENU_H

#include "Tower.h"
#include "ErrorHandling.h"
#include "ArrowTower.h"
#include "FireTower.h"
#include "IceTower.h"
#include "Session.h"
#include <vector>
#include <memory>
#include <string>
#include <limits>

//Main Menu Methods
int action(Session &session, string type, ErrorHandling* &errorObj);

//Buy Methods
int buy_option(Session &session, ErrorHandling* &errorObj);
void buy_tower(int type, vector<Tower*> &tower_list, Session &session);
bool display_buy_message(int type, int &list_size, vector<Tower*> &tower_list, Session &session);

//Sell Methods
int sell_option(int list_size, vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj);
void sell_tower(int selling_index, vector<Tower*> &tower_list);
void sell_message(int selling_index, vector<Tower*> &tower_list, Session &session);

//Upgrade Methods
int upgrade_option(int list_size, vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj);
void upgrade_tower(int upgrading_index, vector<Tower*> &tower_list, Session &session);

//Information Methods
int get_tower_info(Session &session, ErrorHandling* &errorObj);
string get_tower_type(int type);
void display_tower_list(vector<Tower*> &tower_list, string type);
int display_option(vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj);

//Strategy Pattern
void attack_strategy_option(vector<Tower*> &tower_list, Session &session, ErrorHandling* &errorObj);

//Other
bool get_confirmation(int type, Session &session, string option, ErrorHandling* &errorObj);
void display_session(Session &session);
void print_tower_list(vector<Tower*> &tower_list);

//Main Menu method. Implements all the methods above
void tower_menu(Session &session, vector<Tower*> &tower_list, int &list_size, bool &start, Map* map, string type, ErrorHandling* &errorObj);

#endif 
//End of TowerMenu.h

