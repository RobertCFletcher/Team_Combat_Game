/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - Character class header file.  Includes the attack and defense functions for the
**  character as virtual functions, also includes various getters and setters for the private values.
*******************************************************************************************************************/
#include <string>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character {

private:
	//attack, defense, armor, strength points, and name
	int attack;
	int	defense;
	int armor;
	int strengthPoints;
	std::string name;

public:
	Character();
	//getters and setters
	void setAttack(int attackDieRoll);
	void setDefense(int defenseDieRoll);
	void setStrengthPoints(int someAttack);
	void setArmor(int armorNumber);
	void setName();
	int getAttack();
	int getDefense();
	int getArmor();
	int getStrengthPoints();
	std::string getName();
	//virtual defense function to make pure virtual
	virtual void defend(int attackNumber) = 0;
	//virtual function for attack
	virtual int attackSomething() = 0;
	//virtual function to get the character's type
	virtual std::string getType() = 0;
	//virtual function to recover points
	virtual void recover() = 0;
};
#endif