#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
	int processId;
	char processStatus[10];
	int priority;
	struct node *next;
};
struct node *head;

void insert(int, int);
void display();
void delete();
void displayHighPriority();

int main()
{
	insert(1, 5);
	display();
	displayHighPriority();
	delete ();
	return 0;
};
void insert(int id, int priority)
{
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));
	if (ptr != NULL)
	{
		printf("\nEnter the Status of the PCB Id %d : ", id);
		scanf("%s", &ptr->processStatus);
		ptr->priority = priority;
		ptr->processId = id;

		if (head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
			printf("---Inserted to the Head---");
		}
		else
		{
			temp = head;
			while (temp != NULL)
			{
				temp = temp->next;
			}
			ptr->next = NULL;
			temp->next = ptr;
			printf("---Inserted Successfully---");
		}
	}
	else
	{
		printf("\n---nOVERFLOW---\n");
	}
};
void display()
{
	struct node *temp;
	if (head == NULL)
	{
		printf("\n---List is Empty---\n");
	}
	else
	{
		temp = head;
		printf("\n-------------Display PCBs----------------\n");
		while (temp != NULL)
		{
			printf("\nId : %d , Status : %s , Priority :%d\n", temp->processId, temp->processStatus, temp->priority);
			temp = temp->next;
		}
	}
};
void displayHighPriority()
{
	struct node *temp;
	int id, check = 1000;

	if (head == NULL)
	{
		printf("\n---List is Empty---\n");
	}
	else
	{
		temp = head;
		printf("\n-------------Display PCBs----------------\n");
		while (temp != NULL)
		{
			if (temp->priority < check)
			{
				check = temp->priority;
				id = temp->processId;
				//				status = temp->processStatus;
				printf("\nHighest Priority PCB is with Id : %d has %d priority\n", id, check);
			}
			temp = temp->next;
		}
	}
}
void delete()
{
	struct node *temp, *preTemp;
	temp = head;
	head = NULL;
	printf("\nAfter deleteing DEAD state\n");

	if (head == NULL)
	{
		printf("\n---List is Empty---\n");
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->processStatus != "dead")
			{
				preTemp = temp;
				temp = temp->next;
			}
			else
			{
				printf("\nPCB Id :%d and status : %s with %d priority is deleted\n", temp->processId, temp->processStatus, temp->priority);
				preTemp->next = temp->next;
				temp = temp->next;
			}
		}
	}
};
