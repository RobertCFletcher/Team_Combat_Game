/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 3 - BlueMen class implementation file.  Includes the attack and defense functions for the
**  blue men.
*******************************************************************************************************************/

#include "BlueMen.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

BlueMen::BlueMen() : Character() {
	//set armor to 3
	setArmor(3);
	//set strength points to 12
	setStrengthPoints(12);
	//initialize random so that it isn't the same every time the program runs
	srand(time(0));
}

//attack function for the BlueMen class
int BlueMen::attackSomething() {
	//create two random 10 sided die rolls
	dieRoll1 = rand() % 10 + 1;
	dieRoll2 = rand() % 10 + 1;
	//print out the die rolls
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	std::cout << "Die roll 2: " << dieRoll2 << std::endl;
	//set attack to the sum of the two die rolls
	setAttack(dieRoll1 + dieRoll2);
	//print out the total attack
	std::cout << "Total Attack: " << getAttack() << std::endl;
	//return the attack for the BlueMen
	return getAttack();
}

//defense function for the blue men class
void BlueMen::defend(int attackNumber) {
	//print out strength points and armor before defending
	std::cout << "Blue Men Strength Points Before Defending: " << getStrengthPoints() << std::endl;
	std::cout << "Blue Men Armor: " << getArmor() << std::endl;

	//if blue men are greater than 8, three die rolls
	if (getStrengthPoints() > 8) {
		//create three random 6-sided die rolls
		dieRoll1 = rand() % 6 + 1;
		dieRoll2 = rand() % 6 + 1;
		dieRoll3 = rand() % 6 + 1;
		//print out the three die rolls
		std::cout << "Die roll 1: " << dieRoll1 << std::endl;
		std::cout << "Die roll 2: " << dieRoll2 << std::endl;
		std::cout << "Die roll 3: " << dieRoll3 << std::endl;
		//set defense to the three die rolls combined
		setDefense(dieRoll1 + dieRoll2 + dieRoll3);
		//print out the defense
		std::cout << "Blue Men defend for " << getDefense() << std::endl;
	}
	//if blue men are less than or equal to 8 but greater than 4, 2 die rolls
	else if (getStrengthPoints() <= 8 && getStrengthPoints() > 4) {
		//create two six-sided die rolls
		dieRoll1 = rand() % 6 + 1;
		dieRoll2 = rand() % 6 + 1;
		//print out the two die rolls
		std::cout << "Die roll 1: " << dieRoll1 << std::endl;
		std::cout << "Die roll 2: " << dieRoll2 << std::endl;
		//set defense to the sum of the two die rolls
		setDefense(dieRoll1 + dieRoll2);
		//print out the defense
		std::cout << "Blue Men defend for " << getDefense() << std::endl;
	}
	//if blue men are less than or equal to 4, only 1 die roll
	else if (getStrengthPoints() <= 4) {
		//create one six-sided die roll
		dieRoll1 = rand() % 6 + 1;
		//print out the die roll result
		std::cout << "Die roll 1: " << dieRoll1 << std::endl;
		//set defense equal to the result of the die roll
		setDefense(dieRoll1);
		//print out the defense
		std::cout << "Blue Men defend for " << getDefense() << std::endl;
	}

	//assign the damage to the blue men
	//if attacked amount, minus the defense and armor is greater than zero
	if (attackNumber - (getDefense() + getArmor()) > 0) {
		//set strength points
		setStrengthPoints(getStrengthPoints() - attackNumber + getDefense() + getArmor());
		//print out total damage inflicted
		std::cout << "The total damage inflicted is: " << attackNumber - (getDefense() + getArmor()) << std::endl;;
	}
	//if attack damage is less than defense and armor combined, no damage is assigned
	else {
		//print out the total damage inflicted
		std::cout << "The total damage inflicted is: " << 0 << std::endl;
	}

	//print out the strength points left for the blue men
	std::cout << "Blue men have " << getStrengthPoints() << " strength points." << std::endl;
}


//returns the character's type as a string
std::string BlueMen::getType() {
	return "Blue Men";
}

//recovery function for team battles
void BlueMen::recover() {
	//recovers 50% of the health lost in the battle
	setStrengthPoints(getStrengthPoints() + (12 - getStrengthPoints()) / 2);
}