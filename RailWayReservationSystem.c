#include <stdio.h>

struct RailWayReservationSystem
{
    int passengerNo;
    char passengerName[25];
    float ticketPrice;
};
struct RailWayReservationSystem rail[5];
void insertPassenger();
void DisplayPassengers();
int searchPassenger(int passengerNumber);
int main()
{
    int choice, passNo;
    int continueMenu = 1; // A flag to continue the menu loop

    while (continueMenu)
    {
        printf("----------------------RailWay Reservation System---------------------------\n");
        printf("Enter your Choice (1: Insert details for 5  passengers, 2: Display, 3: Searching, 0: Exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertPassenger();
            break;
        case 2:
            DisplayPassengers();
            break;
        case 3:
            printf("Enter the passenger number \n");
            scanf("%d", &passNo);
            searchPassenger(passNo);
            break;
        case 0:

            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void insertPassenger()
{
    printf("\n");
    printf("Enter the Details for 5 passengers:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Passenger %d:\n", i + 1);
        rail[i].passengerNo = i + 1;
        printf("Name: ");
        scanf("%s", rail[i].passengerName);
        printf("Ticket Price: ");
        scanf("%f", &rail[i].ticketPrice);
        printf("\n");
    }
    printf("inserted successfully \n");
}
void DisplayPassengers()
{
    printf("\n");
    printf("Passenger Details:\n");
    for (int i = 0; i < 5; i++)
    {
        if (rail[i].passengerNo != 0)
        {
            printf("Passenger %d - Name: %s, Ticket Price: %.2f\n", rail[i].passengerNo, rail[i].passengerName, rail[i].ticketPrice);
        }
    }
}
int searchPassenger(int passengerNumber)
{
    for (int i = 0; i < 5; i++)
    {
        if (rail[i].passengerNo == passengerNumber)
        {
            return printf("Passenger %d - Name: %s, Ticket Price: %.2f\n", rail[i].passengerNo, rail[i].passengerName, rail[i].ticketPrice);
            ;
        }
    }
    return printf("passenger not found\n"); // Passenger not found
}