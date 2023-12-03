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
int main()
{
    beginsert();
    lastinsert();
    display();
    return 0;
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
        return printf("Inserted value at the beginning");
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
        while (ptr!=NULL)
        {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
        
    }
}