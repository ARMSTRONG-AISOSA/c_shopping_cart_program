#include <stdio.h>
#include <string.h>

int main() {
    // Shopping Cart Program

    char item[50] = " ";
    float price = 0.0f;// let's dev know it's a floating value
    int quantity = 0;
    char currency = '$';
    float total = 0.0f;

    printf("\n\033[1;34mShopping Cart Program\033[0m\n");

    printf("What item would you like to buy?: ");
    fgets(item, sizeof(item), stdin);
    item[strlen(item) - 1] = '\0'; // remove trailing newline

    printf("What is the price for each?: ");
    scanf("%f", &price);

    printf("How many would you like?: ");
    scanf("%d", &quantity);

    total = price * quantity;

    printf("\nYou have bought %d %s/s.\n", quantity, item);
    printf("The total is: ");
    printf("\033[1;33m%c%.2f.\033[0m\n\n", currency,total);

    return 0;
}