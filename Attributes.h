//--------------------------------------------
//  Vince Abruzzese 
//  Attributes.h
//--------------------------------------------
//  The Attributes header contains all the
//  information of the attributes in the game.
//  this includes towers, critters, gold, etc.
//--------------------------------------------

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

///////////////////////////////////////////////////
// Session Attributes
///////////////////////////////////////////////////

int const NUMBER_OF_LIVES = 20;
int const STARTING_GOLD = 75;
int const MAX_NUMBER_OF_ROUNDS = 10;

///////////////////////////////////////////////////
// Tower Attributes
///////////////////////////////////////////////////
//Selling - Will receive 60% back
//Range = Amount of array tiles away it can reach
//Power = Damage inflicted on monster
//Rate = Speed at which it attacks
///////////////////////////////////////////////////

//_____________________________________________
//Values of Arrow Tower:
//_____________________________________________

//CS = (Critical Strike) chance it does double damage

//Level 1
int const ARROW_COST_1 = 10;
int const ARROW_SELL_1 = 6;
int const ARROW_RANGE_1 = 3;
int const ARROW_POWER_1 = 10;
float const ARROW_RATE_1 = 1.25f; //Rate is better when lower
float const ARROW_CS_PERCENTAGE_1 = 0.10f;

//Level 2
int const ARROW_COST_2 = 15; //Upgrade cost (total value = 25)
int const ARROW_SELL_2 = 15;
int const ARROW_RANGE_2 = 4;
int const ARROW_POWER_2 = 20;
float const ARROW_RATE_2 = 1.0f;
float const ARROW_CS_PERCENTAGE_2 = 0.15f;

//Level 3
int const ARROW_COST_3 = 30; //total value = 55
int const ARROW_SELL_3 = 33;
int const ARROW_RANGE_3 = 5;
int const ARROW_POWER_3 = 30;
float const ARROW_RATE_3 = 0.75f;
float const ARROW_CS_PERCENTAGE_3 = 0.25f;

//_____________________________________________
//Values of Fire Tower:
//_____________________________________________

//Splash = Area in which multiple monsters are hit

//Level 1
int const FIRE_COST_1 = 15;
int const FIRE_SELL_1 = 9;
int const FIRE_RANGE_1 = 2;
int const FIRE_POWER_1 = 8;
float const FIRE_RATE_1 = 1.5f;

//Level 2
int const FIRE_COST_2 = 20; //total value = 35
int const FIRE_SELL_2 = 21;
int const FIRE_RANGE_2 = 3;
int const FIRE_POWER_2 = 16;
float const FIRE_RATE_2 = 1.25f;

//Level 3
int const FIRE_COST_3 = 40; //total value = 75
int const FIRE_SELL_3 = 45;
int const FIRE_RANGE_3 = 4;
int const FIRE_POWER_3 = 32;
float const FIRE_RATE_3 = 1.0f;

//_____________________________________________
//Values of Ice Tower:
//_____________________________________________

//Slow Rate = percentage is which critter speed is reduced
//Slow Duration = how long they will be slowed down

//Level 1
int const ICE_COST_1 = 25;
int const ICE_SELL_1 = 15;
int const ICE_RANGE_1 = 1;
int const ICE_POWER_1 = 8;
float const ICE_RATE_1 = 2.0f;
float const ICE_SLOW_RATE_1 = 1.5f; //Make 1.5 times slower
float const ICE_SLOW_DURATION_1 = 3.0f; //Last 3 seconds

//Level 2
int const ICE_COST_2 = 20; //total value = 45
int const ICE_SELL_2 = 27;
int const ICE_RANGE_2 = 2;
int const ICE_POWER_2 = 12;
float const ICE_RATE_2 = 1.75f;
float const ICE_SLOW_RATE_2 = 2.0f;
float const ICE_SLOW_DURATION_2 = 4.0f;

//Level 3
int const ICE_COST_3 = 25; //total value = 70
int const ICE_SELL_3 = 42;
int const ICE_RANGE_3 = 3;
int const ICE_POWER_3 = 18;
float const ICE_RATE_3 = 1.50f;
float const ICE_SLOW_RATE_3 = 2.5f;
float const ICE_SLOW_DURATION_3 = 6.0f;

