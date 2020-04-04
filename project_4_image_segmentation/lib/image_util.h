/* CMSC 16200 - Homework 4
 * File: image_util.h
 * Utility functions for image processing
 */

#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

#ifndef _PNG_FUNCTIONS_H_
#define _PNG_FUNCTIONS_H_

#define ROWS 1000
#define COLS 1000

#define QUALITY 100

void read_png_file(char* file_name);

void write_png_file(char* file_name);

void buffer_to_arrays(pixel pixels[ROWS][COLS]);

void arrays_to_buffer(pixel pixels[ROWS][COLS]);

void free_buffer(void);

int provided_read_png(char *filename,
    pixel pixels[ROWS][COLS],
    unsigned int *image_width,
    unsigned int *image_length);

int provided_write_png(char *filename,
    pixel pixels[ROWS][COLS],
    unsigned int image_width,
    unsigned int image_length);

void abort_(const char * s, ...);

int provided_print_image_to_html(char *filename,
    pixel pixels[ROWS][COLS],
    unsigned int image_width,
    unsigned int image_height);

#endif /* _PNG_FUNCTIONS_H_ */
