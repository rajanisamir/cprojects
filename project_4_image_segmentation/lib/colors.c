/* CMSC 16200 - Homework 4
 * File: colors.c
 * A sample set of colors to choose from for our image segmentation.
 * (Source of color design: http://www.flatdesigncolors.com)
 */

#include <stdlib.h>
#include <stdio.h>
#include "colors.h"

int get_color(int k) {
    int palette[24] = {0xFF61BD6D, 0xFF1ABC9C, 0xFF54ACD2, 0xFF2C82C9, 0xFF9365B8, 0xFF475577,
                       0xFF41A85F, 0xFF00A885, 0xFF3D8EB9, 0xFF2969B0, 0xFF553982, 0xFF28324E,
                       0xFFF7DA64, 0xFFFBA026, 0xFFEB6B56, 0xFFE25041, 0xFFA38F84, 0xFFEFEFEF,
                       0xFFFAC51C, 0xFFF37934, 0xFFD14841, 0xFFB8312F, 0xFF75706B, 0xFFD1D5D8};
    return palette[k % 24];
}
