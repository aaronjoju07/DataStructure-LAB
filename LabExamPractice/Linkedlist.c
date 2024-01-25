#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int id;
    char name[20];
    struct node *next;
};
struct node *head;
void Display();
void InsertBegining();
int main()
{
    int ch;
    while (ch != 0)
    {
        printf("\n1.Display\n 2.InsertBegining\n 3.DeleteBegining\n 4.InsertEnd\n 5.DeleteEnd \n6.InsertRandom\n");
        switch (ch)
        {
        case 1:
            Display();
            break;
        case 2:
            InsertBegining();
            break;

        default:
            printf("Invalid Choice");
            break;
        }
    }

    return 0;
}
void InsertBegining()
{
    int val;
    char name[20];
    printf("\nEnter the value :");
    scanf("%d", &val);
    printf("\nEnter the Name :");
    scanf("%c", &name);
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->id = val;
    strcpy(ptr->name, name);
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = ptr;
        ptr = head;
    }
}