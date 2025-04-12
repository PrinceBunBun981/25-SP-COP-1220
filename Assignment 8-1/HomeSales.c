#include <stdio.h>
#include <ctype.h>

// Define the number of salespeople
#define SALES_PEOPLE 3

// Define the file name for the list of salespeople
#define FILE_NAME "salespeople.txt"

// Define the Salesperson struct
typedef struct {
    char initial;
    char name[20];
    float sales;
} Salesperson;

int main() {
    // Initialize variables
    char salesperson;
    float sale;
    float grand_total = 0;

    // Initialize struct array
    Salesperson salespeople[SALES_PEOPLE];

    // Open file and read salespeople data
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", FILE_NAME);
        return 1;
    }

    // Read salespeople data
    for (int i = 0; i < SALES_PEOPLE; i++) {
        // If data is not read correctly, print error message
        if (fscanf(fp, " %c %s %f", &salespeople[i].initial, salespeople[i].name, &salespeople[i].sales) != 3) {
            printf("Error reading data from file.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    // Main loop
    while (1) {
        // Get user input
        printf("Enter salesperson: ");
        scanf(" %c", &salesperson);
        salesperson = toupper(salesperson);

        // Check if user wants to exit
        if (salesperson == 'Z') break;

        // Check if salesperson is valid
        int found = 0;
        for (int i = 0; i < SALES_PEOPLE; i++) {
            // If salesperson is found, update sales and grand total
            if (salesperson == salespeople[i].initial) {
                found = 1;
                
                // User input for sale
                printf("Enter sale: ");
                scanf("%f", &sale);

                // Update sales and grand total
                salespeople[i].sales += sale;
                grand_total += sale;
                break;
            }
        }

        // If salesperson is not found, print error message
        if (!found) {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }
    }

    // Find highest salesperson and print results
    int highest_salesperson_index = 0;
    for (int i = 0; i < SALES_PEOPLE; i++) {
        printf("%s's total sales: $%.2f\n", salespeople[i].name, salespeople[i].sales);

        // Update highest salesperson
        if (salespeople[i].sales > salespeople[highest_salesperson_index].sales) {
            highest_salesperson_index = i;
        }
    }

    // Print grand total
    printf("Grand Total: $%.2f\n", grand_total);

    // If grand total is not 0, print highest salesperson
    if (grand_total != 0) printf("Highest Sale: %s\n", salespeople[highest_salesperson_index].name);

    return 0;
}