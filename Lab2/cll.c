#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a hotel room
struct HotelRoom {
    int roomNumber;
    char guestName[50];
    struct HotelRoom *next;
};

// Function to display all hotel rooms
void displayRooms(struct HotelRoom *head) {
    if (head == NULL) {
        printf("No rooms in the hotel.\n");
        return;
    }

    struct HotelRoom *current = head;
    do {
        printf("Room %d: %s\n", current->roomNumber, current->guestName);
        current = current->next;
    } while (current != head);
}

// Function to add a new room to the hotel
struct HotelRoom *addRoom(struct HotelRoom *head, int roomNumber, const char *guestName) {
    struct HotelRoom *newRoom = (struct HotelRoom *)malloc(sizeof(struct HotelRoom));
    if (newRoom == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    newRoom->roomNumber = roomNumber;
    strncpy(newRoom->guestName, guestName, sizeof(newRoom->guestName) - 1);
    newRoom->guestName[sizeof(newRoom->guestName) - 1] = '\0';  // Ensure null-termination

    if (head == NULL) {
        newRoom->next = newRoom;  // Point to itself if the list is empty
        return newRoom;
    }

    newRoom->next = head->next;  // Set the new room to point to the first room
    head->next = newRoom;        // Update the last room to point to the new room

    return head;
}

// Function to remove a room from the hotel
struct HotelRoom *removeRoom(struct HotelRoom *head, int roomNumber) {
    if (head == NULL) {
        printf("No rooms in the hotel.\n");
        return NULL;
    }

    struct HotelRoom *current = head;
    struct HotelRoom *prev = NULL;

    do {
        if (current->roomNumber == roomNumber) {
            if (prev != NULL) {
                prev->next = current->next;
                if (current == head) {
                    head = current->next; // Update head if removing the first room
                }
            } else {
                if (current->next == head) {
                    head = NULL; // If only one room is there, make the list empty
                } else {
                    prev = current->next; // Update the last room to point to the next room
                    while (prev->next != current) {
                        prev = prev->next;
                    }
                    prev->next = current->next;
                    head = current->next; // Update head if removing the first room
                }
            }
            free(current);
            printf("Room %d removed\n", roomNumber);
            return head;
        }

        prev = current;
        current = current->next;
    } while (current != head);

    printf("Room %d not found\n", roomNumber);
    return head;
}

// Function to free all allocated memory
void freeMemory(struct HotelRoom *head) {
    if (head == NULL) {
        return;
    }

    struct HotelRoom *current = head->next;
    struct HotelRoom *next;

    while (current != head) {
        next = current->next;
        free(current);
        current = next;
    }

    free(head);  // Free the head node
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
