#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep function
#include <stdbool.h>

int redDuration = 3;
int yellowDuration = 2;
int greenDuration = 3;
bool isPaused = false;

void displayMenu() {
    printf("\n");
    printf("=====================================\n");
    printf("       Traffic Light Simulation       \n");
    printf("=====================================\n");
    printf("1. Start Simulation\n");
    printf("2. Adjust Timers\n");
    printf("3. Pause/Resume Simulation\n");
    printf("4. Exit\n");
    printf("Please choose an option: ");
}

void displayLight(int light) {
    printf("\n");
    printf("Traffic Light State:\n");
    printf("      _______\n");
    printf("     |       |\n");
    printf("     |  %s  |\n", (light == 1) ? " RED " : "   ");
    printf("     |_______|\n");
    printf("     |       |\n");
    printf("     |  %s  |\n", (light == 2) ? " YLW " : "   ");
    printf("     |_______|\n");
    printf("     |       |\n");
    printf("     |  %s  |\n", (light == 3) ? " GRN " : "   ");
    printf("     |_______|\n");
}

void adjustTimers() {
    printf("\nAdjust Timer Durations:\n");
    printf("Enter duration for Red Light (default 3 seconds): ");
    scanf("%d", &redDuration);
    printf("Enter duration for Yellow Light (default 2 seconds): ");
    scanf("%d", &yellowDuration);
    printf("Enter duration for Green Light (default 3 seconds): ");
    scanf("%d", &greenDuration);
}

void startSimulation() {
    int choice;
    while (1) {
        printf("\nTraffic Light Simulation Menu:\n");
        printf("1. Red Light\n");
        printf("2. Yellow Light\n");
        printf("3. Green Light\n");
        printf("4. Exit Simulation\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (isPaused) {
            printf("Simulation is paused. Please resume to continue.\n");
            continue;
        }

        switch (choice) {
            case 1:
                displayLight(1);
                printf("Red Light - Stop\n");
                sleep(redDuration); // Light duration
                break;
            case 2:
                displayLight(2);
                printf("Yellow Light - Prepare to Stop\n");
                sleep(yellowDuration); // Light duration
                break;
            case 3:
                displayLight(3);
                printf("Green Light - Go\n");
                sleep(greenDuration); // Light duration
                break;
            case 4:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    int option;
    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                startSimulation();
                break;
            case 2:
                adjustTimers();
                break;
            case 3:
                isPaused = !isPaused;
                printf(isPaused ? "Simulation paused.\n" : "Simulation resumed.\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}
