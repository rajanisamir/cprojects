/* CMSC 16200 - Homework 3
 * File: encrypt.c
 * Implementation of encryption
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/english.h"
#include "lib/hashtable.h"
#include "lib/encrypt.h"

/* given a langauge A, an allocated hashtable ht, the size of the langauge wordcount,
   a string key, a string plain, and a string cipher, uses the key to encipher plain and
   saves it in cipher */
void encipher_word(word_t *A, hashtable* ht, int wordcount,
                   word_t key, word_t plain, word_t cipher) {
    int keyIndex = get(ht, key);
    int plainIndex = get(ht, plain);
    int cipherIndex = (keyIndex + plainIndex) % wordcount;
    strcpy(cipher, A[cipherIndex]);
}

/* given a langauge A, an allocated hashtable ht, the size of the langauge wordcount,
   an array of strings key_sentence, the length of the key key_len, an array of strings
   plain_text, an array of strings cipher_text, and the length of the ciphertext txt_len,
   uses the key to encipher plain_text and saves it in cipher_text */
void encrypt_msg(word_t *A, hashtable* ht, int wordcount,
                 word_t *key_sentence, int key_len,
                 word_t *plain_text, word_t *cipher_text, int txt_len) {
    for (int i = 0; i < txt_len; i++) {
        encipher_word(A, ht, wordcount, key_sentence[i % key_len], plain_text[i], cipher_text[i]);
    }
}
