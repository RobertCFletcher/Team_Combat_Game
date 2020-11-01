/*****************************************************************************************************************
**Name: Robert Fletcher
**Course: CS162
**Date: 02/17/2018
**Description: Project 4 - main file for the program.  This program implements a team fighting game, where two teams
**  of characters fight each other until one of the teams is depleted.  The program outputs all of the info from each
**  fight and then outputs the final scores at the end and the winner of the game.
*******************************************************************************************************************/

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Queue.hpp"
#include "menu.hpp"
#include <iostream>
#include <ctime>

int main() {

	/*********************************************************************
	**Set up the different queues and variables for scores and input
	*********************************************************************/

	Queue q, q2, loserPile;
	//keeps the game running as long as the user doesn't choose to exit
	int gameMenuSelection = 0;
	//number of characters per player determined by the user
	int numberOfCharactersP1 = 0;
	int numberOfCharactersP2 = 0;
	int characterMenuSelection = 0;
	int loserMenuSelection = 0;
	int p1Score = 0;
	int p2Score = 0;
	int roundCounter = 1;
	int numberOfLosers = 0;



	/**************************************************
	**Set up the various menus for the program
	**************************************************/

	menu m1, m2, m3, m4;
	m1.setMenuItem("Play Game");
	m1.setMenuItem("Quit");

	m2.setMenuItem("Barbarian");
	m2.setMenuItem("Blue Men");
	m2.setMenuItem("Harry Potter");
	m2.setMenuItem("Medusa");
	m2.setMenuItem("Vampire");

	m3.setMenuItem("Print Loser Pile");
	m3.setMenuItem("Don't Print Loser Pile");

	m4.setMenuItem("Play Again");
	m4.setMenuItem("Quit");



	/**********************************************************************************
	**Check whether the user wants to play the game or not
	**********************************************************************************/

	//print out the intro menu
	m1.printMenu();
	//this is the game loop.  If user chooses option 2 to quit, the game will end
	while (gameMenuSelection != 2) {
		gameMenuSelection = m1.getRangeInput(1,2);
		//if the user chooses to play game
		if (gameMenuSelection == 1) {
			//reset both player's scores to 0
			p1Score = 0;
			p2Score = 0;
			numberOfLosers = 0;



			/*************************************************************************
			**Get the number of characters on each team
			*************************************************************************/

			//ask user for number of characters for player1
			std::cout << "Please enter the number of characters for Player 1: ";
			numberOfCharactersP1 = m1.getIntInput();
			//ask user for number of characters for player 2
			std::cout << "Please enter the number of characters for Player 2: ";
			numberOfCharactersP2 = m1.getIntInput();



			/************************************************************************
			**Team selection for each player
			************************************************************************/
			std::cout << "\n" << std::endl;
			std::cout << "Team Selection:\n" << std::endl;

			//user enters each character for player1
			for (int i = 0; i < numberOfCharactersP1; i++) {
				std::cout << "Player 1 - Character " << i + 1 << ":\n" << std::endl;
				//character type selection
				m2.printMenu();
				//resets characterMenuSelection
				characterMenuSelection = 0;
				//makes sure the user is entering a number between 1 and 5
				characterMenuSelection = m2.getRangeInput(1, 5);

				//if the user chooses a barbarian
				if (characterMenuSelection == 1) {
					//create the new barbarian
					Barbarian* b = new Barbarian;
					//get the name of the barbarian
					b->setName();
					//add the barbarian to the queue
					q.addBack(b);
				}
				//if the user chooses blue men
				else if (characterMenuSelection == 2) {
					//create the new blue men
					BlueMen* bm = new BlueMen;
					//set the name of the blue men
					bm->setName();
					//add the blue men to the queue
					q.addBack(bm);
				}
				//if the user chooses Harry Potter
				else if (characterMenuSelection == 3) {
					//create the new Harry Potter
					HarryPotter* hp = new HarryPotter;
					//set the name of the Harry Potter character
					hp->setName();
					//add the Harry Potter character to the queue
					q.addBack(hp);
				}
				//if the user chooses Medusa
				else if (characterMenuSelection == 4) {
					//create the new Medusa
					Medusa* m = new Medusa;
					//set the name of the Medusa character
					m->setName();
					//add the Medusa character to the queue
					q.addBack(m);
				}
				//if the user chooses Vampire
				else if (characterMenuSelection == 5) {
					//create the new Vampire character
					Vampire* v = new Vampire;
					//set the name of the Vampire character
					v->setName();
					//add the vampire character to the queue
					q.addBack(v);
				}
			}
			//user enters each character for player2
			for (int i = 0; i < numberOfCharactersP2; i++) {
				std::cout << "Player 2 - Character " << i + 1 << ":\n" << std::endl;
				//character type selection
				m2.printMenu();
				//makes sure the user is entering a number between 1 and 5
				characterMenuSelection = m2.getRangeInput(1, 5);

				//if the user chooses a barbarian
				if (characterMenuSelection == 1) {
					//create the new barbarian character
					Barbarian* b = new Barbarian;
					//set the name of the barbarian character
					b->setName();
					//add the barbarian to the queue
					q2.addBack(b);
				}
				//if the user chooses blue men
				else if (characterMenuSelection == 2) {
					//create the new blue men
					BlueMen* bm = new BlueMen;
					//set teh name of the blue men
					bm->setName();
					//add the blue men character to the queue
					q2.addBack(bm);
				}
				//if the user chooses Harry Potter
				else if (characterMenuSelection == 3) {
					//create the new Harry Potter character
					HarryPotter* hp = new HarryPotter;
					//set thename of the Harry Potter character
					hp->setName();
					//add the Harry Potter character to the queue
					q2.addBack(hp);
				}
				//if the user chooses Medusa
				else if (characterMenuSelection == 4) {
					//create the new Medusa character
					Medusa* m = new Medusa;
					//set the name of the Medusa character
					m->setName();
					//add the Medusa character to the queue
					q2.addBack(m);
				}
				//if the user chooses Vampire
				else if (characterMenuSelection == 5) {
					//create the new Vampire character
					Vampire* v = new Vampire;
					//set teh name of the Vampire character
					v->setName();
					//add the vampire character to the queue
					q2.addBack(v);
				}
			}



			/*********************************************************************************************
			**The two player's teams battle each other
			**********************************************************************************************/

			//while both teams have players to battle
			while (q.getFront()->getStrengthPoints() > 0 && q2.getFront()->getStrengthPoints() > 0) {
				//while neither of the characters that are fighting has died yet
				while (q.getFront()->getStrengthPoints() > 0 && q2.getFront()->getStrengthPoints() > 0) {
					std::cout << "Round " << roundCounter << std::endl << std::endl;
					//player 1 character attacks
					std::cout << q.getFront()->getName() << " attacks.\n" << std::endl;
					q.getFront()->attackSomething();
					std::cout << std::endl;
					//player 2 character attacks
					std::cout << q2.getFront()->getName() << " attacks.\n" << std::endl;
					q2.getFront()->attackSomething();
					std::cout << std::endl;
					//player 1 character defends
					std::cout << q.getFront()->getName() << " defends.\n" << std::endl;
					q.getFront()->defend(q2.getFront()->getAttack());
					std::cout << std::endl;
					//player 2 character defends
					std::cout << q2.getFront()->getName() << " defends.\n" << std::endl;
					q2.getFront()->defend(q.getFront()->getAttack());
					std::cout << std::endl << std::endl;
					//increment round counter
					roundCounter++;
				}
				//reset round counter
				roundCounter = 1;

				//if player 1 character survived and player 2 character died
				if (q.getFront()->getStrengthPoints() > 0 && q2.getFront()->getStrengthPoints() <= 0) {
					//print out the type and name of each character and who won the fight
					std::cout << "In the fight between " << q.getFront()->getType() << " " << q.getFront()->getName() 
						<< " and " << q2.getFront()->getType() << " " << q2.getFront()->getName() << ", "
						<< q.getFront()->getType() << " " << q.getFront()->getName() << " has won the fight.\n\n" << std::endl;
					//add the character that lost to the loser pile
					loserPile.addBack(q2.getFront());
					//increment the number of losers
					numberOfLosers++;
					//move on to the next character for q2
					q2.nextFighter();
					//lets the winner recover some strength points
					q.getFront()->recover();
					//move recovered character to the back of the queue
					q.nextFighter();
					//increment player 1 score
					p1Score++;
				}
				//if player 1 character died and player 2 character survived
				else if (q.getFront()->getStrengthPoints() <= 0 && q2.getFront()->getStrengthPoints() > 0) {
					//print out the type and name of each character and who won the fight
					std::cout << "In the fight between " << q.getFront()->getType() << " " << q.getFront()->getName()
						<< " and " << q2.getFront()->getType() << " " << q2.getFront()->getName() << ", "
						<< q2.getFront()->getType() << " " << q2.getFront()->getName() << " has won the fight.\n\n" << std::endl;
					//add the loser to the loser pile
					loserPile.addBack(q.getFront());
					numberOfLosers++;
					//move to the next character for q
					q.nextFighter();
					//lets the winner recover some strength points
					q2.getFront()->recover();
					//move the recovered character to the back of the queue
					q2.nextFighter();
					//increment player 2 score
					p2Score++;
				}
				//if both characters died at the same time and there was a tie
				else if (q.getFront()->getStrengthPoints() <= 0 && q2.getFront()->getStrengthPoints() <= 0) {
					//print out a message indicating that both characters died
					std::cout << "In the fight between " << q.getFront()->getType() << " " << q.getFront()->getName()
						<< " and " << q2.getFront()->getType() << " " << q2.getFront()->getName() << ", "
						<< "both characters have died, resulting in a tie!\n\n" << std::endl;
					//add the player 1 character to the loser pile
					loserPile.addBack(q.getFront());
					numberOfLosers++;
					//add the player 2 character to the loser pile
					loserPile.addBack(q2.getFront());
					numberOfLosers++;
					//move the player 1 character to the back of the queue
					q.nextFighter();
					//move the player 2 character to the back of the queue
					q2.nextFighter();
				}
			}



			/*********************************************************************
			**Post-Game output and menus
			*********************************************************************/

			//print out the two player scores
			std::cout << "Player 1 Score: " << p1Score << std::endl;
			std::cout << "Player 2 Score: " << p2Score << std::endl;

			//if player 1 wins
			if (p1Score > p2Score) {
				std::cout << "Player 1 wins the game!!!\n\n" << std::endl;
			}
			//if player 2 wins
			else if (p2Score > p1Score) {
				std::cout << "Player 2 wins the game!!!\n\n" << std::endl;
			}
			//if the game ends in a tie
			else if (p1Score == p2Score) {
				std::cout << "The game has ended in a tie!\n\n" << std::endl;
			}

			//asks the user whether they want to print the loser pile or not
			m3.printMenu();
			//verifies the user's input
			loserMenuSelection = m3.getRangeInput(1, 2);

			//if the user chooses to print out the loser pile
			if (loserMenuSelection == 1) {
				//prints out the loser pile
				std::cout << "Loser Pile: ";
				loserPile.printQueue();
				std::cout << std::endl;
			}

			//print out the final menu, verifies input at the top of the loop for initial and final menus
			m4.printMenu();



			/*************************************************************************
			**Memory cleanup at the end of the game loop so that no memory is leaked.
			*************************************************************************/

			//remove the players from the player 1 queue
			for (int i = 0; i < numberOfCharactersP1; i++) {
				q.removeFront();
			}
			//remove the players from the player 2 queue
			for (int i = 0; i < numberOfCharactersP2; i++) {
				q2.removeFront();
			}
			//clean up the loser pile so that there are no memory leaks
			for (int i = 0; i < numberOfLosers; i++) {
				loserPile.cleanUpLoserPile();
			}
		}
	}
	return 0;
}