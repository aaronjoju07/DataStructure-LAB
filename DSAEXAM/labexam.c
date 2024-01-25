#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int pid;
    char pname;
    int uprice;
    struct stack *link;
};
struct stack *top;

void insert()
{
    struct stack *newNode, *temp;
    int pid, uprice;
    char pname;

    newNode = (struct stack *)malloc(sizeof(struct stack));

    printf("Enter process ID: ");
    scanf("%d", &pid);
    if (pid < 0)
    {
        printf("\nNo Negative IDs\n");
        printf("Enter process ID: ");
        scanf("%d", &pid);
    }

    printf("Enter process name: ");
    scanf("%s", &pname);
    printf("Enter unit price: ");
    scanf("%d", &uprice);
    if (uprice > 1000)
    {
        printf("\nUnit Price should be less than 1000.\n");
        printf("Enter unit price: ");
        scanf("%d", &uprice);
    }

    newNode->pid = pid;
    newNode->pname = pname;
    newNode->uprice = uprice;

    if (top == NULL)
    {
        top = newNode;
        top->link = NULL;
    }

    else
    {
        newNode->link = top;
        top = newNode;
    }
}
void display()
{
    struct stack *temp;
    temp = top;

    while (temp != NULL)
    {
        printf("\nProcess ID: %d", temp->pid);
        printf("\nProcess name: %c", temp->pname);
        printf("\nUnit price: %d", temp->uprice);
        temp = temp->link;
    }
}
void search()
{
    struct stack *temp;
    temp = top;
    char sh[29];
    int found = 0;

    printf("Enter process name to search: ");
    scanf("%s", &sh);
    printf("%s", sh);
    while (temp != NULL)
    {
        if ((strcmp(&temp->pname, &sh)) == 0)
        {
            printf("\nElement Found\n");
            printf("\nProcess ID: %d", temp->pid);
            printf("\nProcess name: %c", temp->pname);
            printf("\nUnit price: %d", temp->uprice);
            found = 1;
            break;
        }
        temp = temp->link;
    }

    if (!found)
    {
        printf("\nProcess not found.\n");
    }
}
int main()
{
    int ch = 100, id, price;
    char name[29];
    while (ch != 0)
    {
        printf("\n1.Insert\n2.Display\n3.Search\nEnter your Choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        // case 4:
        //     quickSort();
        //     break;
        default:
            break;
        }
    }
    return 0;
}
void quickSort(){

}
