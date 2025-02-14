#include <stdio.h>
#include <ctype.h>

#define SALES_PEOPLE 3

int main() {
    char salesperson;
    float sale;
    float grand_total = 0;

    float sales[] = {0, 0, 0};
    char initials[] = {'D', 'E', 'F'};
    char* names[] = {"Danielle", "Edward", "Francis"};

    while (1) {
        printf("Enter salesperson: ");
        scanf(" %c", &salesperson);
        salesperson = toupper(salesperson);

        if (salesperson == 'Z') break;

        int found = 0;
        for (int i = 0; i < SALES_PEOPLE; i++) {
            if (salesperson == initials[i]) {
                found = 1;
                printf("Enter sale: ");
                scanf("%f", &sale);
                sales[i] += sale;
                grand_total += sale;
                break;
            }
        }

        if (!found) {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }
    }

    int highest_salesperson_index = 0;
    for (int i = 0; i < SALES_PEOPLE; i++) {
        printf("%s's total sales: $%.2f\n", names[i], sales[i]);

        if (sales[i] > sales[highest_salesperson_index]) {
            highest_salesperson_index = i;
        }
    }

    printf("Grand Total: $%.2f\n", grand_total);
    if (grand_total != 0) printf("Highest Sale: %s\n", names[highest_salesperson_index]);

    return 0;
}

