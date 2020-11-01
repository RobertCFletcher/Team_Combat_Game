/**********************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - Medusa class header file.  Includes the attack and defense functions for the
**  Medusa class.  Includes two variables for die rolls.
**********************************************************************************************************/
#include "Character.hpp"

#ifndef MEDUSA_HPP
#define	MEDUSA_HPP
class Medusa : public Character {

private:
	//two die rolls
	int dieRoll1;
	int dieRoll2;

public:
	Medusa();
	//attack function
	int attackSomething();
	//defense function (takes an attack value as a parameter)
	void defend(int attackNumber);
	//returns the character's type as a string
	std::string getType();
	void recover();
};
#endif