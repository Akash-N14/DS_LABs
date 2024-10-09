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

void insertEnd(Node *header, int value)
{
    Node *newNode = createNode(value);
    if (header->next == header)
    { // First element
        header->next = newNode;
        header->prev = newNode;
        newNode->next = header;
        newNode->prev = header;
    }
    else
    {
        Node *tail = header->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = header;
        header->prev = newNode;
    }
}

void displayList(Node *header)
{
    if (header->next == header)
    {
        printf("List is empty.\n");
        return;
    }
    Node *temp = header->next;
    while (temp != header)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node *addTwoNumbers(Node *num1Header, Node *num2Header)
{
    Node *resultHeader = createNode(0); // Header node for the result list
    resultHeader->next = resultHeader;
    resultHeader->prev = resultHeader;

    Node *num1Tail = num1Header->prev;
    Node *num2Tail = num2Header->prev;

    int carry = 0;

    while (num1Tail != num1Header || num2Tail != num2Header || carry != 0)
    {
        int digit1 = (num1Tail != num1Header) ? num1Tail->data : 0;
        int digit2 = (num2Tail != num2Header) ? num2Tail->data : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        Node *newNode = createNode(sum);
        newNode->next = resultHeader->next;
        newNode->prev = resultHeader;
        resultHeader->next->prev = newNode;
        resultHeader->next = newNode;

        if (num1Tail != num1Header)
            num1Tail = num1Tail->prev;
        if (num2Tail != num2Header)
            num2Tail = num2Tail->prev;
    }

    return resultHeader;
}

int main()
{
    Node *num1Header = createNode(0);
    num1Header->next = num1Header;
    num1Header->prev = num1Header;

    Node *num2Header = createNode(0);
    num2Header->next = num2Header;
    num2Header->prev = num2Header;

    printf("Enter the digits of the first number (enter -1 to stop):\n");
    int digit;
    while (1)
    {
        scanf("%d", &digit);
        if (digit == -1)
            break;
        insertEnd(num1Header, digit);
    }

    printf("Enter the digits of the second number (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &digit);
        if (digit == -1)
            break;
        insertEnd(num2Header, digit);
    }

    printf("First number: ");
    displayList(num1Header);
    printf("Second number: ");
    displayList(num2Header);

    Node *resultHeader = addTwoNumbers(num1Header, num2Header);

    printf("Sum: ");
    displayList(resultHeader);

    return 0;
}
