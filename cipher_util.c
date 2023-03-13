#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cipher_util.h"

// encrypt or decrypt the plain-text string using caesar cipher
void caesar_cipher(char *text, int shift, int is_encrypt) {
    int i;
    char ch;
    char *copy = (char *) malloc(strlen(text) + 1);

    strcpy(copy, text);

    for(i = 0; copy[i] != '\0'; ++i) {
        ch = copy[i];

        if(ch >= 'a' && ch <= 'z') {
            if(is_encrypt) {
                ch = ch + shift;
                if(ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }
            } else {
                ch = ch - shift;
                if(ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
            }
        } else if(ch >= 'A' && ch <= 'Z') {
            if(is_encrypt) {
                ch = ch + shift;
                if(ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
            } else {
                ch = ch - shift;
                if(ch < 'A') {
                    ch = ch + 'Z' - 'A' + 1;
                }
            }
        }

        copy[i] = ch;
    }
    copy[i] = '\0'; // null terminate the copy string

    // print the encrypted or decrypted result based on the is_encrypt flag
    if(is_encrypt) {
        printf("\nEncrypted Cipher: %s\n", copy);
    } else {
        printf("\nDecrypted Cipher: %s\n", copy);
    }

    free(copy);
}

// decrypt the given cipher-text string using brute force



void brute_force_decrypt(char *text) {
    int shift;

    for(shift = 1; shift <= 25; shift++) {
        char copy[strlen(text) + 1];
        strcpy(copy, text);
        caesar_cipher(copy, shift, 0);
        printf("Shift %d\n", shift);
    }
}

// encrypt or decrypt the plain-text string using vigenere cipher
void vigenere_cipher(char *text, char *key, int is_encrypt) {
    int i, j, key_len = strlen(key), text_len = strlen(text);
    char ch;
    char *copy = (char *) malloc(text_len + 1);

    for(i = 0, j = 0; i < text_len; ++i) {
        ch = text[i];

        if(isalpha(ch)) {
            int base = isupper(ch) ? 'A' : 'a';
            ch -= base;
            int offset = isupper(key[j % key_len]) ? key[j % key_len] - 'A' : key[j % key_len] - 'a';
            ch = is_encrypt ? (ch + offset) % 26 : (ch - offset + 26) % 26;
            ch += base;
            ++j;
        }

        copy[i] = ch;
    }
    copy[i] = '\0'; // null terminate the copy string

    // print the encrypted or decrypted result based on the is_encrypt flag
    if(is_encrypt) {
        printf("\nEncrypted Cipher: %s\n", copy);
    } else {
        printf("\nDecrypted Cipher: %s\n", copy);
    }

    free(copy);
}
