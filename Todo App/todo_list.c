#include <stdio.h>
#include <string.h>
#include <windows.h>  // Include Windows API for color

#define MAX_TASKS 100
#define MAX_LENGTH 100

// Color codes for Windows CMD
#define RESET   15
#define BLUE    9
#define GREEN   10
#define RED     12
#define YELLOW  14
#define BOLD    8

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void addTask(char tasks[][MAX_LENGTH], int *taskCount);
void viewTasks(char tasks[][MAX_LENGTH], int *completed, int taskCount);
void completeTask(int *completed, int taskCount);
void deleteTask(char tasks[][MAX_LENGTH], int *completed, int *taskCount);
void printHeader();

int main() {
    char tasks[MAX_TASKS][MAX_LENGTH];
    int completed[MAX_TASKS] = {0};
    int taskCount = 0;
    int choice;

    do {
        printHeader();
        setColor(BLUE);
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        setColor(YELLOW);
        printf("Choose an option: ");
        setColor(RESET);
        scanf("%d", &choice);
        getchar(); // Clear the input buffer

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                viewTasks(tasks, completed, taskCount);
                break;
            case 3:
                completeTask(completed, taskCount);
                break;
            case 4:
                deleteTask(tasks, completed, &taskCount);
                break;
            case 5:
                setColor(GREEN);
                printf("Exiting the program.\n");
                setColor(RESET);
                break;
            default:
                setColor(RED);
                printf("Invalid choice! Please try again.\n");
                setColor(RESET);
        }
    } while (choice != 5);

    return 0;
}

void printHeader() {
    setColor(BLUE);
    printf("\n***************************************\n");
    printf("*        Stylish To-Do List Menu       *\n");
    printf("***************************************\n");
    setColor(RESET);
}

void addTask(char tasks[][MAX_LENGTH], int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        setColor(RED);
        printf("Task list is full!\n");
        setColor(RESET);
        return;
    }
    setColor(YELLOW);
    printf("Enter the task: ");
    setColor(RESET);
    fgets(tasks[*taskCount], MAX_LENGTH, stdin);
    tasks[*taskCount][strcspn(tasks[*taskCount], "\n")] = '\0'; // Remove newline character
    (*taskCount)++;
    setColor(GREEN);
    printf("Task added successfully.\n");
    setColor(RESET);
}

void viewTasks(char tasks[][MAX_LENGTH], int *completed, int taskCount) {
    if (taskCount == 0) {
        setColor(RED);
        printf("No tasks to display.\n");
        setColor(RESET);
        return;
    }
    setColor(BLUE);
    printf("\nTo-Do List:\n");
    setColor(RESET);
    for (int i = 0; i < taskCount; i++) {
        setColor(GREEN);
        printf("%d. %s [%s]\n", i + 1, tasks[i], completed[i] ? "Completed" : "Not Completed");
        setColor(RESET);
    }
}

void completeTask(int *completed, int taskCount) {
    int taskNumber;
    setColor(YELLOW);
    printf("Enter the task number to mark as completed: ");
    setColor(RESET);
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > taskCount) {
        setColor(RED);
        printf("Invalid task number!\n");
        setColor(RESET);
        return;
    }
    completed[taskNumber - 1] = 1;
    setColor(GREEN);
    printf("Task marked as completed.\n");
    setColor(RESET);
}

void deleteTask(char tasks[][MAX_LENGTH], int *completed, int *taskCount) {
    int taskNumber;
    setColor(YELLOW);
    printf("Enter the task number to delete: ");
    setColor(RESET);
    scanf("%d", &taskNumber);

    if (taskNumber < 1 || taskNumber > *taskCount) {
        setColor(RED);
        printf("Invalid task number!\n");
        setColor(RESET);
        return;
    }

    for (int i = taskNumber - 1; i < *taskCount - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
        completed[i] = completed[i + 1];
    }
    (*taskCount)--;
    setColor(GREEN);
    printf("Task deleted successfully.\n");
    setColor(RESET);
}