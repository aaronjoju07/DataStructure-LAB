#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Hotel {
    int id;
    char name[50];
    int rating;
};


void swap(struct Hotel *a, struct Hotel *b) {
    struct Hotel temp = *a;
    *a = *b;
    *b = temp;
}


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


void quickSort(struct Hotel hotels[], int low, int high, int *comparisons, int *dataTransfers) {
    if (low < high) {
        int pi = partition(hotels, low, high, comparisons, dataTransfers);

        quickSort(hotels, low, pi - 1, comparisons, dataTransfers);
        quickSort(hotels, pi + 1, high, comparisons, dataTransfers);
    }
}


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

    const int n = 5;


    struct Hotel hotels[n];
    for (int i = 0; i < n; i++) {
        hotels[i].id = rand() % 1000 + 1;
        sprintf(hotels[i].name, "Hotel%d", i + 1);
        hotels[i].rating = rand() % 5 + 1;
    }


    writeToFile(hotels, n, "hotels.txt");


    readFromFile(hotels, n, "hotels.txt");


    printf("Original Hotels:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }


    int quickComparisons = 0, quickDataTransfers = 0;
    quickSort(hotels, 0, n - 1, &quickComparisons, &quickDataTransfers);


    printf("\nHotels after Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }


    readFromFile(hotels, n, "hotels.txt");


    int bubbleComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(hotels, n, &bubbleComparisons, &bubbleDataTransfers);


    printf("\nHotels after Bubble Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }


    printf("\nQuick Sort Comparisons: %d, Data Transfers: %d\n", quickComparisons, quickDataTransfers);
    printf("Bubble Sort Comparisons: %d, Data Transfers: %d\n", bubbleComparisons, bubbleDataTransfers);

    return 0;
}
