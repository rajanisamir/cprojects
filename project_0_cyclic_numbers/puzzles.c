/* CMSC 16200 - Homework
 * File: puzzles.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include "puzzles.h"

/* Begin of Puzzle 1 */
/* VOL computes the product of its three arguments */
#define VOL(X,Y,Z) (X)*(Y)*(Z)

int volume() {
    int v = VOL(1+1,2+2,3+3);
    printf("volume = %d\n", v);
    return v;
}

int puzzle1() {
    volume();
    return 0;
}
/* End of Puzzle 1 */

/* Begin of Puzzle 2 */
/* swap function swaps the values of a and b */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

int puzzle2() {
    int a = 2;
    int b = 3;
    printf("Before: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After : a = %d, b = %d\n", a, b);
    return 0;
}
/* End of Puzzle 2 */

/* Begin of Puzzle 3 */
void add1(int *p) {
    if (p == NULL) {
      return;
    }
    printf("Before: %d\n", *p);
    *p = *p + 1;
    printf("After : %d\n", *p);
}

int puzzle3() {
    int* p = malloc(sizeof(int));
    if (p == NULL) {
      return 1;
    }
    *p = 0;
    add1(p);
    free(p);
    return 0;
}
/* End of Puzzle 3 */

/* Begin of Puzzle 4 */
/* test_safe_add function can add any two integers without error */
bool test_safe_add(int a, int b) {
    if ((a > 0) & (b > 0)) {
        return a + b > 0;
    }
    if ((a < 0) & (b < 0)) {
        return a + b < 0;
    }
    return true;
}

int puzzle4() {
    int a = INT_MAX - 3;
    int b = 5;
    if (!test_safe_add(a,b)) {
        printf("Unsafe addition detected: %d + %d\n", a, b);
        return 1;
    } else {
        printf("%d + %d = %d\n", a, b, a + b);
        return 0;
    }
}
/* End of Puzzle 4 */

/* Begin of Puzzle 5 */
/* test_safe_div function divides any two integers without error */
bool test_safe_div(int b) {
    return b != 0;
}

int puzzle5() {
    int a = 42;
    int b = 0;
    if (!test_safe_div(b)) {
        printf("Unsafe division detected: %d / %d\n", a, b);
        return 1;
    } else {
        printf("%d / %d = %d\n", a, b, a / b);
        return 0;
    }
}
/* End of Puzzle 5 */

/* Begin of Puzzle 6 */
/* set_vector function fills a length-n array with integer v */
void set_vector(int *vec, int n, int v) {
    for (int i = 0; i < n; i++) {
        vec[i] = v;
    }
    return;
}

int puzzle6() {
    int* vec_i = malloc(3*sizeof(int));
    int value_i = 0;
    if (vec_i == NULL) {
        printf("malloc failed.\n");
        return 1;
    } else {
        set_vector(vec_i, 3, value_i);
        printf("A vector of integers: %d\n", vec_i[0]);
        free(vec_i);
    }
    return 0;
}
/* End of Puzzle 6 */
