/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

void initialize_game(void) {
    // Programming category
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "This programming language, created by Guido van Rossum, is known for its readability and simplicity.");
    strcpy(questions[0].answer, "What is python");
    questions[0].value = 100;
    questions[0].answered = false;
    
    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "This software development practice involves writing tests for code before implementing the code itself.");
    strcpy(questions[1].answer, "What is tdd");
    questions[1].value = 200;
    questions[1].answered = false;
    
    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "What does the ++ operator do in Java?");
    strcpy(questions[2].answer, "What is increment");
    questions[2].value = 300;
    questions[2].answered = false;
    
    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "This integrated development environment (IDE) is widely used for Java development.");
    strcpy(questions[3].answer, "What is intellij");
    questions[3].value = 400;
    questions[3].answered = false;

 
    // Databases category
    strcpy(questions[4].category, "databases");
    strcpy(questions[4].question, "This SQL keyword is used to retrieve data from a database table.");
    strcpy(questions[4].answer, "What is select");
    questions[4].value = 100;
    questions[4].answered = false;
    
    strcpy(questions[5].category, "databases");
    strcpy(questions[5].question, "This type of database model organizes data into tables with rows and columns.");
    strcpy(questions[5].answer, "What is relational");
    questions[5].value = 200;
    questions[5].answered = false;
    
    strcpy(questions[6].category, "databases");
    strcpy(questions[6].question, "This popular NoSQL database is known for its flexibility and scalability, often used in big 		data applications.");
    strcpy(questions[6].answer, "What is mongodb");
    questions[6].value = 300;
    questions[6].answered = false;
    
    strcpy(questions[7].category, "databases");
    strcpy(questions[7].question, "This type of join returns only the rows that have matching values in both tables.");
    strcpy(questions[7].answer, "What is inner");
    questions[7].value = 400;
    questions[7].answered = false;
    
    //Algorithms Category
    strcpy(questions[8].category, "algorithms");
    strcpy(questions[8].question, "This sorting algorithm has a worst-case time complexity of O(n log n).");
    strcpy(questions[8].answer, "What is merge");
    questions[8].value = 100;
    questions[8].answered = false;
    
    strcpy(questions[9].category, "algorithms");
    strcpy(questions[9].question, "Named after its founder, this greedy algorithm finds the shortest path in a weighted graph.");
    strcpy(questions[9].answer, "What is dijkstra");
    questions[9].value = 200;
    questions[9].answered = false;
    
    strcpy(questions[10].category, "algorithms");
    strcpy(questions[10].question, "This algorithm is used to find the maximum or minimum value in a list of elements.");
    strcpy(questions[10].answer, "What is extremum");
    questions[10].value = 300;
    questions[10].answered = false;
    
    strcpy(questions[11].category, "algorithms");
    strcpy(questions[11].question, "This search algorithm finds the position of a target value within a sorted array.");
    strcpy(questions[11].answer, "What is binary");
    questions[11].value = 400;
    questions[11].answered = false;
}


void display_categories(void) {
    printf("\n");
    printf("Categories:\n");
    for (int i = 0; i < NUM_CATEGORIES; ++i) {
        printf("%s\n", categories[i]);
    }
    printf("\n");
}

void display_question(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Category: %s\n", questions[i].category);
            printf("Question for $%d: %s\n", questions[i].value, questions[i].question);
            return;
        }
    }
}

bool valid_answer(char *category, int value, char *answer) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            questions[i].answered = true;
            return strcmp(questions[i].answer, answer) == 0;
        }
    }
    return false; // Question not found
}

bool already_answered(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; ++i) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return true; // Question not found
}

