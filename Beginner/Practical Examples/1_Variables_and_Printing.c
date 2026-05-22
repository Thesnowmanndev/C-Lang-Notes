// Assignment 1: Simple Receipt Calculator
// Write a C program that calculates the total cost of a small shopping trip.
// Your program should:

// Create variables to store the price and quantity of 3 different items (you choose what the items are)
// Calculate the subtotal for each item (price × quantity)
// Calculate the total of all items combined
// Apply a 10% tax to the total
// Print out each item's subtotal, the pre-tax total, the tax amount, and the final total


// Requirements:
// Use appropriate data types (int for quantities, float or double for prices)
// Use only variables and arithmetic operators — no functions, arrays, or input needed
// All values should be hardcoded (assigned directly in the code)


// Example output might look like:
// Item 1 subtotal: 7.50
// Item 2 subtotal: 12.00
// Item 3 subtotal: 3.75

// Pre-tax total: 23.25
// Tax (10%): 2.33
// Final total: 25.58

#include <stdio.h>

static const float TAX_PERCENTAGE = 0.10;

char item_A_name[] = "Ground Beef 80/20, 2lbs";
float item_A_price = 9.89;
int item_A_quantity = 3;

char item_B_name[] = "Grade A Large Eggs, dozen";
float item_B_price = 3.49;
int item_B_quantity = 5;

char item_C_name[] = "Large Russet Potatoes Bag, 5lbs";
float item_C_price = 4.49;
int item_C_quantity = 2;

float calculate_pretotal_price(float price, int quantity) {
    float pretotal_price = price * quantity;
    return pretotal_price;
}

float calculate_pretax_total(float item_A, float item_B, float item_C) {
    float pretax_total = item_A + item_B + item_C;
    return pretax_total;
}

float calculate_tax(float pre_total) {
    float tax_total = pre_total * TAX_PERCENTAGE;
    return tax_total;
}

float calculate_grand_total(float pretax_total, float tax_total){
    float grand_total = pretax_total + tax_total;
    return grand_total;
}

int main(void) {
    float item_A_subtotal = calculate_pretotal_price(item_A_price, item_A_quantity);
    float item_B_subtotal = calculate_pretotal_price(item_B_price, item_B_quantity);
    float item_C_subtotal = calculate_pretotal_price(item_C_price, item_C_quantity);

    printf("%s subtotal: $%.2f\n", item_A_name, item_A_subtotal);
    printf("%s subtotal: $%.2f\n", item_B_name, item_B_subtotal);
    printf("%s subtotal: $%.2f\n\n", item_C_name, item_C_subtotal);

    float calculated_pretax_total = calculate_pretax_total(item_A_subtotal, item_B_subtotal, item_C_subtotal);
    float calculated_tax = calculate_tax(calculated_pretax_total);
    float grand_total = calculate_grand_total(calculated_pretax_total, calculated_tax);

    printf("Pre-tax total: $%.2f\n", calculated_pretax_total);
    printf("Tax (10 percent): $%.2f\n", calculated_tax);
    printf("Final Total: $%.2f\n", grand_total);
}