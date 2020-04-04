/* CMSC 16200 - Homework 0
 * File: cyclic.h
 */

#ifndef _CYCLIC_H_
#define _CYCLIC_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* countDigits:
 * counts the number of digits in a number
 */
int countDigits(int num);

/* power:
 * computes the base raised to the power of an exponent
 */
int power(int base, int exp);

/* isFullyRepeated:
 * determines if the number consists of fully repeated pattern
 */
bool isFullyRepeated(int num);

/* sign:
 * returns -1 if the number is negative and 1 otherwise
 */
int sign(int num);

/* rightRotateDigit:
 * rotates the digits in num by d places to the right
 */
int rightRotateDigit(int num, int d);

/* leftRotateDigit:
 * rotates the digits in num by d places to the left
 */
int leftRotateDigit(int num, int d);

/* elem:
 * returns true if num is an element of arr; returns false otherwise
 */
bool elem(int num, int arr[], int length);

/* isCyclicBad:
 * naive implementation for determining if a number is a cyclic number
 */
bool isCyclicBad(int num);

/* isPrime:
 * determines if a number is a prime
 */
bool isPrime(int num);

/* generateCyclic:
 * returns true if p generates a cyclic number, false otherwise
 * prints out the cyclic number if print is true
 */
bool generateCyclic(int p, bool print);

/* kthCyclic:
 * finds the kth cyclic number using Fermat's quotient form
 */
int kthCyclic(int k, int flag);

#endif
