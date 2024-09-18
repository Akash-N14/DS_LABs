#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct 
{
    int top;
    int items[MAX];
} Stack;

void push(Stack *s, int value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->items[++(s->top)] = value;
    }
}

int pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return s->items[(s->top)--];
    }
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void deleteKElements(int arr[], int n, int k)
{
    Stack stack;
    stack.top = -1;

    for (int i = 0; i < n; i++)
    {
        while (!isEmpty(&stack) && arr[i] > stack.items[stack.top] && k > 0)
        {
            pop(&stack);
            k--;
        }
        push(&stack, arr[i]);
    }

    for (int i = 0; i <= stack.top; i++)
    {
        printf("%d ", stack.items[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {20, 10, 25, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    deleteKElements(arr, n, k);

    return 0;
}
