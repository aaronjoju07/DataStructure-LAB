#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a customer
typedef struct Customer {
    char name[50];
    int roomNumber;
    struct Customer* next;
} Customer;

// Define a structure for the queue
typedef struct {
    Customer* front;
    Customer* rear;
} HotelQueue;

// Function to initialize an empty queue
void initializeQueue(HotelQueue* queue) {
    queue->front = queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(HotelQueue* queue) {
    return queue->front == NULL;
}

// Function to add a customer to the queue
void enqueue(HotelQueue* queue, char name[], int roomNumber) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    if (!newCustomer) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newCustomer->name, name);
    newCustomer->roomNumber = roomNumber;
    newCustomer->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newCustomer;
    } else {
        queue->rear->next = newCustomer;
        queue->rear = newCustomer;
    }

    printf("Customer %s added to room %d\n", name, roomNumber);
}

// Function to remove a customer from the queue (check-out)
void dequeue(HotelQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, no customers to check out\n");
        return;
    }

    Customer* removedCustomer = queue->front;
    queue->front = queue->front->next;

    printf("Customer %s checked out from room %d\n", removedCustomer->name, removedCustomer->roomNumber);

    free(removedCustomer);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

// Function to display the current queue (list of customers)
void displayQueue(HotelQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    Customer* currentCustomer = queue->front;

    printf("Current Queue:\n");

    while (currentCustomer != NULL) {
        printf("Room %d: %s\n", currentCustomer->roomNumber, currentCustomer->name);
        currentCustomer = currentCustomer->next;
    }
}

// Function to free memory and clear the queue
void clearQueue(HotelQueue* queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int main() {
    HotelQueue hotelQueue;
    initializeQueue(&hotelQueue);

    enqueue(&hotelQueue, "John Doe", 101);
    enqueue(&hotelQueue, "Jane Smith", 202);
    enqueue(&hotelQueue, "Bob Johnson", 303);

    displayQueue(&hotelQueue);

    dequeue(&hotelQueue);
    displayQueue(&hotelQueue);

    clearQueue(&hotelQueue);

    return 0;
}
