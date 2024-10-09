#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} Node;

Node *createNode(int coeff, int exp)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;
    return newNode;
}

void insertEnd(Node *header, int coeff, int exp)
{
    Node *newNode = createNode(coeff, exp);
    if (header->next == header)
    {
        header->next = newNode;
    }
    else
    {
        Node *temp = header->next;
        while (temp->next != header)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    newNode->next = header;
}

void display(Node *header)
{
    if (header->next == header)
    {
        printf("0\n");
        return;
    }
    Node *temp = header->next;
    while (temp != header)
    {
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

Node *subtract(Node *poly1, Node *poly2)
{
    Node *result = createNode(0, 0);
    Node *temp1 = poly1->next;
    Node *temp2 = poly2->next;
    while (temp1 != poly1 || temp2 != poly2)
    {
        if (temp1->exp == temp2->exp)
        {
            insertEnd(result, temp1->coeff - temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            insertEnd(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else
        {
            insertEnd(result, -temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }
    while (temp1 != poly1)
    {
        insertEnd(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while (temp2 != poly2)
    {
        insertEnd(result, -temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
    return result;
}

Node *multiply(Node *poly1, Node *poly2)
{
    Node *result = createNode(0, 0);
    Node *temp1 = poly1->next;
    Node *temp2 = poly2->next;
    while (temp1 != poly1)
    {
        temp2 = poly2->next;
        while (temp2 != poly2)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insertEnd(result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

void freeList(Node *header)
{
    Node *temp = header->next;
    while (temp != header)
    {
        Node *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    free(header);
}

int main()
{
    Node *poly1 = createNode(0, 0);
    Node *poly2 = createNode(0, 0);
    int choice, coeff, exp;
    while (1)
    {
        printf("1. Input Polynomials\n2. Subtract\n3. Multiply\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 2; i++)
            {
                printf("Enter polynomial %d (coeff exp, enter -1 -1 to stop):\n", i + 1);
                while (1)
                {
                    scanf("%d %d", &coeff, &exp);
                    if (coeff == -1 && exp == -1)
                        break;
                    insertEnd(i == 0 ? poly1 : poly2, coeff, exp);
                }
            }
            break;
        case 2:
        {
            Node *result = subtract(poly1, poly2);
            printf("Subtraction Result: ");
            display(result);
            freeList(result);
        }
        break;
        case 3:
        {
            Node *result = multiply(poly1, poly2);
            printf("Multiplication Result: ");
            display(result);
            freeList(result);
        }
        break;
        case 4:
            printf("Polynomial 1: ");
            display(poly1);
            printf("Polynomial 2: ");
            display(poly2);
            break;
        case 5:
            freeList(poly1);
            freeList(poly2);
            exit(0);
        }
    }
    return 0;
}
