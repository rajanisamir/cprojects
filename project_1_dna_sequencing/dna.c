/* CMSC 16200 - Homework 1
 * File: dna.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdio.h>
#include <stdlib.h>
#include "dna.h"

//Formats and prints an input strand to the console
void print_seq(strand *L) {
    if (L == NULL) return;
    if (L->head == NULL || L->length == 0) {
        printf("DNA seq empty.\n");
        return;
    }
    seq *iterator = NULL;
    printf("DNA seq (len = %d): < ", L->length);
    for (iterator = L->head; iterator != NULL; iterator = iterator->next) {
        printf("%c ", iterator->data);
    }
    printf(">\n");
}

//Creates and returns a strand with length = 0 and head = NULL.
//Returns NULL if malloc fails.
strand *empty_strand() {
    strand* s = (strand*) malloc(sizeof(strand));
    if (s == NULL) return NULL;
    s -> head = NULL;
    s -> length = 0;
    return s;
}

//Takes a character data and a strand S, and prepends a node of value data to S.
void cons_strand(char data, strand *S) {
    if (S == NULL) return;
    seq* newHead = malloc(sizeof(seq));
    newHead -> data = data;
    newHead -> next = S -> head;
    S -> head = newHead;
    (S -> length)++;
    return;
}

//Takes a string and returns its length.
//Returns 0 if passed a null pointer.
int stringLength(char *s) {
    if (s == NULL) return 0;
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

//Takes a string and creates and returns a corresponding strand.
//Returns an empty strand if passed a null pointer.
strand *string2strand(char *s) {
    if (s == NULL) return empty_strand();
    strand* newStrand = empty_strand();
    for (int i = stringLength(s) - 1; i >= 0; i--) {
        cons_strand(s[i], newStrand);
    }
    return newStrand;
}

//Frees a strand, along with its associated nodes, from memory.
void free_strand(strand *S) {
    if (S == NULL) return;
    seq* curNode = S -> head;
    seq* nextNode = curNode -> next;
    while (curNode != NULL) {
        nextNode = curNode -> next;
        free(curNode);
        curNode = nextNode;
    }
    free(S);
    return;
}
