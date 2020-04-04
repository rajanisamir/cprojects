#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib/duplicates.h"

int main(void) {
    // Testing number_distinct
    printf("%s\n", "Testing number_distinct ...");

    const char **a = calloc(3, sizeof(char*)); // create an array of strings on heap
    a[0] = "hello";
    a[1] = "world";
    a[2] = "world";
    assert(2 == number_distinct(a, 3));
    free(a);

    const char **b = calloc(7, sizeof(char*));
    b[0] = "bobcat";
    b[1] = "bobcat";
    b[2] = "chipmunk";
    b[3] = "eagle";
    b[4] = "eagle";
    b[5] = "eagle";
    b[6] = "tortoise";
    assert(4 == number_distinct(b,7));
    free(b);

    const char **c = calloc(4, sizeof(char*));
    c[0] = "testing";
    c[1] = "again";
    c[2] = "words";
    c[3] = "whoa";
    assert(2 == number_distinct(c,2));
    assert(4 == number_distinct(c,4));
    free(c);

    const char **d = calloc(0, sizeof(char*));
    assert(0 == number_distinct(d,0));
    free(d);

    const char **e = calloc(1, sizeof(char*));
    e[1] = "";
    assert(1 == number_distinct(e,1));
    free(e);

    printf("%s\n", "Passed all tests!");



    // Testing indices_distinct
    printf("%s\n", "Testing indices_distinct ...");

    const char **f = calloc(7, sizeof(char*));
    int *result = calloc(4, sizeof(int));
    f[0] = "bobcat";
    f[1] = "bobcat";
    f[2] = "chipmunk";
    f[3] = "eagle";
    f[4] = "eagle";
    f[5] = "eagle";
    f[6] = "tortoise";
    indices_distinct(f, result, 7);
    assert(0 == result[0]);
    assert(2 == result[1]);
    assert(3 == result[2]);
    assert(6 == result[3]);
    free(f);

    printf("%s\n", "Passed all tests!");


    // Testing remove_duplicates
    printf("%s\n", "Testing remove_duplicates ...");
    const char **g = calloc(7, sizeof(char*));
    g[0] = "bobcat";
    g[1] = "bobcat";
    g[2] = "chipmunk";
    g[3] = "eagle";
    g[4] = "eagle";
    g[5] = "eagle";
    g[6] = "tortoise";
    char **g1 = remove_duplicates(g, 5);
    assert(strcmp("bobcat", g1[0]) == 0);
    assert(strcmp("chipmunk", g1[1]) == 0);
    assert(strcmp("eagle", g1[2]) == 0);
    free(g1);
    free(g);

    printf("%s\n", "Passed all tests!");
    return 0;
}
