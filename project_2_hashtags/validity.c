/* CMSC 16200 - Homework 2
 * File: validity.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/validity.h"
#include "lib/string_util.h"

//takes a string, removes all non-letter characters, and turns all letters to lowercase
void sentence2hashtag(char *sentence) {
    int i = 0;
    while (sentence[i] != '\0') {
        //character is a capital letter, so convert it to lowercase
        if (((int) sentence[i]) >= 65 && ((int) sentence[i]) <= 90) {
            sentence[i] += 32;
        }
        //character is not a letter, so shift everything back
        else if (((int) sentence[i]) > 122 || ((int) sentence[i]) < 97) {
            int j = i;
            while (sentence[j] != '\0') {
                sentence[j] = sentence[j+1];
                j++;
            }
            i--;
        }
        i++;
    }
    return;
}

//returns true if the input string consists only of dictionary words without
//  spaces or uppercase letters; return false otherwise
bool is_valid_hashtag(char *hashtag) {
    if (strlen(hashtag) == 0) return true;
    for (int i = 1; i <= (int) strlen(hashtag); i++) {
        char *maybeWord = malloc(i + 1);
        if(is_word(substring(maybeWord, hashtag, 0, i))) {
            char* rest = malloc(strlen(hashtag)-i+1);
            if(is_valid_hashtag(substring(rest, hashtag, i, strlen(hashtag)-i))) {
                return true;
            }
        }
    }
    return false;
}
