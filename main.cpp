#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SCREEN 25
#pragma warning(disable : 4996)

/*enemies*/

class goblin
{

public:
    int health = 10;
	static const int attack = 2;
	static const int defense = 2;

} goblin;

/*player*/


class player
{

public:
	char name[20];
	int level = 1;
	int health = 10;
	int player_exp = 0;
    int attack = 1;
    int defense = 5;
	int gobchance = 0;

} player;
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

	printf("You did %i damage!\n", damage);
	goblin.health = goblin.health - damage;
	printf("The goblin has %i health left!\n", goblin.health);
	printf("The bonus is %i!", bonus);

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
			player.player_exp + 10;
			goblin.health += 10;
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
	printf("You enter a temple!\n"
		   "which way would you like to go?\n");
}
void grasslands()
{
	printf("Trees, lots of trees.");
}
void desert()
{
	printf("Sandy.");
	player.gobchance += 1;
	printf("Gobchance number: ", player.gobchance);
}
void startarea()
{
	printf("Lots of luscious grass, looks like somewhere new players would start.");
	printf("************************\n*****^^^^^^^^^^"
		   "trees^^^^^^RRARARERARR\n***************HE"
		   "HEHHEE\nEEEEEEEEEEEEEEEEEEE\n\n");

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

	if (player.gobchance == 5){
		printf("You find a goblin! Do you want to attack the goblin?!\n 1 = yes 2 = no: ");
		player.gobchance = 0;
	}

	if (player.gobchance < 5){
		printf("What area would you like to explore? Desert = 3, Grasslands = 4, Temple = 5");
	}

	scanf_s("%d", &y);
	error_check(stdin);
	printf("Invalid integer. Please try again: ");

	clearscreen();

	switch (y)
	{
	case 1:
		match();
		break;
	case 2:
		printf("You chose to run!");
		printf("Exiting.\n");
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
	player.name[20];

	    printf("Enter your player name : ");
	    gets(player.name);
	    printf("Player name is : %s !", player.name);
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

    /* blew my mind right here. Heh yeah. */

	getchar();
	return 0;

}