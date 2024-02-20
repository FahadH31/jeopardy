/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "players.h"

extern void tokenize(char *input, char **tokens);
extern void show_results(player *players, int num_players);
#endif /* JEOPARDY_H_ */
