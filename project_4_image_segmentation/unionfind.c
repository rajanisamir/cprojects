/* CMSC 16200 - Homework 4
 * File: unionfind.c
 * The Union Find implementation using up-trees.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib/unionfind.h"
#include "lib/hashtable.h"

/* Find and return the index of the root of the pixel with pixelID idx. */
pixelID up_trees_find(pixelID parentID[ROWS][COLS], unsigned int w, pixelID idx) {
    pixelID curParentID = parentID[get_x_coord(idx, w)][get_y_coord(idx, w)];
    while (curParentID != -1) {
        idx = curParentID;
        curParentID = parentID[get_x_coord(idx, w)][get_y_coord(idx, w)];
    }
    return idx;
}

/* Merge the two groups to which pixel p1 and pixel p2 belong. */
void up_trees_union(pixelID parentID[ROWS][COLS], unsigned int w, pixelID p1, pixelID p2) {
    pixelID parent1 = up_trees_find(parentID, w, p1);
    pixelID parent2 = up_trees_find(parentID, w, p2);
    if (p1 < p2) parentID[get_x_coord(parent2, w)][get_y_coord(parent2, w)] = parent1;
    else parentID[get_x_coord(parent1, w)][get_y_coord(parent1, w)] = parent2;
}

/* Store forest of up-trees in the array parentID, given the graph G. */
void up_trees_new(graph G, pixelID parentID[ROWS][COLS]) {
    for (unsigned int i = 0; i < G->image_height; i++) {
        for (unsigned int j = 0; j < G->image_width; j++) {
            parentID[i][j] = -1;
        }
    }
}

/*
 * Run UNION-FIND, and store the final forest of up-trees in array parentID,
 * where count is a boolean flag indicating whether to print out the count.
 */
void run_union_find(graph G, pixelID parentID[ROWS][COLS], bool count) {
    int numUnions = 0;
    for (unsigned int i = 0; i < G->image_height; i++) {
        for (unsigned int j = 0; j < G->image_width; j++) {
            pixelID curID = get_pixel_id(i, j, G->image_width);
            node* curEdge = (G->edges)[curID];
            while (curEdge != NULL) {
                if (up_trees_find(parentID, G->image_width, curEdge->pixel_id) !=
                    up_trees_find(parentID, G->image_width, curID)) {
                    up_trees_union(parentID, G->image_width, curEdge->pixel_id, curID);
                    numUnions++;
                }
                curEdge = curEdge->next;
            }
        }
    }
    if (count) {
        printf("The number of times that the method union was called for this image is: %d.\n",
                numUnions);
    }
}
