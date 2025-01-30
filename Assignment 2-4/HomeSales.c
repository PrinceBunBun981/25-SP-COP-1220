#include <stdio.h>
#include <ctype.h>

int main() {
    char salesperson;
    float sale;
    float d_sales = 0, e_sales = 0, f_sales = 0;
    float grand_total = 0;

    while (1) {
        printf("Enter salesperson: ");
        scanf(" %c", &salesperson);
        salesperson = toupper(salesperson);

        if (salesperson == 'Z') break;

        if (salesperson != 'D' && salesperson != 'E' && salesperson != 'F') {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }

        printf("Enter sale: ");
        scanf("%f", &sale);

        if (salesperson == 'D') d_sales += sale;
        else if (salesperson == 'E') e_sales += sale;
        else if (salesperson == 'F') f_sales += sale;

        grand_total += sale;
    }

    printf("\nDanielle's total sales: $%.2f\nEdward's total sales: $%.2f\nFrancis' total sales: $%.2f\n", d_sales, e_sales, f_sales);
    printf("Grand Total: $%.2f\n", grand_total);

    if (d_sales > e_sales && d_sales > f_sales) printf("Highest Sale: Danielle\n");
    else if (e_sales > d_sales && e_sales > f_sales) printf("Highest Sale: Edward\n");
    else if (f_sales > d_sales && f_sales > e_sales) printf("Highest Sale: Francis\n");

    return 0;
}