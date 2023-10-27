#include <stdio.h>
#include <string.h>

// Structure to store a name
struct Name {
    char first[50];
    char last[50];
};

// Function to read and display n names
void readNames(struct Name *names, int n) {
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter first name for name %d: ", i + 1);
        scanf("%s", names[i].first);
        printf("Enter last name for name %d: ", i + 1);
        scanf("%s", names[i].last);
    }
    printf("The entered names are:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", names[i].first, names[i].last);
    }
}

// Function to swap two names
void swapNames(struct Name *name1, struct Name *name2) {
    struct Name temp = *name1;
    *name1 = *name2;
    *name2 = temp;
}

// Function to implement bubble sort for n names
void bubbleSortNames(struct Name *names, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j].last, names[j + 1].last) > 0) {
                swapNames(&names[j], &names[j + 1]);
            }
        }
    }
    printf("The sorted names are:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", names[i].first, names[i].last);
    }
}

int main() {
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    struct Name names[n];
    readNames(names, n);
    bubbleSortNames(names, n);
    return 0;
}