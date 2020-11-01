/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - Blue Men class header file.  Includes the attack and defense functions for the
**  blue men.  Includes two variables for die rolls.
*******************************************************************************************************************/

#include "Character.hpp"

#ifndef BLUEMEN_HPP
#define	BLUEMEN_HPP
class BlueMen : public Character {

private:
	//three die rolls
	int dieRoll1;
	int dieRoll2;
	int dieRoll3;

public:
	BlueMen();
	//attack function
	int attackSomething();
	//defense function (takes an attack value as a parameter)
	void defend(int attackNumber);
	//returns the character's type as a string
	std::string getType();
	void recover();
};
#endif
