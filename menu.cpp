/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/25/2018
**Description: Project 4 - menu class implementation for the program.  Creates various menus, has a function to print
**  the menu to the console, and includes a way to validate that the user is entering an integer value.
*******************************************************************************************************************/

#include "menu.hpp"
#include <iostream>
#include <string>
#include <sstream>

menu::menu() {
	numberOfMenuItems = 0;
	intInput = 0;
	userEntry = "";
	myLoop = true;
}

//prints the menu to the console
void menu::printMenu() {
	for (int i = 0; i < numberOfMenuItems; i++) {
		std::cout << i + 1 << ": " << menuItems[i] << std::endl;
	}
}

//sets the menu item and allows for menu item manipulation
void menu::setMenuItem(std::string menuItem) {
	menuItems[numberOfMenuItems] = menuItem;
	numberOfMenuItems++;
}

//gets and validates input from the user for menu selections, etc..  Ensures the user is entering integers
int menu::getIntInput() {
	//resets the myLoop variable
	myLoop = true;
	//loops until a user enters valid input
	while (myLoop) {
		std::string s1;
		//gets the user's input
		std::getline(std::cin, s1);
		std::stringstream stream1(s1);
		//if the user's input is valid
		if (stream1 >> intInput && !(stream1 >> s1))
		{
			//print out a new line and stop the loop
			std::cout << std::endl;
			myLoop = false;
		}
		//if the user's input is invalid
		else {
			//print error message
			std::cout << "Please enter an integer value." << std::endl;
		}
	}
	//return the input if valid
	return intInput;
}


//Range input allows a user to specify an integer range for the verified input
int menu::getRangeInput(int lowRange, int highRange) {
	//resets the myLoop variable
	myLoop = true;
	//loops until a user enters valid input
	while (myLoop) {
		std::cin.clear();
		std::string s1;
		//gets the user's input
		std::getline(std::cin, s1);
		std::stringstream stream1(s1);
		//if the user's input is valid
		if (stream1 >> intInput && !(stream1 >> s1) && intInput >= lowRange && intInput <= highRange) {
			//print out a new line and stop the loop
			std::cout << std::endl;
			myLoop = false;
		}
		//if the user's input is invalid
		else {
			//print error message
			std::cout << "Please enter a valid integer value." << std::endl;
		}
	}
	//return the input if valid
	return intInput;
}