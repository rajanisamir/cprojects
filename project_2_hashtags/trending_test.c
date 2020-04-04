#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib/trending.h"

int main(void) {
    // Testing count_frequencies
    printf("%s\n", "Testing count_frequencies ...");

    const char **a = calloc(4, sizeof(char*));
    a[0] = "bobcat";
    a[1] = "chipmunk";
    a[2] = "eagle";
    a[3] = "tortoise";

    int *b = (int*) calloc(4, sizeof(int));
    b[0] = 2;
    b[1] = 1;
    b[2] = 3;
    b[3] = 1;

    const char **c = calloc(7, sizeof(char*));
    c[0] = "tortoise";
    c[1] = "tortoise";
    c[2] = "Hare";
    c[3] = "Hare";
    c[4] = "Hare";
    c[5] = "chipmunk";
    c[6] = "bobcat";

    int result = count_frequencies(a, b, 4, c, 7, true);
    assert(result == 3);
    assert(b[0] == 3);
    assert(b[1] == 2);
    assert(b[2] == 3);
    assert(b[3] == 3);

    free(a);
    free(b);
    free(c);

    printf("%s\n", "Passed all tests!");

    // Testing top_three
    printf("%s\n", "Testing top_three ...");

    int *d = (int*) calloc(4, sizeof(int));
    d[0] = 2;
    d[1] = 1;
    d[2] = 3;
    d[3] = 1;

    int *e = (int*) calloc(3, sizeof(int));

    top_three(d, e, 4);
    assert(e[0] == 2);
    assert(e[1] == 0);
    assert(e[2] == 1);

    free(d);
    free(e);

    int *f = (int*) calloc(2, sizeof(int));
    f[0] = 2;
    f[1] = 1;

    int *g = (int*) calloc(3, sizeof(int));

    top_three(f, g, 2);
    assert(g[0] == 0);
    assert(g[1] == 1);

    free(f);
    free(g);

    printf("%s\n", "Passed all tests!");


    return 0;
}
