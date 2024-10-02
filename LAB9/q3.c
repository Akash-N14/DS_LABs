#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int height;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int height)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->height = height;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node *insert(struct Node *head, int height)
{
    struct Node *newNode = createNode(height);
    if (head == NULL)
    {
        return newNode; // If the list is empty, return new node as head
    }

    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode; // Link the new node at the end
    return head;
}

// Function to display the linked list
void display(struct Node *head)
{
    printf("->");
    while (head != NULL)
    {
        printf("%d->", head->height);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node *merge(struct Node *headA, struct Node *headB)
{
    struct Node *mergedHead = NULL;
    struct Node **tail = &mergedHead; // Pointer to the last node in merged list

    // Merge nodes from both lists
    while (headA != NULL && headB != NULL)
    {
        struct Node *temp;
        if (headA->height < headB->height)
        {
            temp = headA;
            headA = headA->next; // Move to the next node in list A
        }
        else
        {
            temp = headB;
            headB = headB->next; // Move to the next node in list B
        }

        *tail = temp;            // Link the smaller node to the merged list
        tail = &((*tail)->next); // Update tail to point to the new end of the merged list
    }

    // Attach the remaining nodes of list A or B
    if (headA != NULL)
    {
        *tail = headA;
    }
    else
    {
        *tail = headB;
    }

    return mergedHead; // Return the head of the merged list
}

int main()
{
    int N1, N2;

    // Input the number of students in class A and B
    scanf("%d %d", &N1, &N2);

    struct Node *classA = NULL;
    struct Node *classB = NULL;

    // Input heights for class A
    for (int i = 0; i < N1; i++)
    {
        int height;
        scanf("%d", &height);
        classA = insert(classA, height);
    }

    // Input heights for class B
    for (int i = 0; i < N2; i++)
    {
        int height;
        scanf("%d", &height);
        classB = insert(classB, height);
    }

    // Display Class A
    printf("Class A\n");
    display(classA);

    // Display Class B
    printf("Class B\n");
    display(classB);

    // Merge the two classes
    struct Node *jointClass = merge(classA, classB);

    // Display Joint Class
    printf("Joint Class\n");
    display(jointClass);

    // Free the allocated memory (optional for cleanup)
    // Add memory cleanup code here if necessary

    return 0;
}
