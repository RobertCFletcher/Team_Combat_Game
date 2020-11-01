/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - Harry Potter class header file.  Includes the attack and defense functions for the
**  Harry Potter class.  Includes two variables for die rolls and a life counter.
*******************************************************************************************************************/
#include "Character.hpp"
#include <string>

#ifndef HARRYPOTTER_HPP
#define	HARRYPOTTER_HPP
class HarryPotter : public Character {

private:
	//two die rolls
	int dieRoll1;
	int dieRoll2;
	//life counter
	int lifeCounter;

public:
	HarryPotter();
	//attack function
	int attackSomething();
	//defense function (takes an attack value as a parameter)
	void defend(int attackNumber);
	std::string getType();
	void recover();
};
#endif