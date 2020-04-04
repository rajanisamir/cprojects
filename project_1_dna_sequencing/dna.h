/* CMSC 16200 - Homework 1
 * File: dna.h
 */

#ifndef _DNA_H_
#define _DNA_H_

typedef struct dna_header strand;

void print_seq(strand *L);

strand *empty_strand();

void cons_strand(char data, strand *S);

strand *string2strand(char *s);

void free_strand(strand *S);

struct base_node {
    char data;
    struct base_node* next;
};
typedef struct base_node seq;

struct dna_header {
    int length;
    seq* head;
};

#endif
