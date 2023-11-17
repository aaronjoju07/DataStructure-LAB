#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for a hotel room
struct HotelRoom {
    int roomNumber;
    char guestName[50];
    struct HotelRoom *next;
};

// display all hotel rooms
void displayRooms(struct HotelRoom *head) {
    struct HotelRoom *current = head;

    while (current != NULL) {
        printf("Room %d: %s\n", current->roomNumber, current->guestName);
        current = current->next;
    }
}

// add a new room to the hotel
struct HotelRoom *addRoom(struct HotelRoom *head, int roomNumber, const char *guestName) {
    struct HotelRoom *newRoom = (struct HotelRoom *)malloc(sizeof(struct HotelRoom));
    if (newRoom == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newRoom->roomNumber = roomNumber;
    strncpy(newRoom->guestName, guestName, sizeof(newRoom->guestName) - 1);
    newRoom->guestName[sizeof(newRoom->guestName) - 1] = '\0';  // Ensure null-termination
    newRoom->next = head;  // Add the new room at the beginning of the list

    return newRoom;
}

// remove a room from the hotel
struct HotelRoom *removeRoom(struct HotelRoom *head, int roomNumber) {
    struct HotelRoom *current = head;
    struct HotelRoom *prev = NULL;

    // Find room to be removed
    while (current != NULL && current->roomNumber != roomNumber) {
        prev = current;
        current = current->next;
    }

    // If room found, remove it
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            head = current->next;
        }
        free(current);
        printf("Room %d removed\n", roomNumber);
    } else {
        printf("Room %d not found\n", roomNumber);
    }

    return head;
}

//free all allocated memory
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

    // Add some rooms
    head = addRoom(head, 101, "John Doe");
    head = addRoom(head, 102, "Jane Smith");
    head = addRoom(head, 103, "Bob Johnson");

    // Display all rooms
    displayRooms(head);

    // Remove a room
    head = removeRoom(head, 102);

    // Display rooms after removal
    displayRooms(head);

    // Free allocated memory
    freeMemory(head);

    return 0;
}
