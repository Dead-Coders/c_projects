#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startGame();

int main() {
    int choice;

    do {
        printf("\n===============================\n");
        printf("      Guess the Number Game     \n");
        printf("===============================\n");
        printf("1. Start Game\n");
        printf("2. Exit\n");
        printf("===============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

void startGame() {
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;

    printf("I have selected a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != number);
}
