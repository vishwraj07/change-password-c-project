#include <stdio.h>
#include <string.h>
#include <conio.h>

// Function to take hidden password input
void getHiddenPassword(char password[]) {
    int i = 0;
    char ch;

    while (1) {
        ch = getch();  // get character without showing

        if (ch == 13) {  // Enter key
            password[i] = '\0';
            printf("\n");
            break;
        }
        else if (ch == 8 && i > 0) {  // Backspace
            i--;
            printf("\b \b");
        }
        else {
            password[i++] = ch;
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
