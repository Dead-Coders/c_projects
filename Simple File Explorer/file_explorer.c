#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Function to list files and directories in the given path
void listFiles(const char *path) {
    struct dirent *de;  // Pointer for directory entry

    // Open the directory specified by the path
    DIR *dr = opendir(path);

    if (dr == NULL) {  // Check if the directory could be opened
        printf("Could not open directory %s\n", path);
        return;
    }

    printf("\nContents of %s:\n", path);
    printf("----------------------------\n");
    // Read and print all files and directories within the directory
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    // Close the directory
    closedir(dr);
}

int main() {
    int choice;
    char path[256];
    char filename[100];

    while (1) {
        // Display the menu
        printf("\n===================================\n");
        printf("|       SIMPLE FILE EXPLORER      |\n");
        printf("===================================\n");
        printf("| 1. View files                   |\n");
        printf("| 2. Change directory             |\n");
        printf("| 3. Create file                  |\n");
        printf("| 4. Delete file                  |\n");
        printf("| 5. Exit                         |\n");
        printf("===================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the choice

        switch (choice) {
            case 1:
                // List files and directories in the given path
                printf("\nEnter the directory path: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0; // Remove the newline character
                listFiles(path);
                break;

            case 2:
                // Change the current working directory
                printf("\nEnter the path to change directory: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0; // Remove the newline character
                if (chdir(path) == 0) {
                    printf("Changed to directory %s\n", path);
                } else {
                    printf("Could not change directory to %s\n", path);
                }
                break;

            case 3:
                // Create a new file
                printf("\nEnter the name of the file to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the newline character
                FILE *fp = fopen(filename, "w");
                if (fp) {
                    printf("File created successfully\n");
                    fclose(fp);
                } else {
                    printf("Could not create the file %s\n", filename);
                }
                break;

            case 4:
                // Delete an existing file
                printf("\nEnter the name of the file to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove the newline character
                if (remove(filename) == 0) {
                    printf("File deleted successfully\n");
                } else {
                    printf("Could not delete the file %s\n", filename);
                }
                break;

            case 5:
                // Exit the program
                printf("\nExiting the File Explorer. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}