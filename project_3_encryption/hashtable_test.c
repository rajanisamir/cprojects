/* CMSC 16200 - Homework 3
 * File: hashtable_test.c
 * Test of hash table
 */

#include "lib/hashtable.h"
#include <stdlib.h>
#include <stdio.h>


int main(void) {

  hashtable* ht = allocate(20);

  keyType key = "Key1";
  valType value = 1;

  put(ht, key, value);

  valType result = get(ht, key);
  printf("The value of %s is %d\n", key, result);

  erase(ht, key);
  result = get(ht, key);
  printf("The value of %s is %d\n", key, result);


  deallocate(ht);




  hashtable* ht2 = allocate(100);

  key = "Hello";
  value = 6;

  put(ht2, key, value);

  key = "Whoa";
  value = 2;
  put(ht2, key, value);

  key = "ab";
  value = 3;
  put(ht2, key, value);

  key = "ba";
  value = 5;
  put(ht2, key, value);

  valType result2 = get(ht2, "ab");
  printf("The value of %s is %d\n", key, result2);

  erase(ht2, key);
  result2 = get(ht2, key);
  printf("The value of %s is %d\n", key, result2);

  printf("All tests have been successfully passed.\n");
  return 0;
}
