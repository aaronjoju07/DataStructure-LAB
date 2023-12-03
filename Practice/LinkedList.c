#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
int beginsert();
void lastinsert();
void display();
void randominsert();
int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            display();
            break;
        case 4:
            randominsert();
            break;
        case 9:
            exit(0);
        default:
            printf("\nInvalid Input\n");
            break;
        }
    }
}
void randominsert()
{
    int i, loc, val = 300;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data = val;
        printf("\nEnter the location after which you want to insert ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nLocation not found");
                return; // Add return statement to exit the function if location not found
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\ndata inserted\n");
    }
}

int beginsert()
{
    struct node *ptr;
    int val = 100;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        return printf("\nOverFlow\n");
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        head = ptr;
        return printf("\nInserted value at the beginning\n");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int val = 200;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\n OverFlow \n");
    }
    else
    {
        ptr->data = val;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\n value inserted \n");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nvalue inserted at end of list\n");
        }
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("No list avaliable");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
    }
}