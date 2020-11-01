/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 3 - Vampire class implementation file.  Includes the attack and defense functions for the
**  vampire class.  Also includes the charm ability where the vampire does not take any damage.
*******************************************************************************************************************/

#include "Vampire.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Vampire::Vampire() : Character() {
	//set armor to 1
	setArmor(1);
	//set strength points to 18
	setStrengthPoints(18);
	//initialize random so that it isn't the same every time the program runs
	srand(time(0));
}

//attack function
int Vampire::attackSomething() {
	//create a random 12-sided die roll
	dieRoll = rand() % 12 + 1;
	//print out the die roll result
	std::cout << "Die roll: " << dieRoll << std::endl;
	//set attack equal to the die roll
	setAttack(dieRoll);
	//print out the total attack
	std::cout << "Total Attack: " << getAttack() << std::endl;
	//return the total attack
	return getAttack();
}

//this is the defend function
void Vampire::defend(int attackNumber) {
	//figures out the defense
	dieRoll = rand() % 6 + 1;
	//flips a coin to calculate the 50/50 chance of charming opponent
	coinFlip = rand() % 2 + 1;
	//the opponent attacks for the normal amount
	std::cout << "Vampire Strength Points before defending: " << getStrengthPoints() << std::endl;
	std::cout << "Vampire Armor: " << getArmor() << std::endl;

	//vampire defends (50% chance)
	if (coinFlip == 1) {
		//print out result of die roll
		std::cout << "Defense Die Roll: " << dieRoll << std::endl;
		//set defense equal to the die roll
		setDefense(dieRoll);
		//print out the amount the vampire defends for
		std::cout << "Vampire defends for " << getDefense() << std::endl;
		//If the attacked amount, minus the defense and armor is greater than zero
		if (attackNumber - (getDefense() + getArmor()) > 0) {
			//update strength points
			setStrengthPoints(getStrengthPoints() - attackNumber + getDefense() + getArmor());
			//print out the total damage inflicted
			std::cout << "The total damage inflicted is: " << attackNumber - (getDefense() + getArmor()) << std::endl;;
		}
		//if there is no damage to assign
		else {
			//print out the damage inflicted is zero
			std::cout << "The total damage inflicted is: " << 0 << std::endl;
		}
	}
	//the opponent was charmed and doesn't actually attack
	else if (coinFlip == 2) {
		//vampire uses its charm ability and doesn't take any damage
		std::cout << "The opponent was charmed and did not actually attack!" << std::endl;
	}
	//print out the vampire's strength point total
	std::cout << "Vampire has " << getStrengthPoints() << " strength points." << std::endl;
}

//returns the character's type as a string
std::string Vampire::getType() {
	return "Vampire";
}

//recovery function for team battles
void Vampire::recover() {
	//recovers 50% of the health lost in the battle
	setStrengthPoints(getStrengthPoints() + (18 - getStrengthPoints()) / 2);
}