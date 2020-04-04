/* CMSC 16200 - Homework 1
 * File: list.c
 * Implementation of linked list and its operations
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//takes a linked list L as input and prints it to the console
//prints nothing if L is NULL
void print_list(linked_list *L) {
    if (L == NULL) return;
    if (L->head == NULL || L->length == 0) {
        printf("Linked list empty.\n");
        return;
    }
    list *iterator = NULL;
    printf("Linked list (len = %d): < ", L->length);
    for (iterator = L->head; iterator != NULL; iterator = iterator->next) {
        printf("%d ", iterator->data);
    }
    printf(">\n");
    return;
}

//creates and returns a linked list
linked_list *empty() {
    linked_list* emptyList = malloc(sizeof(linked_list));
    if (emptyList == NULL) {
        printf("Error: Malloc failed!");
        return NULL;
    }
    emptyList -> length = 0;
    emptyList -> head = NULL;
    return emptyList;
}

//takes an integer data as input
//creates and returns a singleton list with data as the value of its only node
linked_list *singleton(int data) {
    linked_list* newList = empty();
    if (newList == NULL) return NULL;
    list* newNode = malloc(sizeof(list));
    if (newNode == NULL) {
        printf("Error: Malloc failed!");
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    newList -> head = newNode;
    newList -> length = 1;
    return newList;
}

//takes a linked list L and integer data as input
//appends a node to L with value data
void append(linked_list *L, int data) {
    if (L == NULL) return;
    list* curNode = L -> head;
    for (int i = 0; i < (L -> length) - 1; i++) {
        curNode = curNode -> next;
    }
    list* newNode = malloc(sizeof(list));
    if (newNode == NULL) {
        printf("Error: Malloc failed!");
        return;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    if (curNode == NULL) {
        L -> head = newNode;
    }
    else {
        curNode -> next = newNode;
    }
    (L -> length)++;
    return;
}

//takes a linked list L and integer data as input
//prepends a node to L with value data
void cons(int data, linked_list *L) {
    list* newHead = malloc(sizeof(list));
    if (newHead == NULL) {
        printf("Error: Malloc failed!");
        return;
    }
    newHead -> data = data;
    newHead -> next = L -> head;
    L -> head = newHead;
    (L -> length)++;
    return;
}

//takes a linked list L as input
//removes the first element of L and returns 0 to indicate success
//fails and returns 1 if L is NULL or if L is of length 0
int pop(linked_list *L) {
    if (L == NULL || L -> head == NULL) {
        printf("Error: list contains no elements.");
        return 1;
    }
    list* toRemove = L -> head;
    int data = toRemove -> data;
    L -> head = L -> head -> next;
    free(toRemove);
    (L -> length)--;
    return data;
}

//takes a linked list L as input
//frees L and its associated nodes from memory
void free_list(linked_list *L) {
    if (L == NULL) return;
    list* curNode = L -> head;
    list* nextNode = curNode -> next;
    while (curNode != NULL) {
        nextNode = curNode -> next;
        free(curNode);
        curNode = nextNode;
    }
    free(L);
    return;
}
