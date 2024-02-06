/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();
	int count = 0;
    // Prompt for players names
	while (count != NUM_PLAYERS) {
		if (count == 0 ) {
			char str[];
		printf("What is the current player name: %d", i);
		scanf ("%16s", str);
		strcpy(players[i], str);
		}
		else if (count == 1) {
			char str2[];
			printf("What is the current player name: %d", i);
			scanf (players[i], str2);
		}
		else if (count == 2){
			char str3[];
			printf("What is the current player name: %d", i);
			scanf(players[i], str3);
		}
		else if (count == 3){
			char str4[];
			printf("What is the current player name: %d", i);
			scanf(players[i], str4);
		}
		else{
		}

		count++;
	}	
    // initialize each of the players in the array

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL) {
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
