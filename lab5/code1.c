#include <stdio.h>
#include <stdlib.h>
/*
Name: Ruben Pino-Martinez
Lab Name: Lab 5: IDE, compiled programs (C programming with arrays), Git
Date: 10/10/24
Objective: We will have user input sales for each month, the program will return back what each month and their respective
sales are, the months with highest/lowest sales, and the 6 month interval average for each month, and a sorted monthley Sales
list from highest to lowest
*/


/*MonthlySales struct is designed to be a storage of sales for each month
Esed throughout the program to store and manipulate monthly sales since arrays in C 
dont hold different variable types*/
typedef struct {
    // Month name as a string
    char month[10];
    // Sales for the month as an integer
    int sales;      
} MonthlySales;

int main() {
    printf("Welcome to Monthly Sales Statistics Generator!\n");

    // Create an array of MonthlySales to store the month names and initial sales
    MonthlySales sales_data[12] = {
        {"January", 0}, {"February", 0}, {"March", 0},
        {"April", 0}, {"May", 0}, {"June", 0},
        {"July", 0}, {"August", 0}, {"September", 0},
        {"October", 0}, {"November", 0}, {"December", 0}
    };

    // Loop to get sales input from the user
    for (int i = 0; i < 12; i++) {
        // Prompt the user to input their monthly sales for the specific month.
        printf("Enter your monthly sale for %s: ", sales_data[i].month);
        // Read integer from the user, store it in the sales field of the index i in the sales_data 
        scanf("%d", &sales_data[i].sales);
    }

    printf("\nMonth    Sales\n");
    for (int i = 0; i < 12; i++) {
        // Display each month with its sales
        printf("%-10s %d\n", sales_data[i].month, sales_data[i].sales);
    }

    // Sorting of instances based on sales
    for (int i = 0; i < 12; i++) {
        // Initialize maximum index to current index
        int max_index = i;
        for (int j = i + 1; j < 12; j++) {
            // Update max_index if a larger sales value is found
            if (sales_data[j].sales > sales_data[max_index].sales) {
                max_index = j;
            }
        }
        // Swap the entries if the maximum index is not the current index
        if (max_index != i) {
            MonthlySales temp = sales_data[i];
            sales_data[i] = sales_data[max_index];
            sales_data[max_index] = temp;
        }
    }

    printf("\nMonthly Sales from Highest to Lowest:\n");
    for (int i = 0; i < 12; i++) {
        // Display sorted month and sales
        printf("%-10s %d\n", sales_data[i].month, sales_data[i].sales);
    }

    // Find the minimum and maximum sales, starting first entry as min and max
    MonthlySales min_sales_entry = sales_data[0];
    MonthlySales max_sales_entry = sales_data[0];

    for (int i = 0; i < 12; i++) {
        // Update min_sales_entry if a smaller sales value is found
        if (sales_data[i].sales < min_sales_entry.sales) {
            min_sales_entry = sales_data[i];
        }
        // Update max_sales_entry if a larger sales value is found
        if (sales_data[i].sales > max_sales_entry.sales) {
            max_sales_entry = sales_data[i];
        }
    }
    // Display min and max sales
    printf("\nMinimum Sales: %d (%s)\n", min_sales_entry.sales, min_sales_entry.month);
    printf("Maximum Sales: %d (%s)\n", max_sales_entry.sales, max_sales_entry.month);

    // all sales across months
    // Initialize total_sales to 0
    int total_sales = 0;
    for (int i = 0; i < 12; i++) {
        // Add each month's sales to total_sales
        total_sales += sales_data[i].sales;
    }
    // Average sales calculation
    float average_sales = total_sales / 12.0;
    // Display average sales
    printf("Average Sales: %.2f\n", average_sales);

    // Six-Month Moving Average Report
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= 12 - 6; i++) {
        // Calculate moving average
        float moving_average = 0;
        for (int j = 0; j < 6; j++) {
            moving_average += sales_data[i + j].sales;
        }
        moving_average /= 6;
        // First and last month for the moving average
        printf("%s-%-10s %.2f\n", sales_data[i].month, sales_data[i + 5].month, moving_average);
    }
    return 0;
}
