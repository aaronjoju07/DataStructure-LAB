#include <stdio.h>
#include <stdlib.h>

int main() {
    int n; // Number of elements
    int* numbers; // Pointer to the dynamically allocated array
    int sum = 0; // Variable to store the sum

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array of numbers
    numbers = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the numbers
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Calculate the sum
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }

    // Output the sum
    printf("Sum of the numbers: %d\n", sum);

    // Free the allocated memory
    free(numbers);

    return 0;
}
