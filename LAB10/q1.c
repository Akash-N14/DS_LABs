#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node **head, int value)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("%d inserted at the head.\n", value);
}

void insertAtTail(Node **head, int value)
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
    printf("%d inserted at the tail.\n", value);
}

void deleteFromHead(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from head.\n");
        return;
    }
    Node *temp = *head;
    printf("Deleting %d from the head.\n", temp->data);
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteFromTail(Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from tail.\n");
        return;
    }
    Node *temp = *head;
    if (temp->next == NULL)
    {
        printf("Deleting %d from the tail.\n", temp->data);
        *head = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("Deleting %d from the tail.\n", temp->data);
        temp->prev->next = NULL;
    }
    free(temp);
}

void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Delete from head\n");
        printf("4. Delete from tail\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at head: ");
            scanf("%d", &value);
            insertAtHead(&head, value);
            break;
        case 2:
            printf("Enter value to insert at tail: ");
            scanf("%d", &value);
            insertAtTail(&head, value);
            break;
        case 3:
            deleteFromHead(&head);
            break;
        case 4:
            deleteFromTail(&head);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
