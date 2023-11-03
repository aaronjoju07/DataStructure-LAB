#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROPERTIES 100
#define NUM_ATTRIBUTES 5

struct RentalProperty {
    int propertyId;
    char address[100];
    int rent;
    int bedrooms;
    int bathrooms;
};

struct RentalProperty properties[MAX_PROPERTIES]; 
int propertyCount = 0;


void insertProperty(int propertyId, char address[], int rent, int bedrooms, int bathrooms) {
    if (propertyCount < MAX_PROPERTIES) {
        properties[propertyCount].propertyId = propertyId;
        strncpy(properties[propertyCount].address, address, sizeof(properties[propertyCount].address));
        properties[propertyCount].rent = rent;
        properties[propertyCount].bedrooms = bedrooms;
        properties[propertyCount].bathrooms = bathrooms;
        propertyCount++;
        printf("Property added successfully.\n");
    } else {
        printf("Maximum property limit reached.\n");
    }
}


void deleteProperty(int propertyId) {
    int found = 0;
    for (int i = 0; i < propertyCount; i++) {
        if (properties[i].propertyId == propertyId) {
            for (int j = i; j < propertyCount - 1; j++) {
                properties[j] = properties[j + 1];
            }
            propertyCount--;
            found = 1;
            printf("Property with ID %d deleted successfully.\n", propertyId);
            break;
        }
    }
    if (!found) {
        printf("Property with ID %d not found.\n", propertyId);
    }
}


void searchProperty(int propertyId) {
    int found = 0;
    for (int i = 0; i < propertyCount; i++) {
        if (properties[i].propertyId == propertyId) {
            found = 1;
            printf("Property found with details:\n");
            printf("Property ID: %d\n", properties[i].propertyId);
            printf("Address: %s\n", properties[i].address);
            printf("Rent: %d\n", properties[i].rent);
            printf("Bedrooms: %d\n", properties[i].bedrooms);
            printf("Bathrooms: %d\n", properties[i].bathrooms);
            break;
        }
    }
    if (!found) {
        printf("Property with ID %d not found.\n", propertyId);
    }
}

int main() {
    int choice, propertyId, rent, bedrooms, bathrooms;
    char address[100];

    while (1) {
        printf("1. Insert Property\n");
        printf("2. Delete Property\n");
        printf("3. Search Property\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Property ID: ");
                scanf("%d", &propertyId);
                printf("Enter Address: ");
                scanf("%s", address);
                printf("Enter Rent: ");
                scanf("%d", &rent);
                printf("Enter Bedrooms: ");
                scanf("%d", &bedrooms);
                printf("Enter Bathrooms: ");
                scanf("%d", &bathrooms);
                insertProperty(propertyId, address, rent, bedrooms, bathrooms);
                break;
            case 2:
                printf("Enter Property ID to delete: ");
                scanf("%d", &propertyId);
                deleteProperty(propertyId);
                break;
            case 3:
                printf("Enter Property ID to search: ");
                scanf("%d", &propertyId);
                searchProperty(propertyId);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
