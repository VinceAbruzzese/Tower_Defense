//---------------------------------------------------------------------
//  Vince Abruzzese
//  TowerDisplay.h
//---------------------------------------------------------------------
//  This file is used to separate the business logic from the Tower
//  implementation. All the functions we need to cout the tower for 
//  will be used here instead of the actual tower class
//---------------------------------------------------------------------

#ifndef TOWER_DISPLAY_H
#define TOWER_DISPLAY_H

#include "Tower.h"

//Info:
void towerInfo(int cost, int power, int range, float rate, bool upgrade);
void buyInfo(int type);
void upgradeInfo(Tower* tower);

//Current tower display
void viewTower(Tower* tower);

#endif