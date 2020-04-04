#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "list.h"
#include "recursion.h"

int main(void) {

    printf("\n\nLIST TEST\n\n");

    linked_list *a = empty();
    print_list(a);
    cons(20, a);
    print_list(a);
    cons(30, a);
    print_list(a);
    append(a, 10);
    print_list(a);
    pop(a);
    print_list(a);
    pop(a);
    print_list(a);
    pop(a);
    print_list(a);
    free_list(a);
    linked_list *b = singleton(42);
    print_list(b);
    free_list(b);

    printf("\n\nRECURSION TEST\n\n");

    printf("%lf\n", power(2, 7));
    printf("%lf\n", power(2, -2));
    printf("%lf\n", power(3, 4));
    printf("%lf\n", power(-2, 3));
    printf("%lf\n", power(10, 0));

    linked_list *L = singleton(-7);
    cons(1,L);
    cons(-1,L);
    cons(-7,L);
    cons(9,L);
    print_list(L);
    prefixSum(L);
    print_list(L);
    assert(subsetSum(L, 4) == true);
    assert(subsetSum(L, 0) == true);
    assert(subsetSum(L, 15) == false);
    assert(subsetSum(L, -6) == false);
    free_list(L);

    linked_list *M = singleton(1);
    append(M,2);
    append(M,3);
    append(M,4);
    print_list(M);
    prefixSum(M);
    print_list(M);
    free_list(M);

    linked_list *N = empty();
    print_list(N);
    prefixSum(N);
    print_list(N);
    free_list(N);

    printf("Passed all tests!\n\n");
    return 0;
}
