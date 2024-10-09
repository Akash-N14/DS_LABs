#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[100];
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(const char *value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node **head, const char *value)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(Node **head)
{
    Node *temp = NULL;
    Node *current = *head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

int main()
{
    Node *head = NULL;
    insertEnd(&head, "Hello");
    insertEnd(&head, "world");
    insertEnd(&head, "this");
    insertEnd(&head, "is");
    insertEnd(&head, "a");
    insertEnd(&head, "test");

    printf("Original list: ");
    displayList(head);

    reverseList(&head);

    printf("Reversed list: ");
    displayList(head);

    return 0;
}
