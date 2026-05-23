#include <stdio.h>
#include <string.h>

int main(void) {
    char item[50] = "";
    printf("What item would you like to buy?: ");
    fgets(item, sizeof(item), stdin);   // stdin from stdio.h
    item[strlen(item) - 1] = '\0';      // strlen from string.h 
    
    const char US_CURRENCY = '$';
    float price = 0.0f;
    printf("What is the price for each?: %c", US_CURRENCY);
    scanf("%f", &price);

    int quantity = 0;
    printf("How many would you like to buy?: ");
    scanf("%d", &quantity);

    float total = 0.0f;
    total = price * quantity;

    printf("\nYou have purchased %d %s/s.\n", quantity, item);
    printf("The total is: %c%.2f", US_CURRENCY, total);

    return 0;
}
// EXAMPLE OUTPUT:
// What item would you like to buy?: pizza 
// What is the price for each?: $15.99
// How many would you like to buy?: 3

// You have purchased 3 pizza/s.
//The total is: $47.97