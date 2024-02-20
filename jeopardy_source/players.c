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
#include "players.h"


bool player_exists(player *players, int num_players, char *name) {
    for (int i = 0; i < num_players; ++i) {
        if (strcmp(players[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

void update_score(player *players, int num_players, char *name, int score) {
    for (int i = 0; i < num_players; ++i) {
        if (strcmp(players[i].name, name) == 0) {
            players[i].score += score;
            break;
        }
    }
}

// Display the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    printf("Game Results:\n");
    // Sort players by score (I'll leave the sorting algorithm implementation to you)
    for (int i = 0; i < num_players; ++i) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}
