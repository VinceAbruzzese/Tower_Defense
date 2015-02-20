//--------------------------------------------------------------
//  Vince Abruzzese
//  Gameplay.h
//--------------------------------------------------------------
//  The Gameplay.h file will contain all the methods we use 
//  during the rounds. This will include tower detection, 
//  critters moving on the map, etc.
//--------------------------------------------------------------

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Critter.h"
#include "Timer.h"
#include <string>
#include <vector>
#include "Tower.h"
#include "Session.h"
#include "TowerMenu.h"
#include <iostream>
#include "TowerRangeDisplay.h"
#include "ErrorHandling.h"
#include <Windows.h>
#include "Map.h"
#include "MapEditor.h"

using namespace std;

void welcome_message();

void check_for_spawn(Timer &timer, vector<Critter*> &critter_list, vector<Coordinate> &path, Map* &map, int &critter_count, int level, float spawn_rate, int &critter_type);

void clean_critter_list(vector<Critter*> &critter_list, int path_size, Session &session);

int get_spawn_quantity(int round);

int get_reward(int round);

void pause_menu(Session &session, vector<Tower*> &tower_list, int &list_size, bool &start, Map* &map, vector<Critter*> &critter_list, ErrorHandling* &errorObj);

void pause_all_timers(vector<Critter*> &critter_list, vector<Tower*> &tower_list, Timer &spawn_timer);

void resume_all_timers(vector<Critter*> &critter_list, vector<Tower*> &tower_list, Timer &spawn_timer);

void game_over(Session &session);

void critter_interface(vector<Critter*> &critter_list);

void start_next_round(vector<Coordinate> &path, vector<Critter*> &critter_list, Map* &map, MapEditor* &display, vector<Tower*> &tower_list, Session &session, int &list_size, bool &start, ErrorHandling* &errorObj);


#endif
//End of Gameplay.h