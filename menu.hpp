/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/25/2018
**Description: Project 4 - header file for the menu class.  Creates a menu and allows the menu to be printed back
**  to the console.  Also includes input validation.  See various function descriptions for more info.
*******************************************************************************************************************/

#include <string>

#ifndef MENU_HPP
#define MENU_HPP

class menu {

private:
	int numberOfMenuItems;
	std::string menuItems[5];	//update based on biggest number of menu items
	int intInput;
	std::string userEntry;
	bool myLoop;
public:
	menu();
	//prints the menu to the console
	void printMenu();
	//sets a new menu item
	void setMenuItem(std::string menuItem);
	int getIntInput();
	int getRangeInput(int lowRange, int highRange);
};
#endif
