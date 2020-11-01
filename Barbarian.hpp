/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - Barbarian class header file.  Includes the attack and defense functions for the
**  barbarian.  Includes two variables for die rolls.
*****************************************************************************************************************/

#include "Character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
class Barbarian : public Character {

private:
	//two die rolls
	int dieRoll1;
	int dieRoll2;

public:
	Barbarian();
	//attack function
	int attackSomething();
	//defense function (takes an attack value as a parameter)
	void defend(int attackNumber);
	//returns the type of the character as a string
	std::string getType();
	void recover();
};
#endif
