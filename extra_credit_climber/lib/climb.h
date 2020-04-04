#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "hashtable.h"

#ifndef _CLIMB_H_
#define _CLIMB_H_

struct move {
    int limb;
    int x;
    int y;
    struct move* next;
    struct move* prev;
};
typedef struct move move;

int compare_holds(const void* hold1, const void* hold2);

move* add_move(move* moves, int limb, int x, int y);

move* pop_move(move* moves);

void free_moves(move* moves);

void print_moves(move* moves, int start_x, int start_y);

void poptoBack(int* arr, int n);

int make_move(int A, int T, int L, move** head, move* moves, int* coords, int* limb_queue, int** holds, int n, hashtable* visited);

#endif
