#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 2

struct matrixStruct
{
    char hotel_name;
    int bookings[ROWS][COLS];
};

struct matrixStruct hotel;

void insertionDisplay();
void deleteMatrix(int** matrix, int numRows);
void displayMatrix();
int main()
{
    int choice;
    int continueMenu = 1; // A flag to continue the menu loop

    while (continueMenu)
    {
        printf("----------------------Hotel_Management---------------------------\n");
        printf("Enter your Choice (1: Insert, 2: Delete3: Display,4: Searching, 0: Exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the booking count received in the last 9 days:\n");
            insertionDisplay();
            break;
        case 2:
            // Delete the matrix
            deleteMatrix((int**)hotel.bookings, ROWS);
            printf("Matrix deleted\n");
            break;
        case 3:
            displayMatrix();
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
void displayMatrix(){
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

void deleteMatrix(int **matrix, int numRows)
{
    for (int i = 0; i < numRows; i++)
    {
        free(matrix[i]); // Free memory for each row
        break;
    }
    free(matrix); // Free memory for the array of row pointers
}
