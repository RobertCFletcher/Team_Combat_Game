/*********************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - Vampire class header file.  Includes the attack and defense functions for the
**  vampire class.  Includes variable for die roll and for coin flip (50/50 chance for speial ability).
**********************************************************************************************************/

#include "Character.hpp"

#ifndef VAMPIRE_HPP
#define	VAMPIRE_HPP
class Vampire : public Character {

private:
	//die roll
	int dieRoll;
	//coin flip
	int coinFlip;
public:
	Vampire();
	//attack function
	int attackSomething();
	//defense function (takes an attack value as a parameter)
	void defend(int attackNumber);
	std::string getType();
	void recover();
};
#endif