/* CMSC 16200 - Homework 4
 * File: graph.h
 * The strict pixel graph and its interface.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "image_util.h"
#include "pixel.h"
#include "hashtable.h"

#ifndef _GRAPH_H_
#define _GRAPH_H_

struct pixel_node {
    pixelID pixel_id;
    struct pixel_node* next;
};
typedef struct pixel_node node;

struct pixel_graph_header {
    unsigned int image_width;
    unsigned int image_height;
    pixel pixels[ROWS][COLS];
    // Feel free to define more graph data below as you like.
    node* edges[ROWS*COLS];
    hashtable* counts;
};
typedef struct pixel_graph_header* graph;

// Add an edge to the adjacency list given the head node and the pixel ID of the new node.
node* add_edge(node* start, pixelID pixel_id);

// Return true if pixel1 and pixel2 have the same ARGB colors.
bool same_color(pixel pixel1, pixel pixel2);

// Allocate enough space for the graph, and intialize its required fields.
graph pixel_graph_new(unsigned int img_width,
                      unsigned int img_height,
                      pixel pixels[ROWS][COLS]);

// Free up the memory used by graph G.
void pixel_graph_free(graph G);

#endif /* _GRAPH_H_ */
