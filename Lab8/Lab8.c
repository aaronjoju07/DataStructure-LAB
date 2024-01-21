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


struct Node *removeGuest(struct Node *root, int roomNumber)
{
    if (root == NULL)
    {
        return root;
    }

    if (roomNumber < root->roomNumber)
    {
        root->left = removeGuest(root->left, roomNumber);
    }
    else if (roomNumber > root->roomNumber)
    {
        root->right = removeGuest(root->right, roomNumber);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        root->roomNumber = temp->roomNumber;
        strcpy(root->guestName, temp->guestName);
        root->right = removeGuest(root->right, temp->roomNumber);
    }

    return root;
}


struct Node *search(struct Node *root, int roomNumber)
{
    if (root == NULL || root->roomNumber == roomNumber)
    {
        return root;
    }

    if (roomNumber < root->roomNumber)
    {
        return search(root->left, roomNumber);
    }

    return search(root->right, roomNumber);
}


int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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

// Function for preorder traversal of the BST
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
        printf("\n1. Check-in\n2. Check-out\n3. Find Guest\n4. Display Occupied Rooms\n5. Height\n6. Inorder\n7. Preorder\n8. Postorder\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Room Number: ");
            scanf("%d", &roomNumber);
            printf("Enter Guest Name: ");
            scanf(" %[^\n]s", guestName);
            root = insert(root, roomNumber, guestName);
            break;
        case 2:
            printf("Enter Room Number to Check-out: ");
            scanf("%d", &roomNumber);
            root = removeGuest(root, roomNumber);
            break;
        case 3:
            printf("Enter Room Number to Find Guest: ");
            scanf("%d", &roomNumber);
            if (search(root, roomNumber) != NULL)
            {
                printf("Guest found in the hotel.\n");
            }
            else
            {
                printf("Guest not found in the hotel.\n");
            }
            break;
        case 4:
            printf("Occupied Rooms:\n");
            inorderTraversal(root);
            break;
        case 5:
            printf("Height of the Hotel BST: %d\n", height(root));
            break;
        case 6:
            printf("Inorder Traversal:\n");
            inorderTraversal(root);
            break;
        case 7:
            printf("Preorder Traversal:\n");
            preorderTraversal(root);
            break;
        case 8:
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
