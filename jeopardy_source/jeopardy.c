/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
// jeopardy.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

void tokenize(char *input, char **tokens);
void show_results(player *players, int num_players);

int main(int argc, char *argv[]) {
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN] = { 0 };

    initialize_game();

    printf("Enter the names of the four players:\n");
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        printf("Player %d: ", i + 1);
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
        strcpy(players[i].name, buffer);
        players[i].score = 0;
    }

    while (1) {
        display_categories();
        int remaining_questions = NUM_QUESTIONS;
        while (remaining_questions > 0) {
            char player_name[BUFFER_LEN];
            printf("Enter the name of the player to select a question: ");
            fgets(buffer, BUFFER_LEN, stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
            strcpy(player_name, buffer);

            if (!player_exists(players, NUM_PLAYERS, player_name)) {
                printf("Invalid player name. Please try again.\n");
                continue;
            }

            char category[MAX_LEN];
            int value;
            printf("Enter the category and dollar amount of the question (e.g., programming 100): ");
            fgets(buffer, BUFFER_LEN, stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character
            sscanf(buffer, "%s %d", category, &value);

            if (already_answered(category, value)) {
                printf("Question already answered. Please select another.\n\n");
                continue;
            }

            display_question(category, value);

            printf("Enter your answer (start with 'What is', followed by your answer in lowercase): ");
            fgets(buffer, BUFFER_LEN, stdin);
            buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character

            if (valid_answer(category, value, buffer)) {
                printf("Correct answer!\n\n");
                update_score(players, NUM_PLAYERS, player_name, value);
            } else {
                printf("Incorrect answer! The correct answer is: %s\n", questions[value - 100].answer);
            }
            remaining_questions--;
        }

        show_results(players, NUM_PLAYERS);
        break; // exit the loop after one round for simplicity
    }

    return EXIT_SUCCESS;
}
