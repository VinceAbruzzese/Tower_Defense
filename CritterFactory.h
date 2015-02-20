//----------------------------------------------------
//  Vince Abruzzese 
//  Class: CritterFactory
//----------------------------------------------------
// The CritterFactory class returns which critter to 
//  spawn. Depending on a couple things: what is 
//  the next type of critter to spawn and the strength
//  of the critter depending on the round
//----------------------------------------------------

#include "Critter.h"
#include "ArmorCritter.h"
#include "FireCritter.h"
#include "BossCritter.h"
#include "SpeedCritter.h"

class CritterFactory {
public:
	Critter* getCritter(vector<Coordinate> path, Map* map, int level, int critter_type);


};