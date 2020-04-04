/* CMSC 16200 - Homework 4
 * File: graph.c
 * The strict pixel graph and its implementation.
 */

#include <stdlib.h>
#include <stdio.h>
#include "lib/graph.h"

/*
 * Depending on your implementation,
 * You might want to define helper functions, such as:
 *  - bool is_vertex(graph G, pixelID v);
 *  - bool is_pixel_graph(struct pixel_graph_header *G);
 *  - bool pixel_graph_isedge(graph G, pixelID v, pixelID w);
 *  - etc.
 * for testing your graph implementation.
 */

// Add an edge to the adjacency list given the head node and the pixel ID of the new node.
node* add_edge(node* start, pixelID pixel_id) {
    // Allocate space for new node and initialize its fields.
    node* new_node = malloc(sizeof(node));
    new_node->pixel_id = pixel_id;
    new_node->next = start;
    return new_node;
}

// Return true if pixel1 and pixel2 have the same ARGB colors.
bool same_color(pixel pixel1, pixel pixel2) {
    bool same_red = get_red(pixel1) == get_red(pixel2);
    bool same_green = get_green(pixel1) == get_green(pixel2);
    bool same_blue = get_blue(pixel1) == get_blue(pixel2);
    return same_red && same_green && same_blue;
}

// Allocate enough space for the graph, and initialize its required fields.
graph pixel_graph_new(unsigned int img_width,
                      unsigned int img_height,
                      pixel pixels[ROWS][COLS]) {
    // Allocate space for graph and initialize its width, height, and connected components hashtable.
    graph G = malloc(sizeof(struct pixel_graph_header));
    G->image_width = img_width;
    G->image_height = img_height;
    G->counts = allocate(10);
    // Initialize pixels and edges of graph.
    for (unsigned int i = 0; i < img_width; i++) {
        for (unsigned int j = 0; j < img_height; j++) {
            // Initialize current pixel.
            (G->pixels)[i][j] = pixels[i][j];
            pixelID pixel_id = get_pixel_id(i, j, img_width);
            // Add right edge to pixel if there is a matching color pixel to the right.
            if (i + 1 < img_width && same_color((G->pixels)[i][j], (G->pixels)[i+1][j])) {
                G->edges[pixel_id] = add_edge(G->edges[pixel_id], pixel_id + 1);
            }
            // Add left edge to pixel if there is a matching color pixel to the left.
            if (i > 0 && same_color((G->pixels)[i][j], (G->pixels)[i-1][j])) {
                G->edges[pixel_id] = add_edge(G->edges[pixel_id], pixel_id - 1);
            }
            // Add bottom edge to pixel if there is a matching color pixel to the bottom.
            if (j + 1 < img_height && same_color((G->pixels)[i][j], (G->pixels)[i][j+1])) {
                G->edges[pixel_id] = add_edge(G->edges[pixel_id], pixel_id + img_width);
            }
            // Add top edge to pixel if there is a matching color pixel to the top.
            if (j > 0 && same_color((G->pixels)[i][j], (G->pixels)[i][j-1])) {
                G->edges[pixel_id] = add_edge(G->edges[pixel_id], pixel_id - img_width);
            }
        }
    }
    return G;
}

// Free up the memory used by graph G.
void pixel_graph_free(graph G) {
    // Free memory occupied by edge adjacency list.
    node* cur;
    node* temp;
    for (int i = 0; i < ROWS*COLS; i++) {
        cur = (G->edges)[i];
        while (cur != NULL) {
            temp = cur->next;
            free(cur);
            cur = temp;
        }
    }
    // Free memory occupied by connected component count hashtable.
    deallocate(G->counts);
    // Free memory occupied by graph.
    free(G);
}
