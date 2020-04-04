#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dna.h"
#include "cquence.h"

int main(void) {
    //tests for join function
    printf("\n\nJOIN TESTS\n");
    strand *a = string2strand("CGAT");
    print_seq(a);
    strand *b = string2strand("AGC");
    print_seq(b);
    strand *c = join(a,b);
    print_seq(c);
    strand *e = join(empty_strand(), empty_strand());
    print_seq(e);
    strand *f = join(NULL, b);
    print_seq(f);
    strand *g = join(a,empty_strand());
    print_seq(g);

    printf("\n\nINTERLEAVE TESTS\n");
    //tests for interleave function
    strand *d = interleave(a,b);
    print_seq(d);
    strand *h = interleave(empty_strand(), empty_strand());
    print_seq(h);
    strand *i = interleave(a, NULL);
    print_seq(i);
    strand *j = interleave(empty_strand(), b);
    print_seq(j);
    strand *k = string2strand("A");
    print_seq(k);
    strand *l = interleave(k, a);
    print_seq(l);

    //tests for inject function
    printf("\n\nINJECT TESTS\n");
    inject(a,b,0);
    print_seq(a);
    inject(a,b,5);
    print_seq(a);
    printf("%d\n",inject(a,b,-1));
    print_seq(a);
    printf("%d\n",inject(a,NULL,2));
    print_seq(a);
    strand *q = empty_strand();
    inject(q,b,0);
    print_seq(q);

    //tests for the isPrefix function
    printf("\n\nISPREFIX TESTS\n");
    strand *m = string2strand("ATG");
    strand *n = string2strand("AT");
    strand *o = string2strand("AC");
    strand *r = empty_strand();
    printf("%d\n", isPrefix(m,n));
    printf("%d\n", isPrefix(n,m));
    printf("%d\n", isPrefix(m,o));
    printf("%d\n", isPrefix(m,r));
    printf("%d\n", isPrefix(m,NULL));
    printf("%d\n", isPrefix(NULL,m));

    //tests for the find function
    printf("\n\nFIND TESTS\n");
    printf("%d\n",find(a,b));
    strand *p = string2strand("TG");
    printf("%d\n",find(b,a));
    printf("%d\n",find(m,o));
    printf("%d\n",find(m,p));
    strand *s = string2strand("GCA");
    printf("%d\n",find(a,s));

    printf("\n\nSNIP TESTS\n");
    print_seq(a);
    print_seq(b);
    printf("%d\n", snip(a,b));
    print_seq(a);
    printf("%d\n",find(a,b));
    snip(a,b);
    print_seq(a);
    printf("%d\n",find(a,b));
    printf("%d\n", snip(a,b));
    print_seq(a);

    free_strand(a);
    free_strand(b);
    free_strand(c);
    free_strand(d);
    free_strand(e);
    free_strand(f);
    free_strand(g);
    free_strand(h);
    free_strand(i);
    free_strand(j);
    free_strand(k);
    free_strand(l);
    free_strand(m);
    free_strand(n);
    free_strand(o);
    free_strand(p);
    free_strand(q);
    free_strand(r);
    free_strand(s);
    free_strand(t);

    printf("\n\n");
    printf("Passed all tests!\n\n");
	return 0;
}
