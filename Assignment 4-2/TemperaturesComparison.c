#include <stdio.h>
#include <ctype.h>

int temperatures[5];

void is_increasing_or_decreasing(int temperatures[]) {
    if (temperatures == NULL) {
        printf("Error, temperatures array is null\n");
        return;
    }

    int temp;
    int first = temperatures[0];
    int is_decreasing = 1;
    int is_increasing = 1;
    for (int i = 1; i < 5; i++) {
        if (temperatures[i] < first) {
            is_increasing = 0;
        } else if (temperatures[i] > first) {
            is_decreasing = 0;
        }
        first = temperatures[i];
    }

    if (is_decreasing) {
        printf("Getting colder\n");
    } else if (is_increasing) {
        printf("Getting warmer\n");
    } else {
        printf("It's a mixed bag\n");
    }
}

int main() {
    int index = 0;
    while (index < 5) {
        int temp;
        printf("Enter a temperature: ");
        scanf("%d", &temp);
        
        if (temp < -30 || temp > 130) {
            printf("Temperature %d is invalid, please enter a valid temperature between -30 and 130.\n", temp);
            continue;
        }
        
        temperatures[index] = temp;
        index++;
    }

    is_increasing_or_decreasing(temperatures);
    printf("5-day Temperature [%d, %d, %d, %d, %d]\n", temperatures[0], temperatures[1], temperatures[2], temperatures[3], temperatures[4]);
    printf("Average Temperature is %0.1f degrees\n", (temperatures[0] + temperatures[1] + temperatures[2] + temperatures[3] + temperatures[4]) / 5.0);
}