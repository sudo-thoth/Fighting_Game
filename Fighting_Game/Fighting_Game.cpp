// Fighting_Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>
using namespace std;


void playerSetup(string &pName, int &pAttack, int &pDefense, int &pMagic) {
	cout << "What is your name?" << endl;
	cin >> pName;
	int pointAlloc = 30;
	cout << pName << " you have 30 points to use. You can distribute them as you wish into your Attack, Defense, and Magic abilities. " << endl;
	
	
	bool pointsUsed = false;
	while (pointsUsed == false) {
		cout << "How many points do you want to add to Attack?" << endl;
		cin >> pAttack;
		pointAlloc -= pAttack;
		cout << "How many points do you want to add to Defense?" << endl;
		cin >> pDefense;
		pointAlloc -= pDefense;
		cout << "How many points do you want to add to Magic?" << endl;
		cin >> pMagic;
		pointAlloc -= pMagic;
		cout << endl;

		if (pointAlloc < 0) {
			cout << "You used " << pointAlloc << " more points than allowed, please redistribute your points" << endl;
		
		}
		else if (pointAlloc > 0) {
			cout << "You still have " << pointAlloc << " points leftover! Start over and make sure to use all 30 points!!!" << endl;
		}
		else {
			cout << "You're all set-up!!" << endl;
			pointsUsed = true;
			cout << "You have " << pAttack << " points for your Attack ability." << endl;
			cout << "You have " << pDefense << " points for your Defense ability." << endl;
			cout << "You have " << pMagic << " points for your Magic ability." << endl;
		}


	}

}

void player1ability(int &ability, string p1name) {
	cout << p1name << " choose your ability!" << endl;
	cout << "Press the corresponding number" << endl;
	cout << " 1 for Attack" << endl;
	cout << " 2 for Defense" << endl;
	cout << " 3 for Magic" << endl;
	cin >> ability;
	if (ability == 1) {
		cout << "ATTACK" << endl;
	}
	else if (ability == 2)
	{
		cout << "DEFENSE" << endl;
	}
	else if (ability == 3)
	{
		cout << "MAGIC" << endl;
	}
	else if (ability > 3) {
		cout << "Invalid Ability, try again" << endl;
	}
	else if (ability < 1) {
		cout << "Invalid Ability, try again" << endl;
	}
}



void player2ability(int &ability, string p2name) {
	cout << p2name << " choose your ability!" << endl;
	cout << "Press the corresponding number" << endl;
	cout << " 1 for Attack" << endl;
	cout << " 2 for Defense" << endl;
	cout << " 3 for Magic" << endl;
	cin >> ability;
	if (ability == 1) {
		cout << "ATTACK" << endl;
	}
	else if (ability == 2)
	{
		cout << "DEFENSE" << endl;
	}
	else if (ability == 3)
	{
		cout << "MAGIC" << endl;
	}
	else if (ability > 3) {
		cout << "Invalid Ability, try again" << endl;
	}
	else if (ability < 1) {
		cout << "Invalid Ability, try again" << endl;
	}

}


int main()
{
	int p1health = 100;
	int p2health = 100;


	//p1health
	if (p1health > 100) {
		p1health = 100;
	}
	else if (p1health < 100) {
		p1health = 100;
	}

	//p2health
	if (p1health > 100) {
		p1health = 100;
	}
	else if (p1health < 100) {
		p1health = 100;
	}

	string p1name;
	int p1Att;
	int p1Def;
	int p1Mag;

	string p2name;
	int p2Att;
	int p2Def;
	int p2Mag;


	int dmg = 0;
	int heal = 0;


	//Player 1 moves
	int ability1;

	//Player 2 moves
	int ability2;

	//ability distribution
	random_device rd;
	uniform_int_distribution<int> abilitydis(0, 13);



	cout << "Player1, set up your character!" << endl;

	playerSetup(p1name, p1Att, p1Def, p1Mag);

	cout << "Player2, set up your character!" << endl;

	playerSetup(p2name, p2Att, p2Def, p2Mag);

	cout << "You are now ready to start your battle" << endl;

	while (p1health > 0 && p2health > 0) {
	//Display Health
		cout << p1name << ":" << p1health << " HP" << endl;
		cout << p2name << ":" << p2health << " HP" << endl;

	//Player 1 moves
		player1ability(ability1, p1name);

		


		if (ability1 == 1){
			dmg = p1Att + abilitydis (rd);
			p2health -= dmg;
	}
		else if (ability1 == 2) {
			heal = p1Def + abilitydis(rd);
			p1health += heal;
		}
		else if (ability1 == 3) {
			dmg = p1Mag + abilitydis(rd);
			p2health -= dmg;
		}
	//Player 2 moves
		player1ability(ability2, p2name);

			

			if (ability1 == 1) {
				dmg = p1Att + abilitydis(rd);
				p1health -= dmg;
			}
			else if (ability1 == 2) {
				heal = p1Def + abilitydis(rd);
				p2health += heal;
			}
			else if (ability1 == 3) {
				dmg = p1Mag + abilitydis(rd);
				p1health -= dmg;
			}



			//p1health
			if (p1health > 100) {
				p1health = 100;
			}
			else if (p1health < 0) {
				p1health = 0;
			}


			//p2health
			if (p2health > 100) {
				p2health = 100;
			}
			else if (p2health < 0) {
				p2health = 0;
			}



			if (p1health <=0 && p2health <=0) {
				cout << p1name << ":" << p1health << " HP" << endl;
				cout << p2name << ":" << p2health << " HP" << endl;
				cout << "You have tied eachother!! Startover and battle again!!" << endl;
				break;
			}
			if (p1health <= 0) {
				cout << p1name << ":" << p1health << " HP" << endl;
				cout << p2name << ":" << p2health << " HP" << endl;
				cout << "Congrats " << p2name << "!! You have won the battle!" << endl;
			}

			if (p2health <= 0) {
				cout << p1name << ":" << p1health << " HP" << endl;
				cout << p2name << ":" << p2health << " HP" << endl;
				cout << "Congrats " << p1name << "!! You have won the battle!" << endl;
			}
	}




    return 0;
}

