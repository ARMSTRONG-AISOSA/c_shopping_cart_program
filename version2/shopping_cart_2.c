#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 100

// Function Delaration
void clear_input_buffer();

int main()
{
    // Variables
    char items[MAX_ITEMS][MAX_NAME_LENGTH];
    float prices[MAX_ITEMS]; // array to store multiple values of the same type
    int quantities[MAX_ITEMS];
    float totals[MAX_ITEMS];
    char currency = '$';
    int itemCount = 0;
    float grandTotal = 0.0f;
    bool valid = true;
    int returnedValue;

    printf("\n\033[1;34mShopping Cart Program (Multiple Items)\033[0m\n\n");

    do
    {
        valid = true;

        printf("How many different items would you like to buy? (Max %d):", MAX_ITEMS);
        returnedValue = scanf("%d", &itemCount);

        // Clear invalid input from buffer
        clear_input_buffer();

        if (returnedValue != 1 || itemCount > MAX_ITEMS || itemCount < 1) // check if entered value is numerical || greater than 50 or less than 1
        {
            valid = false;
            printf("Invalid item number.\n");
            printf("\033[3;33mRe-enter number...\033[0m\n\n");
        }

    } while (!valid);

    for (int i = 0; i < itemCount; i++)
    {
        printf("\nItem #%d:\n", i + 1);

        printf("What item would you like to buy?: ");
        fgets(items[i], sizeof(items[i]), stdin);
        items[i][strcspn(items[i], "\n")] = '\0'; // remove trailing newline

        do
        {
            printf("What is the price for each?: ");
            returnedValue = scanf("%f", &prices[i]);

            clear_input_buffer();

            // Checks if user entered a valid float. If not, returns 0.
            // OR if entered price is less than zero
            if (returnedValue != 1 || prices[i] < 0)
            {
                printf("Invalid input. Please enter a valid number\n");

                returnedValue = 0; // to initiate loop
            }
            else
            {
                break; // valid input received
            }

        } while (returnedValue != 1); // repeat if true

        do
        {
            printf("How many would you like?: ");
            returnedValue = scanf("%d", &quantities[i]);

            clear_input_buffer();

            if (returnedValue != 1 || quantities[i] < 0)
            {
                printf("Invalid input. Please enter a valid number\n");
                returnedValue = 0;
            }
            else
            {
                break;
            }

        } while (returnedValue != 1);

        totals[i] = prices[i] * quantities[i]; // total amount
        grandTotal = grandTotal + totals[i];
    }

    // Display Summary
    printf("\n\033[1;32mPurchase Summary:\033[0m\n");

    for (int i = 0; i < itemCount; i++)
    {
        printf("%s x %d @ %c%.2f each = %c%.2f\n", items[i], quantities[i], currency, prices[i], currency, totals[i]);
    }

    printf("\n\033[1;33mGrand Total: %c%.2f\033[0m\n\n", currency, grandTotal);

    return 0;
}

// Function defination

void clear_input_buffer()
{
    // Clear invalid input from buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // txt --> i-1.0
}
