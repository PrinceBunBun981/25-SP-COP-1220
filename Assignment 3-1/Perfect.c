#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_perfect(int num) {
    int total = 0;
    for (int i = 1; i < num; ++i) {
        if (num % i == 0) {
            total += i;
        }
    }
    return total == num;
}

int main() {
    printf("Enter a number to check if it's a Perfect Number: ");
    int num;
    if (scanf("%d", &num) != 1 || num <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    if (is_perfect(num)) {
        printf("Perfect Number.\n");
    } else {
        printf("Not a Perfect Number.\n");
    }
    return 0;
}