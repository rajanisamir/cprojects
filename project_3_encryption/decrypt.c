/* CMSC 16200 - Homework 3
 * File: decrypt.c
 * Implementation of decryption
 *
 * Name: Samir Rajani
 * CNet: srajani
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/english.h"
#include "lib/decrypt.h"
#include "lib/hashtable.h"

/* given a langauge A, an allocated hashtable ht, the size of the langauge wordcount,
   a string key, a string cipher, and a string plain, uses the key to decipher cipher and
   saves it in plain */
void decipher_word(word_t *A, hashtable* ht, int wordcount,
                   word_t key, word_t cipher, word_t plain) {
    int keyIndex = get(ht, key);
    int cipherIndex = get(ht, cipher);
    int plainIndex = (cipherIndex - keyIndex + wordcount) % wordcount;
    strcpy(plain, A[plainIndex]);
}

/* given a langauge A, an allocated hashtable ht, the size of the langauge wordcount,
   an array of strings key_sentence, the length of the key key_len, an array of strings
   cipher_text, an array of strings plain_text, and the length of the plaintext txt_len,
   uses the key to decipher cipher_text and saves it in plain_text */
void decrypt_msg(word_t *A, hashtable* ht, int wordcount,
                 word_t *key_sentence, int key_len,
                 word_t *cipher_text, word_t *plain_text, int txt_len) {
    for (int i = 0; i < txt_len; i++) {
        decipher_word(A, ht, wordcount, key_sentence[i % key_len], cipher_text[i], plain_text[i]);
    }
}
