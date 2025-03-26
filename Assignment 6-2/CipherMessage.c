#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char shift(char c, int i);
int main(int argc, char* argv[]) {
    // Make sure there is only one command-line argument
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure the entire key is a number
    for (int i = 0; i < strlen(argv[1]); i++) {
        if (!isdigit(argv[1][i]) && argv[1][i] != '-') {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    
    // Calculate the key based on the remainder
    int key = (atoi(argv[1]) % 26);
    while (key < 0) {
        key += 26;
    }
    
    // Prompt for the text to cipher
    char s[1024];
    printf("Text: ");
    scanf(" %[^\n]", s);

    // Print the ciphered text
    printf("Cipher: ");
    for (int i = 0, l = strlen(s); i < l; i++) {
        printf("%c", shift(s[i], key));
    }
    printf("\n");

    return 0;
}

char shift(char c, int i) {
    // If the character isn't a letter simply return the character
    if (!isalpha(c)) {
        return c;
    }

    int offset = 0;
    // Get a generic offset based on capital or lowercase A
    if (isupper(c)) {
        offset = 65;
    } else {
        offset = 97;
    }

    // Get the character's index including the key to shift it by
    int ci = (c - offset + i) % 26;
    return ci + offset;
}