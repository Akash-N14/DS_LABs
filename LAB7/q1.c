#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define MAX_STR_LEN 100

struct CircularQueue
{
    char items[SIZE][MAX_STR_LEN];
    int front, rear;
};

void initialize(struct CircularQueue *cq)
{
    cq->front = -1;
    cq->rear = -1;
}

int isFull(struct CircularQueue *cq)
{
    return (cq->front == (cq->rear + 1) % SIZE);
}

int isEmpty(struct CircularQueue *cq)
{
    return (cq->front == -1);
}

void insertcq(struct CircularQueue *cq, char *value)
{
    if (isFull(cq))
    {
        printf("Queue is full! Cannot insert \"%s\"\n", value);
    }
    else
    {
        if (cq->front == -1)
        {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % SIZE;
        strcpy(cq->items[cq->rear], value);
        printf("\"%s\" inserted into the queue.\n", value);
    }
}

void deletecq(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty! Cannot delete.\n");
    }
    else
    {
        printf("\"%s\" deleted from the queue.\n", cq->items[cq->front]);
        if (cq->front == cq->rear)
        {
            cq->front = cq->rear = -1;
        }
        else
        {
            cq->front = (cq->front + 1) % SIZE;
        }
    }
}

void displaycq(struct CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("Circular Queue contents:\n");
        int i = cq->front;
        while (1)
        {
            printf("%s\n", cq->items[i]);
            if (i == cq->rear)
                break;
            i = (i + 1) % SIZE;
        }
    }
}

int main()
{
    struct CircularQueue cq;
    initialize(&cq);

    insertcq(&cq, "Item 1");
    insertcq(&cq, "Item 2");
    insertcq(&cq, "Item 3");
    insertcq(&cq, "Item 4");
    insertcq(&cq, "Item 5");

    displaycq(&cq);

    deletecq(&cq);
    deletecq(&cq);

    insertcq(&cq, "Item 6");
    displaycq(&cq);

    return 0;
}
