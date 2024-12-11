#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void showMenu();
void checkBalance();
void depositMoney();
void withdrawMoney();
void exitATM();

float balance = 1000.0; // Initial balance

int main() {
    int choice;

    do {
        system("cls"); // Clear screen for a fresh menu display
        showMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                exitATM();
                break;
            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }

        printf("\nPress any key to return to the menu...\n");
        getchar(); getchar(); // Wait for user input before returning to the menu
    } while (choice != 4);

    return 0;
}

void showMenu() {
    printf("=====================================\n");
    printf("|          ATM Simulator            |\n");
    printf("=====================================\n");
    printf("| 1. Check Balance                  |\n");
    printf("| 2. Deposit Money                  |\n");
    printf("| 3. Withdraw Money                 |\n");
    printf("| 4. Exit                           |\n");
    printf("=====================================\n");
}

void checkBalance() {
    printf("\nYour current balance is: $%.2f\n", balance);
}

void depositMoney() {
    float amount;
    printf("\nEnter the amount to deposit: $");
    scanf("%f", &amount);
    if (amount > 0) {
        balance += amount;
        printf("You've successfully deposited $%.2f\n", amount);
    } else {
        printf("Invalid amount entered. Please try again.\n");
    }
}

void withdrawMoney() {
    float amount;
    printf("\nEnter the amount to withdraw: $");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("You've successfully withdrawn $%.2f\n", amount);
    } else {
        printf("Invalid transaction. Please try again.\n");
    }
}

void exitATM() {
    printf("\nThank you for using our ATM simulator. Goodbye!\n");
}

