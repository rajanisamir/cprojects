/* CMSC 16200 - Homework 2
 * File: trending.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "lib/trending.h"
#include "lib/array_util.h"

//returns the number of strings in feed that do not occur in words
//updates frequencies with the number of occurences of each string in words
//  based on their appearances in feed
//considers only the first n elements of words, and the first feedlength
//  words in feed
//uses binary search if fast is true and linear search otherwise
int count_frequencies(const char **words, int *frequencies, int n,
                      const char **feed, int feedlength, bool fast) {
    int notWords = 0;
    int index;
    for (int i = 0; i < feedlength; i++) {
        if (fast == true) index = binary_search(feed[i], words, n);
        else index = linear_search(feed[i], words, n);

        if (index == -1) notWords++;
        else frequencies[index]++;
    }
    return notWords;
}

//takes an array of word frequencies as integers
//updates result with the indices of the three most common words in the subarray of length n
void top_three(int *frequencies, int *result, int n) {
    int first = -1;
    int second = -1;
    int third = -1;
    for (int i = 0; i < n; i++) {
        if (first == -1 || frequencies[i] > frequencies[first]) {
            third = second;
            second = first;
            first = i;
        }
        else if (second == -1 || frequencies[i] > frequencies[second]) {
            third = second;
            second = i;
        }
        else if (third == -1 || frequencies[i] > frequencies[third]) {
            third = i;
        }
    }
    if (first != -1) result[0] = first;
    if (second != -1) result[1] = second;
    if (third != -1) result[2] = third;
    return;
}
