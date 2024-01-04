#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent hotel information
struct Hotel {
    int id;
    char name[50];
    int rating;
};

// Function to swap two hotels
void swap(struct Hotel *a, struct Hotel *b) {
    struct Hotel temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for Quick Sort
int partition(struct Hotel hotels[], int low, int high, int *comparisons, int *dataTransfers) {
    int pivot = hotels[high].id;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (hotels[j].id < pivot) {
            i++;
            swap(&hotels[i], &hotels[j]);
            (*dataTransfers)++;
        }
    }
    swap(&hotels[i + 1], &hotels[high]);
    (*dataTransfers)++;
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(struct Hotel hotels[], int low, int high, int *comparisons, int *dataTransfers) {
    if (low < high) {
        int pi = partition(hotels, low, high, comparisons, dataTransfers);

        quickSort(hotels, low, pi - 1, comparisons, dataTransfers);
        quickSort(hotels, pi + 1, high, comparisons, dataTransfers);
    }
}

// Function to perform Bubble Sort and count comparisons and data transfers
void bubbleSort(struct Hotel hotels[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (hotels[j].id > hotels[j + 1].id) {
                // Swap if the element is greater than the next element
                swap(&hotels[j], &hotels[j + 1]);
                (*dataTransfers)++;
            }
        }
    }
}

// Function to write hotel data to a file
void writeToFile(struct Hotel hotels[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fprintf(file, "%d %s %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

// Function to read hotel data from a file
void readFromFile(struct Hotel hotels[], int n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            fscanf(file, "%d %s %d", &hotels[i].id, hotels[i].name, &hotels[i].rating);
        }
        fclose(file);
    } else {
        printf("Error opening file for reading.\n");
    }
}

int main() {
    // Number of hotels
    const int n = 5;

    // Generate random hotel data
    struct Hotel hotels[n];
    for (int i = 0; i < n; i++) {
        hotels[i].id = rand() % 1000 + 1;
        sprintf(hotels[i].name, "Hotel%d", i + 1);
        hotels[i].rating = rand() % 5 + 1;
    }

    // Save data to a file
    writeToFile(hotels, n, "hotels.txt");

    // Read data from the file
    readFromFile(hotels, n, "hotels.txt");

    // Display original hotel data
    printf("Original Hotels:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }

    // Quick Sort
    int quickComparisons = 0, quickDataTransfers = 0;
    quickSort(hotels, 0, n - 1, &quickComparisons, &quickDataTransfers);

    // Display sorted hotel data after Quick Sort
    printf("\nHotels after Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }

    // Read data from the file again
    readFromFile(hotels, n, "hotels.txt");

    // Bubble Sort
    int bubbleComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(hotels, n, &bubbleComparisons, &bubbleDataTransfers);

    // Display sorted hotel data after Bubble Sort
    printf("\nHotels after Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }

    // Display comparison and data transfer results
    printf("\nQuick Sort Comparisons: %d, Data Transfers: %d\n", quickComparisons, quickDataTransfers);
    printf("Bubble Sort Comparisons: %d, Data Transfers: %d\n", bubbleComparisons, bubbleDataTransfers);

    return 0;
}
