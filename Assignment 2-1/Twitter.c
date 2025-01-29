#include <stdio.h>
#include <string.h>

int main() {
    char tweet[1024];

    printf("Enter a tweet: ");
    scanf("%[^\n]", tweet);

    if (strlen(tweet) <= 140) {
        printf("Posted\n");
    } else {
        printf("Rejected\n");
    }
}