/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
// questions.h
#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

static char categories[NUM_CATEGORIES][MAX_LEN] = {
    "programming",
    "algorithms",
    "databases"
};

typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

static question questions[NUM_QUESTIONS];

extern void initialize_game(void);
extern void display_categories(void);
extern void display_question(char *category, int value);
extern bool valid_answer(char *category, int value, char *answer);
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */
