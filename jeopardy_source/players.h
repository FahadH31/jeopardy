/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef PLAYERS_H_
#define PLAYERS_H_

#include <stdbool.h>

#define MAX_LEN 256

typedef struct {
    char name[MAX_LEN];
    int score;
} player;

extern bool player_exists(player *players, int num_players, char *name);
extern void update_score(player *players, int num_players, char *name, int score);

#endif /* PLAYERS_H_ */
