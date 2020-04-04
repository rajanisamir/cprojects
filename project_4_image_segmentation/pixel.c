/* CMSC 16200 - Homework 4
 * File: pixel.c
 * The pixel type and the implementation of library for pixel ops
 */

#include <stdio.h>
#include <stdlib.h>
#include "lib/pixel.h"

// Returns its index to 1-D pixel array, given the coords of input pixel.
pixelID get_pixel_id(unsigned int x, unsigned int y, unsigned int w) {
    return y*w + x;
}

// Returns the x coordinate value of the pixel,
// given its index and the width of the image.
unsigned int get_x_coord(pixelID idx, unsigned int w) {
    return idx % w;
}

// Returns the y coordinate value of the pixel
// given its index and the width of the image.
unsigned int get_y_coord(pixelID idx, unsigned int w) {
    return idx / w;
}

// Returns the red component of the pixel p, between 0 and 255, inclusive.
int get_red(pixel p) {
  return (p >> 16) & (0xff);
}

// Returns the green component of the pixel p, between 0 and 255, inclusive.
int get_green(pixel p) {
  return (p>>8) & (0xff);
}

// Returns the blue component of the pixel p, between 0 and 255, inclusive.
int get_blue(pixel p) {
  return p & (0xff);
}

// Returns the alpha component of the pixel p, between 0 and 255, inclusive.
int get_alpha(pixel p) {
  return (p>>24) & (0xff);
}

// Returns an int representing an RGB pixel consisting of the given
// alpha, red, green and blue intensity values.
// All intensity values must be between 0 and 255,
// inclusive.
pixel make_pixel(int alpha, int red, int green, int blue) {
  return (alpha<<24) | (red<<16) | (green<<8) | blue;
}
