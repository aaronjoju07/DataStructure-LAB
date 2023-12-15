#include <stdio.h>
#include <stdlib.h>

void insertBegin();
void insterEnd();
void insertRandom();
void Display();
void deleteBegin();
void deleteEnd();
void deleteRandom();
struct node
{
    int data;
    struct node *next;
};
struct node *head;

int main()
{
    int ch = 1;
    while (ch != 0)
    {
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Display();
            break;
        case 2:
            insertBegin();
            break;
        case 3:
            insterEnd();
            break;
        case 4:
            insertRandom();
            break;
        case 5:
            deleteBegin();
            break;
        default:
            break;
        }
    }

    return 0;
}
void insertBegin()
{
    int val = 100;
    struct node *ptr;  
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\nOverFlow\n");
    }
    else
    {
        ptr->data = val;
        ptr->next = NULL;
        head = ptr;
        printf("\nInserted value at the beginning\n");
        Display();
    }
}
void Display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void insterEnd()
{
    struct node *ptr, *temp;
    int val = 500;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\nOverFlow\n");
    }
    else
    {
        ptr->data = val;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\n value inserted \n");
            Display();
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
            Display();
        }
    }
}
void insertRandom()
{
    int i, val = 300, index;

    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\nOverFlow\n");
    }
    else
    {
        printf("Enter the index : ");
        scanf("%d", &index);
        ptr->data = val;
        temp = head;

        for (i = 0; i < index - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nLocation not found");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nvalue inserted\n");
    }
}
void deleteBegin()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {

        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
void deleteEnd()
{
    struct node *ptr, *temp;
    if (head == NULL)
    {
        printf("\nlist is empty");
    }
    else if (head->next = NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}