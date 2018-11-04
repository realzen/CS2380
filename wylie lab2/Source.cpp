//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 0211
// Author: Eresnto Valdez
// Course: CSCI/CMPE 2380
// Description: This program will play a game between the user and the computer
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 


#include "player.h"



//what sided die to use to attack
const int ATTACK_DIE = 12;
//the defense also gets a die
const int DEFENSE_DIE = 6;
//what sided die to use to attack
const int BLOCKING_DIE = 4;


int main()
{

	player p1("AI"); //the computer
	player p2; //the user of the program (default name is "Player")
	bool p2_turn = true; //is it the user's turn?
	int p2_choice = 0;  //the menu choice


	cout << "Let's fight!" << endl;

	while (p1.isAlive() && p2.isAlive()) //returns true if the player is alive (health > 0)
	{
		if (p2_turn)
		{
			cout << "Your health: " << p2.getHealth() << ", level:" << p2.getLevel() << endl; //returns health
			cout << "Computer's health: " << p1.getHealth() << ", level:" << p1.getLevel() << endl; //returns health
			cout << "Do you (1)Attack, (2)Taunt, or (3)Block? ";
			cin >> p2_choice;  //get the user's move

			while (!cin)
			{
				cin.clear();
				cin.ignore(2000, '\n');
				cout << "Not a legal integer" << endl;
				cout << "#: ";

				cin >> p2_choice;
			}

			//THE USER
			switch (p2_choice)
			{
			case 1:
				//TakeDamage takes an integer that removes that value from health
				//  Attack returns a random integer less than the value it's passed (ATTACK_DIE) + the level
				//  attack = rand()%ATTACK_DIE + Level
				//  the defense die subtracts its roll from the attack
				//  if the attack rolls its max value than it's a critical hit worth twice the value (24)
				p1.TakeDamage(p2.Attack(ATTACK_DIE), DEFENSE_DIE);
				break;
			case 2:
				//should return a string taunting the opponent
				cout << "You say: " << p2.getTaunt() << endl;
				//the taunt does 4 damage by default because it hurts the computer's feelings
				p1.TakeDamage(4, DEFENSE_DIE);
				break;
			case 3:
				//blocking halves the hit points from an attack, but only lasts for 
				//one turn of your opponent 
				//also, if the player is blocking, then they can only roll with
				//an attack die of 4.
				p1.TakeDamage(p2.Block(BLOCKING_DIE), DEFENSE_DIE);
				break;
			default:
				cout << "Please don't hurt me!" << endl;
				//he loses 1 damage due to your pleas hurting his ears
				p1.TakeDamage(1, DEFENSE_DIE);
				break;
			}
			p2_turn = false;
		}
		else
		{
			//THE COMPUTER AI
			//if the opponent has twice your life he taunts
			if (p1.getHealth() > 2 * p2.getHealth())
			{
				cout << "The computer says: " << p1.getTaunt() << endl;
				p2.TakeDamage(4, DEFENSE_DIE);
			}
			//the computer only blocks when his health is low and his opponent's isn't.
			else if (p1.getHealth()<2 * ATTACK_DIE && p2.getHealth()>2 * ATTACK_DIE)
			{
				cout << "The computer blocks" << endl;
				p2.TakeDamage(p1.Block(BLOCKING_DIE), DEFENSE_DIE);
			}
			else
			{
				cout << "The computer attacks" << endl;
				p2.TakeDamage(p1.Attack(ATTACK_DIE), DEFENSE_DIE);  //the user takes damage from the computer's attack
			}

			p2_turn = true;
		}
	}

	if (p1.isAlive())
		cout << p1.getName() << " wins!" << endl;
	else
		cout << p2.getName() << " wins!" << endl;

	return 0;
}