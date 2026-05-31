//
// Created by kylem on 5/31/2026.
//
#include <stdio.h>

static const double MASS = 0.45359237;

double convert_lbs_to_kgs(double amount) {
    double kg_res = amount * MASS;
    return kg_res;
}

double convert_kgs_to_lbs(double amount) {
    double lbs_res = amount / MASS;
    return lbs_res;
}

int main() {
    int choice = 0;
    double lbs = 0.0;
    double kgs = 0.0;

    printf("========================================\n");
    printf("MASS CONVERTER\n");
    printf("========================================\n\n");

    printf("What conversion would you like to perform?\n");
    printf("(1) convert lbs to kgs.\n");
    printf("(2) convert kgs to lbs.\n");
    printf("Enter an option (type 1 or 2): ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("Choose an option (type 1 or 2): ");
        scanf("%d", &choice);
    } else if (choice == 1) {
        printf("Type the amount of lbs: ");
        scanf("%lf", &lbs);
        kgs = convert_lbs_to_kgs(lbs);
        printf("%.2lf lbs converts to %.2lf kgs.\n", lbs, kgs);
    } else if (choice == 2) {
        printf("Type the amount of kgs: ");
        scanf("%lf", &kgs);
        lbs = convert_kgs_to_lbs(kgs);
        printf("%.2lf kgs converts to %.2lf lbs.\n", kgs, lbs);
    } else {
        printf("Invalid Choice! You did not input a correct option.\n");
    }

    printf("Program exiting...\n");
    printf("========================================\n");
    return 0;
}
