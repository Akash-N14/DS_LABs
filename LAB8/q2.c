#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char *data[MAX]; 
    int front;       
    int rear;        
} Deque;


void initialize(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}


int isFull(Deque *dq)
{
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}


int isEmpty(Deque *dq)
{
    return dq->front == -1;
}


void insertLeft(Deque *dq, char *str)
{
    if (isFull(dq))
    {
        printf("Deque is full! Cannot insert at left.\n");
        return;
    }

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    {
        dq->front = MAX - 1;
    }
    else
    {
        dq->front--;
    }

    dq->data[dq->front] = strdup(str);
}


void insertRight(Deque *dq, char *str)
{
    if (isFull(dq))
    {
        printf("Deque is full! Cannot insert at right.\n");
        return;
    }

    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    {
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }

    dq->data[dq->rear] = strdup(str);
}


void deleteLeft(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty! Cannot delete from left.\n");
        return;
    }

    printf("Deleted: %s\n", dq->data[dq->front]);
    free(dq->data[dq->front]);

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1; 
    }
    else if (dq->front == MAX - 1)
    {
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
}


void printDeque(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");
    int i = dq->front;
    while (1)
    {
        printf("%s ", dq->data[i]);
        if (i == dq->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main()
{
    Deque dq;
    initialize(&dq);

    insertRight(&dq, "Hello");
    insertRight(&dq, "World");
    insertLeft(&dq, "C");
    insertLeft(&dq, "Programming");

    printDeque(&dq);

    deleteLeft(&dq);
    printDeque(&dq);

    deleteLeft(&dq);
    printDeque(&dq);

    insertRight(&dq, "Queue");
    printDeque(&dq);

    return 0;
}
