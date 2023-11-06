#include <stdio.h>

// Function to read and display a string
void readString(char *str) {
    printf("Enter a string: ");
    scanf("%s", str);
    printf("The entered string is: %s\n", str);
}

// Function to calculate the string length
int stringLength(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Function to reverse the string
void reverseString(char *str) {
    char *start = str;
    char *end = str + stringLength(str) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    printf("The reversed string is: %s\n", str);
}

// Function to copy one string into another
void copyString(char *str1, char *str2) {
    while (*str1 != '\0') {
        *str2 = *str1;
        str1++;
        str2++;
    }
    *str2 = '\0';
    printf("The copied string is: %s\n", str2);
}

// Function to check whether a given character is present or not and count the number of times it is repeated
void countChar(char *str, char ch) {
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    if (count > 0) {
        printf("The character %c is present %d times in the string.\n", ch, count);
    } else {
        printf("The character %c is not present in the string.\n", ch);
    }
}

int main() {
    char str1[100], str2[100], ch;
    int choice;
    do {
        printf("\n1. Read and display a string\n");
        printf("2. Calculate the string length\n");
        printf("3. Reverse the string\n");
        printf("4. Copy one string into another\n");
        printf("5. Read a string and check whether a given character is present or not\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readString(str1);
                break;
            case 2:
                printf("The length of the string is: %d\n", stringLength(str1));
                break;
            case 3:
                reverseString(str1);
                break;
            case 4:
                copyString(str1, str2);
                break;
            case 5:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("Enter a character to search: ");
                scanf(" %c", &ch);
                countChar(str1, ch);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}