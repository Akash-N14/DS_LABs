#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int N, K;
        scanf("%d %d", &N, &K);

        struct Queue *queue = createQueue(N);

        for (int i = 1; i <= N; i++)
        {
            enqueue(queue, i);
        }

        int canEnterTogether = 0;
        while (!isEmpty(queue))
        {
            int group[3];
            for (int i = 0; i < 3 && !isEmpty(queue); i++)
            {
                group[i] = dequeue(queue);
            }

            for (int i = 0; i < 3; i++)
            {
                if (group[i] == K && i < 2 && group[i + 1] == K + 1)
                {
                    canEnterTogether = 1;
                    break;
                }
            }

            if (canEnterTogether)
            {
                break;
            }
        }

        if (canEnterTogether)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

        free(queue->array);
        free(queue);
    }

    return 0;
}
