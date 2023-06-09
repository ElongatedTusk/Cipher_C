#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cipher_util.h"

int main() {
    char text[100], key[100];
    int shift, choice;

    printf("Select an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");

    scanf("%d", &choice);

    printf("Select a cipher:\n");
    printf("1. Caesar cipher\n");
    printf("2. Vigenere cipher\n");

    scanf("%d", &shift);

    if(shift == 1) {  // Caesar cipher
        if(choice == 2) {
            printf("Would you like to bruteforce or specify the number of spaces to shift?\n");
            printf("1. Bruteforce\n");
            printf("2. Specify\n");

            scanf("%d", &choice);

            if(choice == 1) {
                printf("Enter the plain-text string: ");
                scanf(" %[^\n]s", text);

                brute_force_decrypt(text);
            } else if(choice == 2) {
                printf("Enter the number of spaces to shift: ");
                scanf("%d", &shift);

                printf("Enter the plain-text string: ");
                scanf(" %[^\n]s", text);

                caesar_cipher(text, shift, choice == 1 ? 1 : 0);
            } else {
                printf("Invalid option selected!\n");
                return 0;
            }
        } else if(choice == 1) {
            printf("Enter the number of spaces to shift: ");
            scanf("%d", &shift);

            printf("Enter the plain-text string: ");
            scanf(" %[^\n]s", text);

            caesar_cipher(text, shift, choice == 1 ? 1 : 0);
        } else {
            printf("Invalid option selected!\n");
        }
    } else if(shift == 2) {  // Vigenere cipher
        if(choice == 1) {
            printf("Enter the Vigenere key: ");
            scanf("%s", key);

            printf("Enter the plain-text string: ");
            scanf(" %[^\n]s", text);

            vigenere_cipher(text, key, 1);
        } else if(choice == 2) {
            printf("Enter the Vigenere key: ");
            scanf("%s", key);

            printf("Enter the cipher-text string: ");
            scanf(" %[^\n]s", text);

            vigenere_cipher(text, key, 0);
        } else {
            printf("Invalid option selected!\n");
        }
    } else {
        printf("Invalid option selected!\n");
    }

    return 0;
}
