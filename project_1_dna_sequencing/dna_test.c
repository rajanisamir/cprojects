#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dna.h"

//helper function prototypes
int stringLength(char *s);

int main(void) {
    char *str1 = NULL;
    printf("Length of str1: %d\n", stringLength(str1));

    char *str2 = "testing";
    printf("Length of str2: %d\n", stringLength(str2));

    strand *a = empty_strand();
    print_seq(a);
    free_strand(a);

    strand *b = string2strand("CGAT");
    print_seq(b);
    free_strand(b);

    strand *c = string2strand(NULL);
    print_seq(c);
    free_strand(c);

    strand *d = empty_strand();
    cons_strand('A', d);
    print_seq(d);
    free_strand(d);

    strand *e = string2strand("");
    print_seq(e);
    free_strand(e);

    strand *f = string2strand("ATG");
    cons_strand('C', f);
    print_seq(f);
    free_strand(f);

    printf("Passed all tests!\n");
    return 0;
}
