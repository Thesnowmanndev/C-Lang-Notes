//
// Created by kylem on 5/29/2026.
//
#include <stdio.h>
#include <math.h>

int main() {
    printf("========================================\n");
    printf("Compound Interest Calculator\n");
    printf("========================================\n");
    printf("\n\n");

    double principal = 0.0;
    printf("Enter the principal: ");
    scanf("%lf", &principal);

    double rate = 0.0;
    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &rate);
    rate = rate / 100;

    int times_compounded = 0;
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%d", &times_compounded);

    int years = 0;
    printf("Enter the amount of time (years): ");
    scanf("%d", &years);

    double total = principal * pow(1 + rate / times_compounded, times_compounded * years);

    printf("----------------------------------------\n\n");
    printf("After %d years, the total is: $%.2lf", years, total);

    return 0;
}