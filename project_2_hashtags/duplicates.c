/* CMSC 16200 - Homework 2
 * File: duplicates.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/duplicates.h"

//counts the number of distinct strings among the first n elements of words
//words must be sorted
int number_distinct(const char **words, int n) {
    int distinctWords = 0;
    if (n > 0) distinctWords++;
    for (int i = 1; i < n; i++) {
        if (strcmp(words[i], words[i-1]) != 0) {
            distinctWords++;
        }
    }
    return distinctWords;
}

//stores in result the index of the first occurence of each distinct word in words
//considers only the first n elements of words
//the empty string is considered a distinct word
void indices_distinct(const char **words, int *result, int n) {
    if (n > 0) result[0] = 0;
    int i = 1;
    for (int j = 1; j < n; j++) {
        if (strcmp(words[j], words[j-1]) != 0) {
            result[i] = j;
            i++;
        }
    }
    return;
}

//allocates and returns a sorted array with all the duplicates in words removed
//considers only the first n elements of words
char **remove_duplicates(const char **words, int n) {
    int numberDistinct = number_distinct(words, n);
    int indicesDistinct[numberDistinct];
    indices_distinct(words, indicesDistinct, n);
    char **result = (char**) malloc(numberDistinct * sizeof(char*));
    for (int i = 0; i < numberDistinct; i++) {
        result[i] = (char*) malloc(strlen(words[indicesDistinct[i]]));
        strcpy(result[i], words[indicesDistinct[i]]);
    }
    return result;
}
