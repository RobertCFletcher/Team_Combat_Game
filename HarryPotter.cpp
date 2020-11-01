/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 3 - Harry Potter class implementation file.  Includes the attack and defense functions for
**  a Harry Potter character.
*******************************************************************************************************************/

#include "HarryPotter.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

HarryPotter::HarryPotter() : Character() {
	//set armor to zero
	setArmor(0);
	//set strength points to 8
	setStrengthPoints(10);
	//initialize random so that it isn't the same every time the program runs
	srand(time(0));
	//initialize the life counter to 1
	lifeCounter = 1;
}

//attack function for the Harry Potter class
int HarryPotter::attackSomething() {
	//create two random six-sided die rolls
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;
	//print out the result of the two die rolls
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	std::cout << "Die roll 2: " << dieRoll2 << std::endl;
	//set attack equal to the sum of the two die rolls
	setAttack(dieRoll1 + dieRoll2);
	//print out the total attack
	std::cout << "Total Attack: " << getAttack() << std::endl;
	//return the total attack
	return getAttack();
}

//defense function for the Harry Potter class
void HarryPotter::defend(int attackNumber) {
	//print out strength points and armor before defending
	std::cout << "Harry Potter Strength Points Before Defending: " << getStrengthPoints() << std::endl;
	std::cout << "Harry Potter Armor: " << getArmor() << std::endl;
	//create two random six-sided die rolls
	dieRoll1 = rand() % 6 + 1;
	dieRoll2 = rand() % 6 + 1;
	//print out the result of the two die rolls
	std::cout << "Die roll 1: " << dieRoll1 << std::endl;
	std::cout << "Die roll 2: " << dieRoll2 << std::endl;
	//set defense equal to sum of the two die rolls
	setDefense(dieRoll1 + dieRoll2);
	//print out the total defense
	std::cout << "Harry Potter defends for " << getDefense() << std::endl;

	//If the attacked amount, minus the defense and armor is greater than zero
	if (attackNumber - (getDefense() + getArmor()) > 0) {
		//update strength points
		setStrengthPoints(getStrengthPoints() - attackNumber + getDefense() + getArmor());
		//print out the total damage inflicted
		std::cout << "The total damage inflicted is: " << attackNumber - (getDefense() + getArmor()) << std::endl;;
	}
	//if the barbarian doesn't take any damage
	else {
		//print out that the total damage inflicted was 0
		std::cout << "The total damage inflicted is: " << 0 << std::endl;
	}

	//if Harry Potter would die for the first time, have him come back to life
	if (getStrengthPoints() <= 0 && lifeCounter > 0) {
		//print out that harry potter died and is coming back to life using Hogwarts
		std::cout << "Harry Potter died and has come back to life using Hogwarts!!!" << std::endl;
		//set the strength points to 20
		setStrengthPoints(20);
		//print out that Harry Potter has 20 strength points
		std::cout << "Harry Potter has " << getStrengthPoints() << " strength points." << std::endl;
		//decrement lifecounter 
		lifeCounter--;
	}
	//if Harry Potter wouldn't die or if he would die for the second time
	else {
		//print out Harry Potter's life strength points total
		std::cout << "Harry Potter has " << getStrengthPoints() << " strength points." << std::endl;
	}
}

//returns the type as a string
std::string HarryPotter::getType() {
	return "Harry Potter";
}

//recovery function for team battles
void HarryPotter::recover() {
	if (lifeCounter == 1) {
		//recovers 50% of the health lost in the battle
		setStrengthPoints(getStrengthPoints() + (10 - getStrengthPoints()) / 2);
	}
	else if (lifeCounter == 0) {
		//recovers 50% of health lost in the battle
		setStrengthPoints(getStrengthPoints() + (10 - getStrengthPoints()) / 2);
	}
}