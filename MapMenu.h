//--------------------------------------------------------------
//  Vince Abruzzese
//  MapMenu.h
//--------------------------------------------------------------
//  The MapMenu.h file is used for the initial setup of the map
//  to avoid congestion in the driver, we have seperated the 
//  methods into its own class
//--------------------------------------------------------------

#ifndef MAP_MENU_H
#define MAP_MENU_H

#include "Map.h"
#include "MapEditor.h"
#include "Gameplay.h"
#include "SaveMap.h"
#include "LoadMap.h"
#include "ErrorHandling.h"

void customMapOptions(Map* map, ErrorHandling* errorObj);

void display_map_options();

void map_menu(int& length, int& width, string& custom, Map* &mapObj, MapEditor* &mapEditorObj, string& loadmap, string mapName, SaveMap* saveMapObj, LoadMap* loadMapObj, ErrorHandling* errorObj);

void loadSavedMap(string& loadmap, LoadMap* loadMapObj, SaveMap* saveMapObj, string mapName, Map* &mapObj, MapEditor* &mapEditorObj, ErrorHandling* errorObj, string& custom, int& length, int& width);

void createCustomMap(string& custom, int& length, int& width, Map* &mapObj, MapEditor* &mapEditorObj, ErrorHandling* errorObj, SaveMap* saveMapObj);

void createDefaultMap(Map* &mapObj, MapEditor* &mapEditorObj);

#endif MAP_MENU_H