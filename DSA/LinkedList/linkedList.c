#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void beginsert(int);
int findSum();

int main()
{
    int choice, item;
    do
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d", &item);
        beginsert(item);
        printf("\nPress 0 to insert more?\n");
        scanf("%d", &choice);
    } while (choice == 0);

    int sum = findSum();
    printf("Sum of all elements in the linked list: %d\n", sum);

    return 0;
}

void beginsert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }
}

int findSum()
{
    int sum = 0;
    struct node *current = head;
    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }
    return sum;
}
