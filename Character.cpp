/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 3 - Character class implementation file.  Includes all of the getters and setters for all
**  of the base character values; attack, defense, armor, and strength points.
*******************************************************************************************************************/
#include <string>
#include "Character.hpp"
#include <iostream>

Character::Character() {
	//set base attack = 0
	attack = 0;
	//set base defense = 0
	defense = 0;
	//set base armor = 0
	armor = 0;
	//set base strength points = 0
	strengthPoints = 0;
	//set name equal to an empty string
	name = "";
}

//set attack
void Character::setAttack(int attackDieRoll) {
	attack = attackDieRoll;
}

//set defense
void Character::setDefense(int defenseDieRoll) {
	defense = defenseDieRoll;
}

//set strength points
void Character::setStrengthPoints(int strengthPointsNumber) {
	strengthPoints = strengthPointsNumber;
}

//set armor
void Character::setArmor(int armorNumber) {
	armor = armorNumber;
}

//get attack
int Character::getAttack() {
	return attack;
}

//get defense
int Character::getDefense() {
	return defense;
}

//get armor
int Character::getArmor() {
	return armor;
}

//get strength points
int Character::getStrengthPoints() {
	return strengthPoints;
}

//set name
void Character::setName() {
	std::cout << "Please enter the character's name: ";
	std::getline(std::cin, name);
	std::cout << std::endl;
}

//get name
std::string Character::getName() {
	return name;
}
