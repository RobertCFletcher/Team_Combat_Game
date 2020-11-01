/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 3 - Barbarian class implementation file.  Includes the attack and defense functions for the
**  barbarian.
*******************************************************************************************************************/

#include "Barbarian.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Barbarian::Barbarian() : Character() {
	//set armor to 0
	setArmor(0);
	//set strength points to 12
	setStrengthPoints(12);
	//initialize random so that it isn't the same every time the program runs
	srand(time(0));
}

//attack function for the Barbarian class
int Barbarian::attackSomething() {
	//two random six sided die rolls
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;
	//print two die rolls
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	std::cout << "Die roll 2: " << dieRoll2 << std::endl;
	//set the attack equal to the two die rolls combined
	setAttack(dieRoll1 + dieRoll2);
	//print out the total attack
	std::cout << "Total Attack: " << getAttack() << std::endl;
	//return attack
	return getAttack();
}

//defense function for the barbarian class
void Barbarian::defend(int attackNumber) {
	//create two random six-sided die rolls
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;
	//print out strength points and armor before defending
	std::cout << "Barbarian Strength Points Before Defending: " << getStrengthPoints() << std::endl;
	std::cout << "Barbarian Armor: " << getArmor() << std::endl;
	//print out die rolls
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	std::cout << "Die roll 2: " << dieRoll2 << std::endl;
	//set defense equal to die roll amounts
	setDefense(dieRoll1 + dieRoll2);
	//print out how much Barbarian defends for
	std::cout << "Barbarian defends for " << getDefense() << std::endl;

	//If the attacked amount, minus the defense and armor is greater than zero
	if (attackNumber - (getDefense() + getArmor()) > 0) {
		//update the strength points
		setStrengthPoints(getStrengthPoints() - attackNumber + getDefense() + getArmor());
		//print out total damage inflicted
		std::cout << "The total damage inflicted is: " << attackNumber - (getDefense() + getArmor()) << std::endl;;
	}
	//if the barbarian doesn't take any damage
	else {
		//print out that the total damage inflicted was zero
		std::cout << "The total damage inflicted is: " << 0 << std::endl;
	}

	//print out total strength points after defending
	std::cout << "Barbarian has " << getStrengthPoints() << " strength points." << std::endl;
}

//returns the type of character as a string
std::string Barbarian::getType() {
	return "Barbarian";
}

//recovery function for team battles
void Barbarian::recover() {
	//recovers 50% of the health lost in the battle
	setStrengthPoints(getStrengthPoints() + (12 - getStrengthPoints()) / 2);
}