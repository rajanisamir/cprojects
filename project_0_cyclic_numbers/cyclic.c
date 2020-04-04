/* CMSC 16200 - Homework 0
 * File: cyclic.c
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "cyclic.h"

int power(int base, int exp);
int sign(int num);
bool elem(int num, int arr[], int length);
bool generateCyclic(int p, bool print);

/* countDigits:
 * counts the number of digits in a number
 */
int countDigits(int num) {
    int digits = 0;
    while (abs(num) >= 10) {
      num /= 10;
      digits++;
    }
    return (digits + 1);
}

/* power:
 * computes the base raised to the power of an exponent
 */
int power(int base, int exp) {
  int result = 1;
  for (int i = 0; i < exp; i++) {
    result *= base;
  }
  return result;
}

/* isFullyRepeated:
 * determines if the number consists of fully repeated pattern
 */
bool isFullyRepeated(int num) {
    num = abs(num);
    int digits = countDigits(num);
    for (int i = 1; i < digits; i++) {
      if (digits % i == 0) {
        int pattern = num % power(10, i);
        int template = 0;
        for (int j = 0; j < digits; j += i) {
          template += pattern * power(10, j);
        }
        if (num == template) {
          return true;
        }
      }
    }
    return false;
}

/* sign:
 * returns -1 if the number is negative and 1 otherwise
 */
int sign(int num) {
  if (num < 0) {
    return -1;
  }
  return 1;
}

/* rightRotateDigit:
 * rotates the digits in num by d places to the right
 */
int rightRotateDigit(int num, int d) {
    // Implement this function
    int sig = sign(num);
    num = abs(num);
    int digits = countDigits(num);
    for(int i = 0; i < d; i++) {
      int lastDigit = num % 10;
      num -= lastDigit;
      num /= 10;
      num += lastDigit * power(10, digits - 1);
    }
    num *= sig;
    return num;
}

/* leftRotateDigit:
 * rotates the digits in num by d places to the left
 */
int leftRotateDigit(int num, int d) {
    // Implement this function
    int sig = sign(num);
    num = abs(num);
    int digits = countDigits(num);
    for(int i = 0; i < d; i++) {
      int firstDigit = num / power(10, digits - 1);
      num -= firstDigit * power(10, digits - 1);
      num *= 10;
      num += firstDigit;
    }
    num *= sig;
    return num;
}

/* elem:
 * returns true if num is an element of arr; returns false otherwise
 */
bool elem(int num, int arr[], int length) {
  for (int i = 0; i < length; i++) {
    if (num == arr[i]) {
      return true;
    }
  }
  return false;
}

/* isCyclicBad:
 * naive implementation for determining if a number is a cyclic number
 */
bool isCyclicBad(int num) {
    int digits = countDigits(num);
    if (isFullyRepeated(num) || digits == 1) {
      return false;
    }
    int templates[digits];
    int multiples[digits];
    for (int i = 0; i < digits; i++) {
      templates[i] = rightRotateDigit(num, i);
    }
    for (int i = 0; i < digits; i++) {
      multiples[i] = num * (i + 1);
    }
    for (int i = 0; i < digits; i++) {
      if (!(elem (multiples[i], templates, digits))) {
        return false;
      }
    }
    return true;
}

/* isPrime:
 * determines if a number is a prime
 */
bool isPrime(int num) {
  if ((num == 0) | (num == 1)) {
    return false;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return false;
    }
    if (i * i >= num) {
      break;
    }
  }
  return true;
}

/* generateCyclic:
 * returns true if p generates a cyclic number, false otherwise
 * prints out the cyclic number if print is true
 */
bool generateCyclic(int p, bool print) {
  int t = 0;
  int r = 1;
  do {
    t++;
    int x = r * 10;
    int d = x / p;
    if (print) {
      printf("%d", d);
    }
    r = x % p;
  } while (r != 1 && t < p);
  if (print) {
    printf("\n");
  }
  if (t == p - 1) {
    return true;
  }
  return false;
}

/* kthCyclic:
 * finds the kth cyclic number using Fermat's quotient form
 */
int kthCyclic(int k, int flag) {
  int i = 1;
  int p = 2;
    while (true) {
      if (isPrime(p) && generateCyclic(p, false)) {
        if (i < k) {
          i++;
        }
        else {
          if (flag == 1) {
            generateCyclic(p, true);
          }
          return p;
        }
      }
      p++;
    }
}
