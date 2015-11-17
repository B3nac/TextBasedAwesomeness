#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "goblin.h"
#include "player.h"
#define SCREEN 25

/*Cross-plat start*/
#ifdef _WIN32
#pragma warning(disable : 4996)*/
#else
#endif
/*------------------------------------------------------------------------------------*/
/*Where people fight.*/

void match()
{

	int damage;
	int enemydamage;
	int exp_gained;
	int bonus = (rand() % 5) + 1; /*Use as exp or crit hit.*/

	damage = goblin.defense - player.attack;
	enemydamage = player.defense - goblin.attack;
	exp_gained = 10;

	std::cout << "You did " << damage << " damage!" << std::endl;
	goblin.health = goblin.health - damage;
	std::cout << "The goblin has " << goblin.health << " health left!" << std::endl;
	std::cout << "The bonus is " << bonus << std::endl;
	std::cout << std::endl;

	/*Add enemy damage here.*/
	    if (enemydamage <= player.defense)
	    {
		    printf("The enemy was not able to do any damage.");
	    }
	    else{

		    player.health = player.health - enemydamage;
		    printf("The goblin did %i damage!\n", enemydamage);
		    printf("The player has %i health left!\n", player.health);
	    }

	    if (player.health <= 0){

		    printf("You did %i damage!\n\n", damage);
		    printf("You win mofackle!\n");
	    }

	    else {

		    printf("Ouch!");
	    }

		if (player.player_exp >= 100){
			printf("The player leveled up!\n");
			player.attack = player.attack + 2;
			player.defense = player.defense +2;
			player.health = player.health + 5;
			player.level = player.level + 1;
		}

		if
			(goblin.health <= 0){
			printf("You killed the goblin!\n");
			printf("The amount of experience gained is %i,", exp_gained);
			player.player_exp = player.player_exp + 10;
			goblin.health += 10;
			player.gobchance = 0;
		}

}
/*------------------------------------------------------------------------------------*/
void clearscreen()
{
	int z;
	for (z = 0; z < SCREEN; z++)
		putchar('\n');
}

/*Areas*/
void temple()
{
	std::cout << "You enter a temple!\n";
	std::cout << "which way would you like to go?\n :";
}

void grasslands()
{
	std::cout << "Trees, lots of trees.";
}

void desert()
{
	std::cout << "Sandy.\n";
	player.gobchance += 1;
	player.moneychance += 1;
	std::cout << "Gobchance number: " << player.gobchance << std::endl;
}

void startarea()
{
	std::cout << "Lots of luscious grass, looks like somewhere new players would start.";
	std::cout << "************************\n*****^^^^^^^^^^"
		         "trees^^^^^^RRARARERARR\n***************HE"
		         "HEHHEE\nEEEEEEEEEEEEEEEEEEE\n\n";

}
/*------------------------------------------------------------------------------------*/
void error_check(FILE *in)
{
	int ch;
	clearerr(in);
	do
	ch = getc(in);
	while (ch != '\n' && ch != EOF);
	clearerr(in);
}

void move()
{
	static int y;
	char choice;

	if (player.gobchance == 5){
		printf("You find a goblin! Do you want to attack the goblin?!\n 1 = yes 2 = no: ");
	}

	if (player.moneychance == 8){
		std::cout << "You found some money! Do you want to pick it up?\n y or n: ";
		std::cin >> choice;
		if (choice == 'y'){
			player.money += 5;
			player.moneychance = 0;
			std::cout << "Current amount of money: " << player.money;
		}
	}

	if (player.gobchance < 5){
		printf("\n What area would you like to explore? Desert = 3, Grasslands = 4, Temple = 5: ");
	
    }
	std::cin >> y;
    
	error_check(stdin);
	printf("Invalid integer. Please try again: ");

	clearscreen();

	switch (y)
	{
	case 1:
		match();
		break;
	case 2:
		std::cout << "You chose to run!\n";
		std::cout << "Exiting.\n";
		break;
	case 3:
		desert();
		break;
	case 4:
		grasslands();
		break;
	case 5:
		temple();
	}

}

void player_name()
{
	    std::cout << "Enter your player name: ";
	    std::cin >> player.name;
	    std::cout << "Player name is: " << player.name << "\n";
}
/*------------------------------------------------------------------------------------*/
void engineLoop()
{
	while (player.health >= 1)
	    move();
	    match();

}

int main()
{

	player_name();
    startarea();
	engineLoop();

	getchar();
	return 0;

}
