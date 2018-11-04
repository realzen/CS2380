
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 0211 header file
// Author:Eresnto Valdez
// Course: CSCI/CMPE 2380
// Description: player class that works with the main program which lets us play the
// game between the user and computer. 
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>
using namespace std;


#ifndef PLAYER_H
#define PLAYER_H


class player
{
private:
	string Name;
	int Health;
	int Level;
	bool Blocking;
	int DamageDone;
	string Taunt;
public:
	//Constructor sets the name of the player and defaults Health to 100 
	//    and Level to 1
	player(string name);
	//Constructor defaults Health to 100 and Level to 1
	player();
	//Takes an int that specifies the number of sides of the die, rolls and
	//  returns value of roll + the Level 
	//  Every time the player does 10 damage they level up. 
	//  If their Health is less than 10, add 5 to their attack 
	int Attack(int NUM_SIDES);
	//Sets the level to input
	void setHealth(int health);
	//Returns the players health
	int getHealth();
	//Returns the player's Level
	int getLevel();
	//Returns whether the player is alive or not (Health > 0)
	bool isAlive();
	//Subtracts the damage done, but first it rolls a die.  If they roll the max,         
	// die value, then it is a critical hit and does double damage 
	// If blocking, the damage is halved, then blocking is turned off
	void TakeDamage(int damage, int NUM_SIDES);
	//Block only lasts for one hit (TakeDamage) at a time. 
	//  If blocking, the attack die is 4 sided 
	int Block(int NUM_SIDES);
	//Returns their name
	string getName();
	//Returns a string to taunt the other player
	string getTaunt();
	//Sets the string to taunt the other player
	void setTaunt(string);

};


#endif