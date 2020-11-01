/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 3 - Medusa class implementation file.  Includes the attack and defense functions for the
**  Medusa class.  Also includes a custom special ability for Medusa which turns the opponent to stone (glare)
*******************************************************************************************************************/

#include "Medusa.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Medusa::Medusa() : Character() {
	//set armor to 3
	setArmor(3);
	//set strength points to 8
	setStrengthPoints(8);
	//initialize random so that it isn't the same every time the program runs
	srand(time(0));
}

//attack function for the Medusa class
int Medusa::attackSomething() {
	//create two random six-sided die rolls
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;
	//print out the results of the die rolls
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	std::cout << "Die roll 2: " << dieRoll2 << std::endl;
	//if the sum of the die rolls is 12 activate Medusa's special ability
	if (dieRoll1 + dieRoll2 == 12) {
		//set attack to higher than anything can defend for (instant kill)
		setAttack(500);
		//print out that Medusa turns the opponent to stone
		std::cout << "Medusa uses Glare, instantly turning the opponent to stone!" << std::endl;
	}
	//if the sum is anything other than 12
	else {
		//set attack to the sum of the die rolls
		setAttack(dieRoll1 + dieRoll2);
		//print out the total attack
		std::cout << "Total Attack: " << getAttack() << std::endl;
	}
	//return total attack
	return getAttack();
}

//defense function
void Medusa::defend(int attackNumber) {
	//roll single six-sided die
	dieRoll1 = rand() % 6 + 1;
	//show Medusa strength points and armor before defending
	std::cout << "Medusa Strength Points Before Defending: " << getStrengthPoints() << std::endl;
	std::cout << "Medusa Armor: " << getArmor() << std::endl;
	//print out the result of the die roll
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	//set defense equal to the die roll
	setDefense(dieRoll1);
	//print out the amount that Medusa defends for
	std::cout << "Medusa defends for " << getDefense() << std::endl;

	//assign the damage to Medusa
	//If the attacked amount, minus the defense and armor is greater than zero
	if (attackNumber - (getDefense() + getArmor()) > 0) {
		//update the strength points value
		setStrengthPoints(getStrengthPoints() - attackNumber + getDefense() + getArmor());
		//print out the total damage inflicted
		std::cout << "The total damage inflicted is: " << attackNumber - (getDefense() + getArmor()) << std::endl;;
	}
	//if attack damage is less than defense and armor combined, no damage is assigned
	else {
		std::cout << "The total damage inflicted is: " << 0 << std::endl;
	}

	//print out the strength points left for the blue men
	std::cout << "Medusa has " << getStrengthPoints() << " strength points." << std::endl;
}


//returns the character's type as a string
std::string Medusa::getType() {
	return "Medusa";
}

//recovery function for team battles
void Medusa::recover() {
	//recovers 50% of the health lost in the battle
	setStrengthPoints(getStrengthPoints() + (8 - getStrengthPoints()) / 2);
}