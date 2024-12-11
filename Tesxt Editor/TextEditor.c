#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 256
#define MAX_TEXT_SIZE 10000

int main() {
    char file_name[MAX_FILE_NAME];
    char text[MAX_TEXT_SIZE];
    char ch;
    FILE *file;

    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    // Open the file for reading
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found. Creating a new file.\n");
        
        // Create the file for writing if it doesn't exist
        file = fopen(file_name, "w");
        if (file == NULL) {
            printf("Error creating the file.\n");
            return 1;
        }
        
        fclose(file);
        
        // Re-open the file for reading and writing
        file = fopen(file_name, "r+");
    }

    // Read and display the content of the file
    printf("File content:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Clear the input buffer
    fseek(file, 0, SEEK_END);

    printf("\nEnter new content (Press Ctrl+D to save and exit):\n");

    // Read and write text until Ctrl+D is pressed
    while (fgets(text, sizeof(text), stdin) != NULL) {
        fputs(text, file);
    }

    printf("File saved and editor closed.\n");

    fclose(file);

    return 0;
}
