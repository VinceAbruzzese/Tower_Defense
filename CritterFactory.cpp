#include "CritterFactory.h"

Critter* CritterFactory::getCritter(vector<Coordinate> path, Map* map, int level, int critter_type){
	
	if ((level == 3) || (level == 6) || (level == 10)) //Boss is created every 3 waves
		return BossCritter::Instance(path, map, level);
	
	else 
	{
		switch (critter_type) //Spawns a different critter each time
		{
		case 0:
			return new SpeedCritter(path, map, level); 
		case 1:
			return new FireCritter(path, map, level);
		case 2:
			return new ArmorCritter(path, map, level);
		}

	}
}