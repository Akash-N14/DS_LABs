#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete duplicates from a sorted linked list
void deleteDuplicates(struct Node *head)
{
    struct Node *current = head;

    while (current != NULL && current->next != NULL)
    {
        // If current node data is the same as next node, skip the next node
        if (current->data == current->next->data)
        {
            struct Node *temp = current->next;
            current->next = current->next->next; // Bypass the duplicate
            free(temp);                          // Free the memory of the duplicate node
        }
        else
        {
            current = current->next; // Move to the next node
        }
    }
}

// Function to display the linked list
void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    struct Node *head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original List:\n");
    display(head);

    deleteDuplicates(head);

    printf("List after removing duplicates:\n");
    display(head);

    return 0;
}
