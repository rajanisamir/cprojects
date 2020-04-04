/* CMSC 16200 - Homework 4
 * File: segment.c
 * Implementations for operations on connected component.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lib/segment.h"
#include "lib/unionfind.h"
#include "lib/hashtable.h"
#include "lib/colors.h"

/* Counting the connected components in the image. */
int count_connected_components(graph G, pixelID parentID[ROWS][COLS]) {
    int count = 0;
    for (unsigned int i = 0; i < G->image_height; i++) {
        for (unsigned int j = 0; j < G->image_width; j++) {
            if (parentID[i][j] == -1) {
                put(G->counts, get_pixel_id(i, j, G->image_width), count);
                count++;
            }
        }
    }
    printf("The number of connected components in this image is: %d.\n", count);
    return count;
}

/* Labeling the connected components in the image. */
void label_connected_components(graph G, pixelID parentID[ROWS][COLS]) {
    for (unsigned int i = 0; i < G->image_height; i++) {
        for (unsigned int j = 0; j < G->image_width; j++) {
                pixelID parent = up_trees_find(parentID,
                    G->image_width, get_pixel_id(i, j, G->image_width));
                int count = get(G->counts, parent);
                (G->pixels)[i][j] = get_color(count);
        }
    }
    provided_write_png("img/output.png", G->pixels, G->image_height, G->image_width);
}
