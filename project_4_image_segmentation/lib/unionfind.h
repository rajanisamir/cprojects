/* CMSC 16200 - Homework 4
 * File: unionfind.h
 * The Union Find implementation and its interface.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "graph.h"

#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_


/* Find and return the index of the root of the pixel with pixelID idx. */
pixelID up_trees_find(pixelID parentID[ROWS][COLS], unsigned int w, pixelID idx);

/* Merge the two groups which pixel p1 and pixel p2 belong. */
void up_trees_union(pixelID parentID[ROWS][COLS], unsigned int w, pixelID p1, pixelID p2);

/* Store forest of up-trees in the array parentID, given the graph G. */
void up_trees_new(graph G, pixelID parentID[ROWS][COLS]);

/*
 * Run UNION-FIND, and store the final forest of up-trees in array parentID,
 * where count is a boolean flag indicating whether to print out the count.
 */
void run_union_find(graph G, pixelID parentID[ROWS][COLS], bool count);

#endif /* _UNIONFIND_H_ */
