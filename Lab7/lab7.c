#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node
{
    int roomNumber;
    char guestName[100];
    struct Node *left;
    struct Node *right;
};


struct Node *createNode(int roomNumber, const char guestName[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->roomNumber = roomNumber;
    strcpy(newNode->guestName, guestName);
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node *insert(struct Node *root, int roomNumber, const char guestName[])
{
    if (root == NULL)
    {
        return createNode(roomNumber, guestName);
    }

    if (roomNumber < root->roomNumber)
    {
        root->left = insert(root->left, roomNumber, guestName);
    }
    else if (roomNumber > root->roomNumber)
    {
        root->right = insert(root->right, roomNumber, guestName);
    }

    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("Room Number: %d, Guest Name: %s\n", root->roomNumber, root->guestName);
        inorderTraversal(root->right);
    }
}


void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("Room Number: %d, Guest Name: %s\n", root->roomNumber, root->guestName);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("Room Number: %d, Guest Name: %s\n", root->roomNumber, root->guestName);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, roomNumber;
    char guestName[100];

    do
    {
        printf("\n1. Check-in\n2. Inorder\n3. Preorder\n4. Postorder\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Enter Room Number: ");
            scanf("%d", &roomNumber);
            printf("Enter Guest Name: ");
            scanf(" %s", guestName);
            root = insert(root, roomNumber, guestName);
            break;
        case 2:
            printf("Inorder Traversal:\n");
            inorderTraversal(root);
            break;
        case 3:
            printf("Preorder Traversal:\n");
            preorderTraversal(root);
            break;
        case 4:
            printf("Postorder Traversal:\n");
            postorderTraversal(root);
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
