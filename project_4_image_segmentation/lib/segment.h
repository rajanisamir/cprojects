/* CMSC 16200 - Homework 4
 * File: segment.h
 * Interface for operations on connected components
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "unionfind.h"

#ifndef _SEGMENT_H_
#define _SEGMENT_H_

/* Counting the connected components in the image. */
int count_connected_components(graph G, pixelID parentID[ROWS][COLS]);

/* Labeling the connected components in the image. */
void label_connected_components(graph G, pixelID parentID[ROWS][COLS]);

#endif /* _SEGMENT_H_ */
