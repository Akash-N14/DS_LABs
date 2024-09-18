#include <stdio.h>
#include <stdlib.h>

#define N 10 


struct DualCircularQueue
{
    int items[N];
    int front1, rear1; 
    int front2, rear2; 
};


void initialize(struct DualCircularQueue *dcq)
{
    dcq->front1 = dcq->rear1 = -1;
    dcq->front2 = dcq->rear2 = N / 2;
}


int isFull1(struct DualCircularQueue *dcq)
{
    return ((dcq->rear1 + 1) % (N / 2) == dcq->front1);
}


int isEmpty1(struct DualCircularQueue *dcq)
{
    return (dcq->front1 == -1);
}

int isFull2(struct DualCircularQueue *dcq)
{
    return ((dcq->rear2 + 1) % (N / 2) + N / 2 == dcq->front2);
}

int isEmpty2(struct DualCircularQueue *dcq)
{
    return (dcq->front2 == N / 2);
}

void insertcq1(struct DualCircularQueue *dcq, int value)
{
    if (isFull1(dcq))
    {
        printf("Queue 1 is full! Cannot insert %d\n", value);
    }
    else
    {
        if (dcq->front1 == -1)
        {
            dcq->front1 = 0;
        }
        dcq->rear1 = (dcq->rear1 + 1) % (N / 2);
        dcq->items[dcq->rear1] = value;
        printf("%d inserted into Queue 1.\n", value);
    }
}

void insertcq2(struct DualCircularQueue *dcq, int value)
{
    if (isFull2(dcq))
    {
        printf("Queue 2 is full! Cannot insert %d\n", value);
    }
    else
    {
        if (dcq->front2 == N / 2)
        {
            dcq->front2 = (N / 2) + 1;
        }
        dcq->rear2 = (dcq->rear2 + 1) % (N / 2) + N / 2;
        dcq->items[dcq->rear2] = value;
        printf("%d inserted into Queue 2.\n", value);
    }
}

void deletecq1(struct DualCircularQueue *dcq)
{
    if (isEmpty1(dcq))
    {
        printf("Queue 1 is empty! Cannot delete.\n");
    }
    else
    {
        printf("%d deleted from Queue 1.\n", dcq->items[dcq->front1]);
        if (dcq->front1 == dcq->rear1)
        {
            dcq->front1 = dcq->rear1 = -1;
        }
        else
        {
            dcq->front1 = (dcq->front1 + 1) % (N / 2);
        }
    }
}

void deletecq2(struct DualCircularQueue *dcq)
{
    if (isEmpty2(dcq))
    {
        printf("Queue 2 is empty! Cannot delete.\n");
    }
    else
    {
        printf("%d deleted from Queue 2.\n", dcq->items[dcq->front2]);
        if (dcq->front2 == dcq->rear2)
        {
            dcq->front2 = dcq->rear2 = N / 2;
        }
        else
        {
            dcq->front2 = (dcq->front2 + 1) % (N / 2) + N / 2;
        }
    }
}

void displaycq1(struct DualCircularQueue *dcq)
{
    if (isEmpty1(dcq))
    {
        printf("Queue 1 is empty!\n");
    }
    else
    {
        printf("Queue 1 contents:\n");
        int i = dcq->front1;
        while (1)
        {
            printf("%d ", dcq->items[i]);
            if (i == dcq->rear1)
                break;
            i = (i + 1) % (N / 2);
        }
        printf("\n");
    }
}

void displaycq2(struct DualCircularQueue *dcq)
{
    if (isEmpty2(dcq))
    {
        printf("Queue 2 is empty!\n");
    }
    else
    {
        printf("Queue 2 contents:\n");
        int i = dcq->front2;
        while (1)
        {
            printf("%d ", dcq->items[i]);
            if (i == dcq->rear2)
                break;
            i = (i + 1) % (N / 2) + N / 2;
        }
        printf("\n");
    }
}

int main()
{
    struct DualCircularQueue dcq;
    initialize(&dcq);

    insertcq1(&dcq, 10);
    insertcq1(&dcq, 20);
    insertcq1(&dcq, 30);
    insertcq1(&dcq, 40);
    insertcq1(&dcq, 50);
    displaycq1(&dcq);
    deletecq1(&dcq);
    displaycq1(&dcq);

    
    insertcq2(&dcq, 60);
    insertcq2(&dcq, 70);
    insertcq2(&dcq, 80);
    insertcq2(&dcq, 90);
    insertcq2(&dcq, 100); 
    displaycq2(&dcq);
    deletecq2(&dcq);
    displaycq2(&dcq);

    return 0;
}
