#include <stdio.h>
#include <string.h>

// Structure to represent hotel information
struct Hotel {
    int id;
    char name[50];
    int rating;
};

// Function to perform linear search
int linearSearch(struct Hotel hotels[], int n, int key, int *elementComparisons, int *indexComparisons) {
    for (int i = 0; i < n; i++) {
        (*elementComparisons)++;
        if (hotels[i].id == key) {
            (*indexComparisons)++;
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform sentinel search
int sentinelSearch(struct Hotel hotels[], int n, int key, int *elementComparisons, int *indexComparisons) {
    // Add a sentinel at the end of the array
    hotels[n].id = key;

    int i = 0;
    while (hotels[i].id != key) {
        (*elementComparisons)++;
        i++;
    }

    (*indexComparisons)++; // Count the last comparison
    if (i < n) {
        return i; // Return the index if found
    } else {
        return -1; // Return -1 if not found
    }
}

// Function to perform binary search
int binarySearch(struct Hotel hotels[], int left, int right, int key, int *elementComparisons, int *indexComparisons) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*elementComparisons)++;
        if (hotels[mid].id == key) {
            (*indexComparisons)++;
            return mid; // Return the index if found
        } else if (hotels[mid].id < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

// Function to perform bubble sort and count comparisons and data transfers
void bubbleSort(struct Hotel hotels[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (hotels[j].id > hotels[j + 1].id) {
                // Swap if the element is greater than the next element
                struct Hotel temp = hotels[j];
                hotels[j] = hotels[j + 1];
                hotels[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}

// Function to perform insertion sort and count comparisons and data transfers
void insertionSort(struct Hotel hotels[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 1; i < n; i++) {
        struct Hotel key = hotels[i];
        int j = i - 1;

        while (j >= 0 && hotels[j].id > key.id) {
            (*comparisons)++;
            hotels[j + 1] = hotels[j];
            (*dataTransfers)++;
            j--;
        }

        hotels[j + 1] = key;
    }
}

int main() {
    // Sample hotel data
    struct Hotel hotels[] = {
        {101, "Hotel A", 4},
        {203, "Hotel B", 3},
        {155, "Hotel C", 5},
        {402, "Hotel D", 2},
        {301, "Hotel E", 4},
    };

    int n = sizeof(hotels) / sizeof(hotels[0]);
    int key = 155;

    int linearIndex = -1, sentinelIndex = -1, binaryIndex = -1;
    int linearElementComparisons = 0, sentinelElementComparisons = 0, binaryElementComparisons = 0;
    int linearIndexComparisons = 0, sentinelIndexComparisons = 0, binaryIndexComparisons = 0;

    // Linear Search
    linearIndex = linearSearch(hotels, n, key, &linearElementComparisons, &linearIndexComparisons);

    // Sentinel Search
    sentinelIndex = sentinelSearch(hotels, n, key, &sentinelElementComparisons, &sentinelIndexComparisons);

    // Sort the array before Binary Search
    int bubbleComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(hotels, n, &bubbleComparisons, &bubbleDataTransfers);

    // Print sorted array after Bubble Sort
    printf("Sorted Hotels (Bubble Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }

    int insertionComparisons = 0, insertionDataTransfers = 0;
    insertionSort(hotels, n, &insertionComparisons, &insertionDataTransfers);

    // Print sorted array after Insertion Sort
    printf("\nSorted Hotels (Insertion Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }

    // Binary Search
    binaryIndex = binarySearch(hotels, 0, n - 1, key, &binaryElementComparisons, &binaryIndexComparisons);

    // Display results
    printf("\nResults:\n");
    printf("Linear Search - Index: %d, Element Comparisons: %d, Index Comparisons: %d\n", linearIndex, linearElementComparisons, linearIndexComparisons);
    printf("Sentinel Search - Index: %d, Element Comparisons: %d, Index Comparisons: %d\n", sentinelIndex, sentinelElementComparisons, sentinelIndexComparisons);
    printf("Binary Search - Index: %d, Element Comparisons: %d, Index Comparisons: %d\n", binaryIndex, binaryElementComparisons, binaryIndexComparisons);

    printf("\nBubble Sort - Comparisons: %d, Data Transfers: %d\n", bubbleComparisons, bubbleDataTransfers);
    printf("Insertion Sort - Comparisons: %d, Data Transfers: %d\n", insertionComparisons, insertionDataTransfers);

    return 0;
}
