#include <stdio.h>
#include <string.h>


struct Hotel {
    int id;
    char name[50];
    int rating;
};


int linearSearch(struct Hotel hotels[], int n, int key, int *elementComparisons, int *indexComparisons) {
    for (int i = 0; i < n; i++) {
        (*elementComparisons)++;
        if (hotels[i].id == key) {
            (*indexComparisons)++;
            return i; 
        }
    }
    return -1; 
}


int sentinelSearch(struct Hotel hotels[], int n, int key, int *elementComparisons, int *indexComparisons) {

    hotels[n].id = key;

    int i = 0;
    while (hotels[i].id != key) {
        (*elementComparisons)++;
        i++;
    }

    (*indexComparisons)++; 
    if (i < n) {
        return i; 
    } else {
        return -1; 
    }
}


int binarySearch(struct Hotel hotels[], int left, int right, int key, int *elementComparisons, int *indexComparisons) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*elementComparisons)++;
        if (hotels[mid].id == key) {
            (*indexComparisons)++;
            return mid; 
        } else if (hotels[mid].id < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}


void bubbleSort(struct Hotel hotels[], int n, int *comparisons, int *dataTransfers) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (hotels[j].id > hotels[j + 1].id) {
                // Swap 
                struct Hotel temp = hotels[j];
                hotels[j] = hotels[j + 1];
                hotels[j + 1] = temp;
                (*dataTransfers)++;
            }
        }
    }
}


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

    struct Hotel hotels[100];  
    int n;

    printf("Enter the number of hotels: ");
    scanf("%d", &n);

    printf("Enter hotel details (ID, Name, Rating) for each hotel:\n");
    for (int i = 0; i < n; i++) {
        printf("Hotel %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &hotels[i].id);
        printf("Name: ");
        scanf("%s", hotels[i].name);
        printf("Rating: ");
        scanf("%d", &hotels[i].rating);
    }

    printf("Enter the key for search: ");
    int key;
    scanf("%d", &key);

    int linearIndex = -1, sentinelIndex = -1, binaryIndex = -1;
    int linearElementComparisons = 0, sentinelElementComparisons = 0, binaryElementComparisons = 0;
    int linearIndexComparisons = 0, sentinelIndexComparisons = 0, binaryIndexComparisons = 0;


    linearIndex = linearSearch(hotels, n, key, &linearElementComparisons, &linearIndexComparisons);


    sentinelIndex = sentinelSearch(hotels, n, key, &sentinelElementComparisons, &sentinelIndexComparisons);


    int bubbleComparisons = 0, bubbleDataTransfers = 0;
    bubbleSort(hotels, n, &bubbleComparisons, &bubbleDataTransfers);


    printf("Sorted Hotels (Bubble Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }

    int insertionComparisons = 0, insertionDataTransfers = 0;
    insertionSort(hotels, n, &insertionComparisons, &insertionDataTransfers);


    printf("\nSorted Hotels (Insertion Sort):\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Rating: %d\n", hotels[i].id, hotels[i].name, hotels[i].rating);
    }


    binaryIndex = binarySearch(hotels, 0, n - 1, key, &binaryElementComparisons, &binaryIndexComparisons);

    // Display 
    printf("\nResults:\n");
    printf("Linear Search - Index: %d, Element Comparisons: %d, Index Comparisons: %d\n", linearIndex, linearElementComparisons, linearIndexComparisons);
    printf("Sentinel Search - Index: %d, Element Comparisons: %d, Index Comparisons: %d\n", sentinelIndex, sentinelElementComparisons, sentinelIndexComparisons);
    printf("Binary Search - Index: %d, Element Comparisons: %d, Index Comparisons: %d\n", binaryIndex, binaryElementComparisons, binaryIndexComparisons);

    printf("\nBubble Sort - Comparisons: %d, Data Transfers: %d\n", bubbleComparisons, bubbleDataTransfers);
    printf("Insertion Sort - Comparisons: %d, Data Transfers: %d\n", insertionComparisons, insertionDataTransfers);

    return 0;
}
