#ifndef CIPHER_UTIL_H
#define CIPHER_UTIL_H

void caesar_cipher(char *text, int shift, int is_encrypt);
void brute_force_decrypt(char *text);
void vigenere_cipher(char *text, char *key, int is_encrypt);

#endif
