/* CMSC 16200 - Homework 3
 * File: hashtable.c
 * Implementation of hash table
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

/* given a size, allocates a hashtable of that size and returns its address
   returns NULL if size parameter is invalid or if malloc fails */
hashtable* allocate(int size){
    // return NULL if size parameter is invalid
    if (size <= 0) return NULL;

    // allocate hashtable, return NULL if malloc fails
    hashtable* ht = malloc(sizeof(hashtable));
    if (ht == NULL) return NULL;

    // set/allocate data for hashtable, return NULL if malloc fails
    ht->size = size;
    ht->table = malloc(size*sizeof(entry*));
    if (ht->table == NULL) return NULL;
    for (int i = 0; i < size; i++) {
        (ht->table)[i] = NULL;
    }

    // return the created hashtable
    return ht;
}

/* given a hashtable ht, a key, and a value, inserts that key-value pair into the hashtable
   updates the value if the key already exists in the hashtable
   returns 0 to indicate success and -1 otherwise */
int put(hashtable* ht, keyType key, valType value){
    // return -1 if hashtable is NULL
    if (ht == NULL) return -1;

    int index = hash(key, ht->size);
    entry* curEntry = (ht->table)[index];

    // if the linked list is empty, add newEntry as its first node
    if (curEntry == NULL) {
        entry* newEntry = malloc(sizeof(entry));
        if (newEntry == NULL) return -1;
        newEntry->key = key;
        newEntry->value = value;
        newEntry->next = NULL;
        (ht->table)[index] = newEntry;
    }


    else {
        // advance curEntry until the key matches or it reaches the end of the list
        while (curEntry->key != key && curEntry->next != NULL) {
            curEntry = curEntry->next;
        }

        // if the key exists in the hashtable, update its value
        if (curEntry-> key == key) {
            curEntry->value = value;
        }

        // if the key does not exist in the hashtable, insert a new entry into the list
        else {
            entry* newEntry = malloc(sizeof(entry));
            if (newEntry == NULL) return -1;
            newEntry->key = key;
            newEntry->value = value;
            newEntry->next = NULL;
            curEntry->next = newEntry;
        }
    }

    // return 0 to indicate success
    return 0;
}

/* given a hashtable ht and a key, returns that value associated with the key
   returns -1 if the key does not exist within the hashtable */
valType get(hashtable* ht, keyType key){
    // return -1 if the hashtable is NULL
    if (ht == NULL) return -1;

    int index = hash(key, ht->size);
    entry* curEntry = (ht->table)[index];

    // if the linked list is empty, return -1
    if (curEntry == NULL) return -1;

    // if the first entry of the linked list is the key, return the associated value
    if (curEntry->key == key) return curEntry->value;

    // advance curEntry and nextEntry until the key matches or it reaches the end of the list
    entry* nextEntry = curEntry->next;
    while (nextEntry != NULL && nextEntry->key != key) {
        curEntry = nextEntry;
        nextEntry = nextEntry->next;
    }

    // if the key doesn't exist in the hashtable, return -1
    if (nextEntry == NULL) return -1;

    // if the key exists in the hashtable, return the associated value
    return nextEntry->value;
}

/* given a hashtable ht and a key, deletes the key
   returns 0 if the entry is successfully deleted
   returns -1 if the key is not found or the hashtable is NULL*/
valType erase(hashtable* ht, keyType key){
    // return -1 if the hashtable is NULL
    if (ht == NULL) return -1;

    int index = hash(key, ht->size);
    entry* curEntry = (ht->table)[index];

    // if the linked list is empty, return -1
    if (curEntry == NULL) return -1;

    // if the first entry of the linked list is the key, free the entry and return 0
    if (curEntry->key == key) {
        (ht->table)[index] = curEntry->next;
        free(curEntry);
        return 0;
    }

    // advance curEntry and nextEntry until the key matches or it reaches the end of the list
    entry* nextEntry = curEntry->next;
    while (nextEntry != NULL && nextEntry->key != key) {
        curEntry = nextEntry;
        nextEntry = nextEntry->next;
    }

    // if the key doesn't exist in the hashtable, return -1
    if (nextEntry == NULL) return -1;

    // if the key exists in the hashtable, free the entry and return 0
    curEntry->next = nextEntry->next;
    free(nextEntry);
    return 0;
}


/* given the address of a hashtable, deallocates all of the memory it occupies
   returns 0 to indicate success and -1 otherwise */
int deallocate(hashtable* ht){
    // return -1 if hashtable is NULL
    if (ht == NULL) return -1;

    // free the memory associated with each linked list
    entry* curEntry;
    entry* nextEntry;
    for (int i = 0; i < ht->size; i++) {
        curEntry = (ht->table)[i];
        while(curEntry != NULL) {
            nextEntry = curEntry->next;
            free(curEntry);
            curEntry = nextEntry;
        }
    }
    free(ht->table);

    // free the memory associated with hashtable
    free(ht);

    // return 0 to indicate success
    return 0;
}

/* hash function that takes the hashtable size m and key of type string and returns an index */
int hash(keyType key, int m){
    return key % m;
}