///////////////////////////////////////////////////
// Critter Attributes
///////////////////////////////////////////////////

//Level Common:
float const ARMOR_LEVEL_SPEED = 2.2f;
float const FIRE_LEVEL_SPEED = 1.8f;
float const SPEED_LEVEL_SPEED = 1.6f;
float const BOSS_LEVEL_SPEED = 2.8f;
float const SPAWN_RATE = 2.5f;

//Level 1 Critters

//Armor:
int const ARMOR_LEVEL_1_HP = 150;
float const ARROW_RESISTANCE_LEVEL_1 = 0.75f; //receive 75% of attack

//Fire:
int const FIRE_LEVEL_1_HP = 120;
float const FIRE_RESISTANCE_LEVEL_1 = 0.75f; //receive only 75% of attack
float const ARROW_WEAKNESS_LEVEL_1 = 0.30f; //30% extra damage

//Speed:
int const SPEED_LEVEL_1_HP = 80;

//Common:
int const LEVEL_1_STRENGTH = 1;
int const LEVEL_1_REWARD = 4;
int const LEVEL_1_QUANTITY = 9; //three of each critter
int const ROUND_1_REWARD = 10;

//Level 2 Critters

//Armor:
int const ARMOR_LEVEL_2_HP = 250;
float const ARROW_RESISTANCE_LEVEL_2 = 0.70f; //receive 70% of attack

//Fire:
int const FIRE_LEVEL_2_HP = 220;
float const FIRE_RESISTANCE_LEVEL_2 = 0.70f; //receive only 70% of attack
float const ARROW_WEAKNESS_LEVEL_2 = 0.25f; //25% extra damage

//Speed:
int const SPEED_LEVEL_2_HP = 280;

//Common:
int const LEVEL_2_STRENGTH = 2;
int const LEVEL_2_REWARD = 6;
int const LEVEL_2_QUANTITY = 12; //four of each critter
int const ROUND_2_REWARD = 15;
//Level 3 BOSS

//Boss :
int const BOSS_LEVEL_3_HP = 2000;
float const FIRE_RESISTANCE_LEVEL_3 = 0.70f; //receive only 70% of attack
float const ICE_RESISTANCE_LEVEL_3 = 0.70f; //receive only 70% of attack
float const ARROW_RESISTANCE_LEVEL_3 = 0.70f; //receive only 70% of attack

//Common:
int const LEVEL_3_STRENGTH = 5;
int const LEVEL_3_REWARD = 50;
int const LEVEL_3_QUANTITY = 1;
int const ROUND_3_REWARD = 20;

//Level 4 Critters

//Armor:
int const ARMOR_LEVEL_4_HP = 350;
float const ARROW_RESISTANCE_LEVEL_4 = 0.65f; //receive 65% of attack

//Fire:
int const FIRE_LEVEL_4_HP = 320;
float const FIRE_RESISTANCE_LEVEL_4 = 0.65f; //receive only 65% of attack
float const ARROW_WEAKNESS_LEVEL_4 = 0.20f; //20% extra damage

//Speed:
int const SPEED_LEVEL_4_HP = 380;

//Common:
int const LEVEL_4_STRENGTH = 3;
int const LEVEL_4_REWARD = 8;
int const LEVEL_4_QUANTITY = 15; //five of each critter
int const ROUND_4_REWARD = 25;
//Level 5 Critters

//Armor:
int const ARMOR_LEVEL_5_HP = 450;
float const ARROW_RESISTANCE_LEVEL_5 = 0.60f; //receive 60% of attack

//Fire:
int const FIRE_LEVEL_5_HP = 420;
float const FIRE_RESISTANCE_LEVEL_5 = 0.60f; //receive only 60% of attack
float const ARROW_WEAKNESS_LEVEL_5 = 0.15f; //15% extra damage

//Speed:
int const SPEED_LEVEL_5_HP = 480;

