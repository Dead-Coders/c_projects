#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100

typedef struct {
    char licensePlate[15];
    char ownerName[30];
    int parkingSlot;
} Car;

typedef struct {
    int slotNumber;
    int isOccupied;
} ParkingSlot;

Car cars[MAX_CARS];
ParkingSlot slots[MAX_CARS];
int carCount = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMenu() {
    clearScreen();
    printf("\033[1;36m"); // Cyan color
    printf("****************************************\n");
    printf("*     PARKING MANAGEMENT SYSTEM         *\n");
    printf("****************************************\n");
    printf("* 1. Add Car                            *\n");
    printf("* 2. Remove Car                         *\n");
    printf("* 3. View Cars                          *\n");
    printf("* 4. Exit                               *\n");
    printf("****************************************\n");
    printf("\033[0m"); // Reset color
    printf("Choose an option: ");
}

void addCar() {
    if (carCount >= MAX_CARS) {
        printf("\n\033[1;31mParking full!\033[0m\n");
        return;
    }

    Car newCar;
    printf("\nEnter license plate: ");
    scanf("%s", newCar.licensePlate);
    printf("Enter owner name: ");
    scanf("%s", newCar.ownerName);

    for (int i = 0; i < MAX_CARS; i++) {
        if (slots[i].isOccupied == 0) {
            newCar.parkingSlot = i;
            slots[i].isOccupied = 1;
            cars[carCount++] = newCar;
            printf("\n\033[1;32mCar added to slot %d.\033[0m\n", i);
            return;
        }
    }
}

void removeCar() {
    char licensePlate[15];
    printf("\nEnter license plate of car to remove: ");
    scanf("%s", licensePlate);

    for (int i = 0; i < carCount; i++) {
        if (strcmp(cars[i].licensePlate, licensePlate) == 0) {
            slots[cars[i].parkingSlot].isOccupied = 0;
            for (int j = i; j < carCount - 1; j++) {
                cars[j] = cars[j + 1];
            }
            carCount--;
            printf("\n\033[1;32mCar removed.\033[0m\n");
            return;
        }
    }
    printf("\n\033[1;31mCar not found.\033[0m\n");
}

void viewCars() {
    printf("\n\033[1;34m=== PARKED CARS ===\033[0m\n");
    if (carCount == 0) {
        printf("\n\033[1;33mNo cars parked.\033[0m\n");
        printf("\nPress Enter to return to the menu...");
        getchar(); // To consume newline character
        getchar(); // To wait for user input
        return;
    }

    for (int i = 0; i < carCount; i++) {
        printf("License Plate: \033[1;33m%s\033[0m, Owner: \033[1;33m%s\033[0m, Slot: \033[1;33m%d\033[0m\n",
               cars[i].licensePlate, cars[i].ownerName, cars[i].parkingSlot);
    }
    printf("\n\033[1;34m====================\033[0m\n");
    printf("\nPress Enter to return to the menu...");
    getchar(); // To consume newline character
    getchar(); // To wait for user input

    clearScreen(); // Clear screen after user presses Enter
}

int main() {
    int choice;

    for (int i = 0; i < MAX_CARS; i++) {
        slots[i].slotNumber = i;
        slots[i].isOccupied = 0;
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                removeCar();
                break;
            case 3:
                viewCars();
                break;
            case 4:
                printf("\n\033[1;31mExiting...\033[0m\n");
                exit(0);
                break;
            default:
                printf("\n\033[1;31mInvalid option. Try again.\033[0m\n");
                printf("Press Enter to continue...");
                getchar(); // To consume newline character
                getchar(); // To wait for user input
        }
    }

    return 0;
}
