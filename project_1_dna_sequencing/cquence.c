/* CMSC 16200 - Homework 1
 * File: cquence.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "dna.h"
#include "cquence.h"

//takes two strands S1 and S2
//creates and returns a new strand of S1 and S2 combined back to back
//if both strands are NULL or malloc fails, returns NULL
strand *join(strand *S1, strand *S2) {
    if (S1 == NULL && S2 == NULL) return NULL;

    strand* S = empty_strand();
    if (S == NULL) return NULL;

    if (S1 != NULL) {
        S -> length += S1 -> length;
    }
    if (S2 != NULL) {
        S -> length += S2 -> length;
    }

    seq* newHead = malloc(sizeof(seq));
    if (newHead == NULL) {
        printf("Error: Malloc failed!");
        return NULL;
    }

    seq* templateNode;
    seq* curNode = NULL;

    if (S1 != NULL && S1 -> head != NULL) {
        newHead -> data = S1 -> head -> data;
        S -> head = newHead;
        templateNode = S1 -> head -> next;
        curNode = newHead;
        while (templateNode != NULL) {
            seq* newNode = malloc(sizeof(seq));
            if (newNode == NULL) {
                printf("Error: Malloc failed!");
                return NULL;
            }
            newNode -> data = templateNode -> data;
            curNode -> next = newNode;
            curNode = curNode -> next;
            templateNode = templateNode -> next;
        }
    }

    if (S2 != NULL && S2 -> head != NULL) {
        if (S -> head == NULL) {
            newHead -> data = S2 -> head -> data;
            S -> head = newHead;
            curNode = newHead;
            templateNode = S2 -> head -> next;
        }
        else {
            templateNode = S2 -> head;
        }
        while (templateNode != NULL) {
            seq* newNode = malloc(sizeof(seq));
            if (newNode == NULL) {
                printf("Error: Malloc failed!");
                return NULL;
            }
            newNode -> data = templateNode -> data;
            curNode -> next = newNode;
            curNode = curNode -> next;
            templateNode = templateNode -> next;
        }
    }

    if (curNode != NULL) {
        curNode -> next = NULL;
    }
    return S;
}

//helper function for interleave
//takes data from n1 and from n2 before recursing on the nodes they point to
strand *interleaveRecurse(seq *n1, seq *n2) {
    if (n1 == NULL && n2 == NULL) return empty_strand();

    if (n1 == NULL) {
        strand* node = empty_strand();
        if (node == NULL) return NULL;
        cons_strand(n2 -> data, node);
        strand* rest = interleaveRecurse(NULL, n2 -> next);
        strand* combine = join(node, rest);
        free(node);
        free(rest);
        return combine;
    }

    if (n2 == NULL) {
        strand* node = empty_strand();
        if (node == NULL) return NULL;
        cons_strand(n1 -> data, node);
        strand* rest = interleaveRecurse(n1 -> next, NULL);
        strand* combine = join(node, rest);
        free(node);
        free(rest);
        return combine;
    }

    strand* next = empty_strand();
    if (next == NULL) return NULL;
    cons_strand(n2 -> data, next);
    cons_strand(n1 -> data, next);
    strand* rest = interleaveRecurse(n1 -> next, n2 -> next);
    strand* combine = join(next, rest);
    free(next);
    free(rest);
    return combine;
}

//takes two strands S1 and S2
//returns a new strand that intersperses the data of S2 in that of S1
//if both strands are NULL, returns NULL
strand *interleave(strand *S1, strand *S2) {
    if (S1 == NULL && S2 == NULL) return NULL;
    if (S1 == NULL) return interleaveRecurse(NULL, S2 -> head);
    if (S2 == NULL) return interleaveRecurse(S1 -> head, NULL);
    return interleaveRecurse(S1 -> head, S2 -> head);
}

//takes two strands S and Sub, and a position pos
//injects Sub into S at position pos, returning 0 to indicate success
//if the position is invalid or S is NULL, returns 1 to indicate failure
int inject(strand *S, strand *Sub, int pos) {
    if (S == NULL) return 1;
    if ((pos < 0) || (pos > S -> length)) return 1;
    if ((Sub == NULL) || (Sub -> length == 0)) return 0;

    seq* curNode = NULL;
    if (pos > 0) {
        curNode = S -> head;
    }
    for(int i = 1; i < pos; i++) {
        curNode = curNode -> next;
    }
    seq* templateNode = Sub -> head;
    seq* firstCopy = malloc(sizeof(seq));
    if (firstCopy == NULL) {
        printf("Error: Malloc failed!");
        return 1;
    }
    (S -> length)++;
    firstCopy -> data = templateNode -> data;
    templateNode = templateNode -> next;
    seq* secondHalf = NULL;
    if (curNode == NULL) {
        if (S -> length > 0) {
            secondHalf = S -> head;
        }
        curNode = firstCopy;
        S -> head = curNode;
    }
    else {
        secondHalf = curNode -> next;
        curNode -> next = firstCopy;
        curNode = curNode -> next;
    }
    while (templateNode != NULL) {
        seq* copyNode = malloc(sizeof(seq));
        if (copyNode == NULL) {
            printf("Error: Malloc failed!");
            return 1;
        }
        (S -> length)++;
        copyNode -> data = templateNode -> data;
        curNode -> next = copyNode;
        curNode = copyNode;
        templateNode = templateNode -> next;
    }
    if (secondHalf != NULL) {
        curNode -> next = secondHalf;
    }
    else {
        curNode -> next = NULL;
    }
    return 0;
}

//takes two strands S and Sub
//returns true if the data in Sub is identical to that at the start of S
//returns false if either strand is NULL or if Sub is longer than S
bool isPrefix(strand *S, strand *Sub) {
    if ((S == NULL) || (Sub == NULL)) return false;

    int m = S -> length;
    int n = Sub -> length;

    if (m < n) return false;

    seq* sNode = S -> head;
    seq* subNode = Sub -> head;

    int i = 0;
    while ((i < n) && (sNode -> data == subNode -> data)) {
        sNode = sNode -> next;
        subNode = subNode -> next;
        i++;
    }
    if (i == n) {
        return true;
    }
    return false;
}

//takes two strands S and Sub
//returns the position of the first instance of Sub in S
//if either strand is NULL or the element is not found, returns -1
int find(strand *S, strand *Sub) {
    if ((S == NULL) || (Sub == NULL)) return -1;

    int m = S -> length;
    int n = Sub -> length;

    seq* initialNode = S -> head;
    seq* templateNode = Sub -> head;
    seq* checkingNode = NULL;

    for (int i = 0; i < m - n + 1; i++) {
        checkingNode = initialNode;
        templateNode = Sub -> head;
        int j = 0;
        while ((j < n) && (checkingNode -> data == templateNode -> data)) {
            checkingNode = checkingNode -> next;
            templateNode = templateNode -> next;
            j++;
        }
        if (j == n) {
            return i;
        }
        initialNode = initialNode -> next;
    }
    return -1;
}

//takes two strands S and Sub
//removes the first instance of Sub in S and returns 0 to indicate success
//returns 1 if Sub is not contained within S or if malloc fails
int snip(strand *S, strand *Sub) {
    int pos = find(S, Sub);
    if (pos < 0) return 1;
    if (Sub -> head == NULL) return 0;

    seq* frag1 = NULL;
    if (pos != 0) {
        frag1 = S -> head;
        for (int i = 0; i < pos - 1; i++) {
            frag1 = frag1 -> next;
        }
    }

    strand* toClip = malloc(sizeof(strand));
    if (toClip == NULL) {
        printf("Error: Malloc failed!");
        return 1;
    }
    if (frag1 != NULL) toClip -> head = frag1 -> next;
    else toClip -> head = S -> head;

    toClip -> length = Sub -> length;

    seq* clip = toClip -> head;
    for (int j = 0; j < (Sub -> length) - 1; j++) {
        clip = clip -> next;
    }
    if (frag1 != NULL) frag1 -> next = clip -> next;
    else S -> head = clip -> next;

    clip -> next = NULL;
    free_strand(toClip);

    S -> length -= Sub -> length;

    return 0;
}