//Common:
int const LEVEL_5_STRENGTH = 3;
int const LEVEL_5_REWARD = 8;
int const LEVEL_5_QUANTITY = 15; //five of each critter
int const ROUND_5_REWARD = 30;
//Level 6 BOSS

//Boss :
int const BOSS_LEVEL_6_HP = 6666;
float const FIRE_RESISTANCE_LEVEL_6 = 0.60f; //receive only 60% of attack
float const ICE_RESISTANCE_LEVEL_6 = 0.60f; //receive only 60% of attack
float const ARROW_RESISTANCE_LEVEL_6 = 0.60f; //receive only 60% of attack

//Common:
int const LEVEL_6_STRENGTH = 10;
int const LEVEL_6_REWARD = 100;
int const LEVEL_6_QUANTITY = 1;
int const ROUND_6_REWARD = 40;
//Level 7 Critters

//Armor:
int const ARMOR_LEVEL_7_HP = 550;
float const ARROW_RESISTANCE_LEVEL_7 = 0.55f; //receive 55% of attack

//Fire:
int const FIRE_LEVEL_7_HP = 520;
float const FIRE_RESISTANCE_LEVEL_7 = 0.55f; //receive only 55% of attack
float const ARROW_WEAKNESS_LEVEL_7 = 0.10f; //10% extra damage

//Speed:
int const SPEED_LEVEL_7_HP = 580;

//Common:
int const LEVEL_7_STRENGTH = 4;
int const LEVEL_7_REWARD = 10;
int const LEVEL_7_QUANTITY = 18; //six of each critter
int const ROUND_7_REWARD = 50;
//Level 8 Critters

//Armor:
int const ARMOR_LEVEL_8_HP = 650;
float const ARROW_RESISTANCE_LEVEL_8 = 0.50f; //receive 50% of attack

//Fire:
int const FIRE_LEVEL_8_HP = 620;
float const FIRE_RESISTANCE_LEVEL_8 = 0.50f; //receive only 50% of attack
float const ARROW_WEAKNESS_LEVEL_8 = 0.5f; //5% extra damage

//Speed:
int const SPEED_LEVEL_8_HP = 680;

//Common:
int const LEVEL_8_STRENGTH = 5;
int const LEVEL_8_REWARD = 12;
int const LEVEL_8_QUANTITY = 21; //seven of each critter
int const ROUND_8_REWARD = 60;

//Level 9 Critters

//Armor:
int const ARMOR_LEVEL_9_HP = 750;
float const ARROW_RESISTANCE_LEVEL_9 = 0.45f; //receive 45% of attack

//Fire:
int const FIRE_LEVEL_9_HP = 720;
float const FIRE_RESISTANCE_LEVEL_9 = 0.45f; //receive only 45% of attack
float const ARROW_WEAKNESS_LEVEL_9 = 0.5f; //5% extra damage

//Speed:
int const SPEED_LEVEL_9_HP = 880;

//Common:
int const LEVEL_9_STRENGTH = 6;
int const LEVEL_9_REWARD = 14;
int const LEVEL_9_QUANTITY = 24; //eight of each critter
int const ROUND_9_REWARD = 70;

//Level 10 BOSS

//Boss :
int const BOSS_LEVEL_10_HP = 66666;
float const FIRE_RESISTANCE_LEVEL_10 = 0.50f; //receive only 50% of attack
float const ICE_RESISTANCE_LEVEL_10 = 0.50f; //receive only 50% of attack
float const ARROW_RESISTANCE_LEVEL_10 = 0.50f; //receive only 50% of attack

//Common:
int const LEVEL_10_STRENGTH = 15;
int const LEVEL_10_REWARD = 1000000;
int const LEVEL_10_QUANTITY = 1;
int const ROUND_10_REWARD = 1000000;

///////////////////////////////////////////////////
//  Map Attributes
///////////////////////////////////////////////////

const int DEFAULT_VALUE_MIN = 15;
const int DEFAULT_VALUE_MAX = 35;

///////////////////////////////////////////////////
//  Observer Attributes
///////////////////////////////////////////////////

int const MAX_OBSERVERS = 5;



#endif
//End of Attributes.h