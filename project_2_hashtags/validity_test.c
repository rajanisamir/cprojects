#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "lib/validity.h"


int main(void) {
    // Testing sentence2hashtag
    printf("%s\n", "Testing sentence2hashtag ...");

    char *a = (char*) malloc(16 * sizeof(char));
    strcpy(a, "I'm adventurous");
    sentence2hashtag(a);
    assert(strcmp(a, "imadventurous") == 0);

    char *f = (char*) malloc(14 * sizeof(char));
    strcpy(f, "ABC  %^#$ XYZ");
    sentence2hashtag(f);
    assert(strcmp(f, "abcxyz") == 0);

    printf("%s\n", "Passed all tests!");


    // Testing is_valid_hashtag
    printf("%s\n", "Testing is_valid_hashtag ...");

    assert(is_valid_hashtag(a));

    char *b = (char*) malloc(19 * sizeof(char));
    strcpy(b, "somewordsandasdfgh");
    assert(!is_valid_hashtag(b));

    char *c = (char*) malloc(20 * sizeof(char));
    strcpy(c, "hashtagwithouttypos");
    assert(is_valid_hashtag(c));

    char *d = (char*) malloc(17 * sizeof(char));
    strcpy(d, "hashtagwithatpyo");
    assert(!is_valid_hashtag(d));

    char *e = (char*) malloc(3 * sizeof(char));
    strcpy(e, "of");
    assert(is_valid_hashtag(e));

    printf("%s\n", "Passed all tests!");

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return 0;
}
