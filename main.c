#include <stdio.h>
#include <conio.h>
#include <string.h>

// Function to take hidden password (shows ****)
void getPassword(char pass[]) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();  // get character without showing on screen

        if (ch == 13) {  // Enter key
            pass[i] = '\0';
            break;
        } else if (ch == 8) {  // Backspace
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pass[i++] = ch;
            printf("*");
        }
    }
}

// Function to read the old password from file
int readOldPassword(char oldPass[]) {
    FILE *fp = fopen("password.txt", "r");

    if (fp == NULL) {
        return 0;  // file not found -> no password saved yet
    }

    fscanf(fp, "%s", oldPass);
    fclose(fp);
    return 1;  // successfully read
}

// Function to save the new password into the file
void saveNewPassword(char newPass[]) {
    FILE *fp = fopen("password.txt", "w");

    fprintf(fp, "%s", newPass);
    fclose(fp);
}

int main() {
    char storedPass[50];
    char oldPassInput[50];
    char newPass[50];

    int fileExists = readOldPassword(storedPass);

    if (!fileExists) {
        printf("No password found. Setting up first password.\n");
        printf("Create new password: ");
        getPassword(newPass);

        saveNewPassword(newPass);

        printf("\nPassword created successfully!\n");
        return 0;
    }

    // Ask user for old password
    printf("Enter old password: ");
    getPassword(oldPassInput);

    // Compare old password
    if (strcmp(storedPass, oldPassInput) != 0) {
        printf("\nIncorrect old password. Password change failed.\n");
        return 0;
    }

    // Ask for new password
    printf("\nEnter new password: ");
    getPassword(newPass);

    // Save new password
    saveNewPassword(newPass);

    printf("\nPassword changed successfully!\n");

    return 0;
}

