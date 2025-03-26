#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int is_punctuation(char c) {
    return (c == '.' || c == ',' || c == '!' || c == '?' || c == ';' || c == ':');
}

void to_piglatin(char *word) {
    int len = strlen(word);

    // Check if the word ends with punctuation
    char punctuation = '\0';
    if (is_punctuation(word[len - 1])) {
        punctuation = word[len - 1];
        word[len - 1] = '\0';
        len--;
    }

    int i = 0;
    while (i < len && !is_vowel(word[i])) {
        i++;
    }
    
    if (i == 0) {
        // If the word starts with a vowel, just append "yay"
        printf("%syay", word);
    } else {
        // Move the consonant cluster to the end
        for (int j = i; j < len; j++) {
            printf("%c", word[j]);
        }
        for (int j = 0; j < i; j++) {
            printf("%c", word[j]);
        }
        // Append "ay"
        printf("ay");
    }

    if (punctuation != '\0') {
        printf("%c", punctuation);
    }
}

// This does not work fully, I cannot be asked to use a dictionary.
void from_piglatin(char *word) {
    int len = strlen(word);

    char punctuation = '\0';
    if (ispunct(word[len - 1])) {
        punctuation = word[len - 1];
        word[len - 1] = '\0';
        len--;
    }

    if (len > 2 && strcmp(word + len - 3, "yay") == 0) {
        // Word started with a vowel
        word[len - 3] = '\0'; // Remove "yay"
        printf("%s", word);
    } else if (len > 2 && strcmp(word + len - 2, "ay") == 0) {
        word[len - 2] = '\0'; // Remove "ay"
        len -= 2;

        int i = len - 1;
        while (i >= 0 && !is_vowel(word[i])) {
            i--;
        }

        // Move the consonant cluster back to the front
        printf("%s", word + i + 1);
        for (int j = 0; j <= i; j++) {
            printf("%c", word[j]);
        }
    } else {
        printf("%s", word);
    }

    if (punctuation != '\0') {
        printf("%c", punctuation);
    }
}

int main() {
    char text[1024];

    printf("Enter text: ");
    scanf(" %[^\n]", text);

    int option = 1; // Default to English -> Pig Latin since Pig Latin -> English is broken
    // printf("Choose an option:\n");
    // printf("1: Convert to Pig Latin\n");
    // printf("2: Convert to English\n");
    // printf("Enter your choice (1 or 2): ");
    // scanf("%d", &option);

    if (option == 1) {
        printf("Pig Latin: ");
        char* word = strtok(text, " ");

        while (word != NULL) {
            to_piglatin(word);
            printf(" ");
            word = strtok(NULL, " ");
        }

        printf("\n");
    } else if (option == 2) {
        printf("English: ");
        char* word = strtok(text, " ");

        while (word != NULL) {
            from_piglatin(word);
            printf(" ");
            word = strtok(NULL, " ");
        }

        printf("\n");
    } else {
        printf("Invalid option\n");
    }
}