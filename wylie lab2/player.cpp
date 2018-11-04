//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 0211 header file
// Author: Ernesto Valdez
// Course: CSCI/CMPE 2380
// Description: methods that work with the main cpp and which were declared in the
// header file.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include<iostream>
#include<string>

#include"player.h"



// parameterized constructuor which takes a string
player::player(string name)
{
	Name = name;
	Health = 100;
	Level = 1;


}
// default constructor 
player::player()
{
	Health = 100;
	Level = 1;

}
// lets the player attack and levels up the player and increases 
// their attack accoridingly
int player::Attack(int NUM_SIDES)
{

	srand(time(NULL));
	int att= rand() % NUM_SIDES + 1+Level;
	if (att == NUM_SIDES)
	{
		att = 2 * att;
	}
	if (Health < 10)
	{
		att += 5;
	}
	if (att >= 10)
	{
		Level++;
	}
	return att;
}
// sets the players health
void player::setHealth(int health)
{
	Health = health;
}
// gets the health the player has
int player::getHealth()
{
	return Health;
}
// gets the player's level
int player::getLevel()
{
	return Level;
}
// checks weather the player is still alive 
// by returning true or false
bool player::isAlive()
{
	if (Health > 0)
		return true;
	else
		return false;
}
// determined the amount of damage the player receives
// and if the player is blocking it account for that as well
void player::TakeDamage(int damage, int NUM_SIDES)
{
	srand(time(NULL));
	int roll = rand() % NUM_SIDES + 1 ;
	
	if (Blocking)
	{
		damage = damage / 2;
		Blocking = false;
	}
	damage = damage - roll;
	if (damage > 0)
		Health = Health - damage;
}
//methods that lets the player block 
int player::Block(int NUM_SIDES)
{
	srand(time(NULL));
	int roll = rand() % NUM_SIDES + 1;
	return roll;


}
// gets the players name
string player::getName()
{

	return Name;

}
// returns a taunt
string player::getTaunt()
{
	return Taunt;

}
// sets a taunted if one wanted
void player::setTaunt(string t)
{
	Taunt = t;

}
