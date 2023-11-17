#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a hotel room
struct HotelRoom {
    int roomNumber;
    char guestName[50];
    struct HotelRoom *next;
    struct HotelRoom *prev;
};

// Function to display all hotel rooms
void displayRooms(struct HotelRoom *head) {
    struct HotelRoom *current = head;

    while (current != NULL) {
        printf("Room %d: %s\n", current->roomNumber, current->guestName);
        current = current->next;
    }
}

// Function to display all hotel rooms in reverse order
void displayRoomsReverse(struct HotelRoom *tail) {
    struct HotelRoom *current = tail;

    while (current != NULL) {
        printf("Room %d: %s\n", current->roomNumber, current->guestName);
        current = current->prev;
    }
}

// Function to add a new room to the hotel
struct HotelRoom *addRoom(struct HotelRoom *head, struct HotelRoom *tail, int roomNumber, const char *guestName) {
    struct HotelRoom *newRoom = (struct HotelRoom *)malloc(sizeof(struct HotelRoom));
    if (newRoom == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newRoom->roomNumber = roomNumber;
    strncpy(newRoom->guestName, guestName, sizeof(newRoom->guestName) - 1);
    newRoom->guestName[sizeof(newRoom->guestName) - 1] = '\0';  // Ensure null-termination

    newRoom->next = head;
    newRoom->prev = NULL;

    if (head != NULL) {
        head->prev = newRoom;
    } else {
        tail = newRoom;  // If the list is empty, set the new room as the tail
    }

    return newRoom;
}

// Function to remove a room from the hotel
struct HotelRoom *removeRoom(struct HotelRoom *head, struct HotelRoom *tail, int roomNumber) {
    struct HotelRoom *current = head;

    // Find the room to be removed
    while (current != NULL && current->roomNumber != roomNumber) {
        current = current->next;
    }

    // If room found, remove it
    if (current != NULL) {
        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != NULL) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;  // If the removed node is the tail, update the tail
        }

        free(current);
        printf("Room %d removed\n", roomNumber);
    } else {
        printf("Room %d not found\n", roomNumber);
    }

    return head;
}

// Function to free all allocated memory
void freeMemory(struct HotelRoom *head) {
    struct HotelRoom *current = head;
    struct HotelRoom *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct HotelRoom *head = NULL;
    struct HotelRoom *tail = NULL;

    // Add some rooms
    tail = addRoom(head, tail, 101, "John Doe");
    tail = addRoom(head, tail, 102, "Jane Smith");
    tail = addRoom(head, tail, 103, "Bob Johnson");

    // Display all rooms
    displayRooms(head);

    // Remove a room
    head = removeRoom(head, tail, 102);

    // Display rooms after removal
    displayRooms(head);

    // Display rooms in reverse order
    displayRoomsReverse(tail);

    // Free allocated memory
    freeMemory(head);

    return 0;
}
