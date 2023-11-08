#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

struct matrixStruct
{
    char hotel_name;
    int bookings[ROWS][COLS];
};

struct matrixStruct hotel;

void insertionDisplay();
int deleteElement(int row, int col);
void displayMatrix();
int linearSearch(int value);
int main()
{
    int choice, value, count = ROWS * COLS, row, col;
    int continueMenu = 1; // A flag to continue the menu loop

    while (continueMenu)
    {
        printf("----------------------Hotel_Management---------------------------\n");
        printf("Enter your Choice (1: Insert, 2: Delete 3: Display,4: Searching, 0: Exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the booking count received in the last %d days:\n", count);
            insertionDisplay();
            break;
        case 2:
            // Delete the matrix
            printf("Enter the Row and Column of the matrix : ");
            scanf("%d %d", &row, &col);
            deleteElement(row, col);
            break;
        case 3:
            displayMatrix();
            break;
        case 4:
            printf("Enter the value to be searched :");
            scanf("%d", &value);
            linearSearch(value);
            break;
        case 0:
            continueMenu = 0; // Exit the loop
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void displayMatrix()
{
    printf("----------------------3x3 Matrix of bookings---------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf(" ");
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", hotel.bookings[i][j]);
        }
        printf("\n");
    }
}
void insertionDisplay()
{
    // Insertion
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &hotel.bookings[i][j]);
        }
    }

    // Display
    printf("----------------------3x3 Matrix of bookings---------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf(" ");
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", hotel.bookings[i][j]);
        }
        printf("\n");
    }
}
// Delete
int deleteElement(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        hotel.bookings[row][col] = -1; // Mark the element as deleted
        return printf("Element deleted\n");
    }
    return printf("Element not found\n");
}

// Linear search
int linearSearch(int value)
{
    printf("----------------------------Searching----------------------------------\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (hotel.bookings[i][j] == value)
            {
                return printf("value %d is found\n", value);
            }
        }
    }
    return printf("value is not found\n");
}
