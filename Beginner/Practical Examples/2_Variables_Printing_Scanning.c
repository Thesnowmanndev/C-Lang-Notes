// ## Assignment 2: Interactive Receipt Calculator

// Building on your Assignment 1, rewrite your receipt calculator so that the user can **enter their own items** instead of having them hardcoded.

// ---

// ### Your program should:

// 1. Ask the user **how many items** they want to enter (maximum 3 for now)
// 2. For each item, ask the user to enter:
//    - The **item name**
//    - The **price**
//    - The **quantity**
// 3. Calculate and display the same receipt output as Assignment 1:
//    - Each item's subtotal
//    - Pre-tax total
//    - Tax amount (10%)
//    - Final total

// ---

// ### Requirements:
// - Use `scanf()` to read numeric input (quantity and price)
// - Use `scanf()` or `fgets()` for item names
// - Keep your functions from Assignment 1 — they should still work
// - Maximum 3 items for now (you'll know why this limit exists once you learn arrays — remember our conversation!)
// - No arrays yet — store each item in its own set of variables, just like before

// ---

// ### Hint — getting input might look like this in pseudocode:
// ```
// print "Enter item name: "
// read item_name

// print "Enter price: "
// read item_price

// print "Enter quantity: "
// read item_quantity
// ```

// ---

// This will feel a bit repetitive with 3 sets of input — and that's intentional. When you learn **loops and arrays**, you'll see exactly how to clean it up. Give it a shot!

#include <stdio.h>

float calculate_subtotal(float price, int quantity){
    float result = price * quantity;
    return result;
}

float sum_price(float price1, float price2){
    float result = price1 + price2;
    return result;
}
float multiply(float amount, float percent) {
    float result = amount * percent;
    return result;
}

int convert_percentage(float tax_rate){
    int result = tax_rate * 100;
    return result;
}

int main(void) {
    int number_of_items = 0;
    printf("Enter the number of items (max of 3): ");
    scanf("%d", &number_of_items);
    printf("The total number of items: %d\n\n", number_of_items);

    char item_1_name[36];
    float item_1_price = 0.00f;
    int item_1_quantity = 0;

    printf("Item\'s name: ");
    scanf("%s", &item_1_name);
    printf("Enter %s\'s price: ", item_1_name);
    scanf("%f", &item_1_price);
    printf("%s cost: $%.2f\n", item_1_name, item_1_price);
    printf("How many of %s did you buy: ", item_1_name);
    scanf("%d", &item_1_quantity);
    printf("\n\n");

    char item_2_name[36];
    float item_2_price = 0.00f;
    int item_2_quantity = 0;

    printf("Item\'s name: ");
    scanf("%s", &item_2_name);
    printf("Enter %s\'s price: ", item_2_name);
    scanf("%f", &item_2_price);
    printf("%s cost: $%.2f\n", item_2_name, item_2_price);
    printf("How many of %s did you buy: ", item_2_name);
    scanf("%d", &item_2_quantity);
    printf("\n\n");

    char item_3_name[36];
    float item_3_price = 0.00f;
    int item_3_quantity = 0;

    printf("Item\'s name: ");
    scanf("%s", &item_3_name);
    printf("Enter %s\'s price: ", item_3_name);
    scanf("%f", &item_3_price);
    printf("%s cost: $%.2f\n", item_3_name, item_3_price);
    printf("How many of %s did you buy: ", item_3_name);
    scanf("%d", &item_3_quantity);
    printf("\n\n");

    float item_1_subtotal = calculate_subtotal(item_1_price, item_1_quantity);
    float item_2_subtotal = calculate_subtotal(item_2_price, item_2_quantity);
    float item_3_subtotal = calculate_subtotal(item_3_price, item_3_quantity);
    
    printf("ITEM NAME\t\tQUANTITY\t\tSUBTOTAL\n");
    printf("%s\t\t\t%d\t\t\t$ %.2f\n", item_1_name, item_1_quantity, item_1_subtotal);
    printf("%s\t\t\t%d\t\t\t$ %.2f\n", item_2_name, item_2_quantity, item_2_subtotal);
    printf("%s\t\t\t%d\t\t\t$ %.2f\n", item_3_name, item_3_quantity, item_3_subtotal);
    printf("\n\n");
    
    float pretax_total = sum_price(item_1_subtotal, item_2_subtotal);
    pretax_total = sum_price(pretax_total, item_3_subtotal);

    printf("Pre-Tax Total:\t\t\t\t\t$ %.2f\n", pretax_total);

    const float TAX_RATE = 0.10f;
    int tax_rate = convert_percentage(TAX_RATE);

    printf("Tax Rate:\t\t\t\t\t%d%%\n", tax_rate);

    float tax_amount = multiply(pretax_total, TAX_RATE);
    float grand_total = sum_price(pretax_total, tax_amount);

    printf("Grand Total:\t\t\t\t\t$ %.2f\n\n", grand_total);

    printf("Program Exit Successfully...\n");
    return 0;
}
