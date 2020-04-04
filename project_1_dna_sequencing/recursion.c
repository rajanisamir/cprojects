/* CMSC 16200 - Homework 1
 * File: recursion.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "recursion.h"

//takes two integers x and y
//returns x raised to the power of y
double power(int x, int y) {
    if (y == 0) return 1;
    else if (y > 0) return x * power(x, y - 1);
    else return 1 / power(x, -y);
}

//helper function for prefixSum
//takes a node and the current sum, computes the current value, and recurses
void prefixSumRecurse(list *cur, int sum) {
    if (cur == NULL) return;
    (cur -> data) += sum;
    prefixSumRecurse(cur -> next, cur -> data);
    return;
}

//takes a linked list L
//transforms L into a linked list where the ith element is the
//sum of the first i+1 elements of L
void prefixSum(linked_list *L) {
    if (L == NULL) return;
    prefixSumRecurse(L -> head, 0);
    return;
}

//takes a linked list S and an integer n
//returns true if a sub-multi-set of S can sum to form n
//returns false if S is NULL
bool subsetSum(linked_list *S, int n) {
    if (S == NULL) return false;
    if (S -> length == 0) return (n == 0);
    linked_list *T = empty();
    if (T == NULL) return false;
    T -> length = (S -> length) - 1;
    T -> head = (S -> head) -> next;
    return subsetSum(T, n) || subsetSum (T, n - (S -> head -> data));
}
