#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct 
{
    int arr[MAX];
    int top1;
    int top2;
} TwoStacks;

// Function to initialize the two stacks
void initialize(TwoStacks *stacks)
{
    stacks->top1 = -1;
    stacks->top2 = MAX;
}

void push1(TwoStacks *stacks, int value)
{
    if (stacks->top1 < stacks->top2 - 1)
    {
        stacks->arr[++(stacks->top1)] = value;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void push2(TwoStacks *stacks, int value)
{
    if (stacks->top1 < stacks->top2 - 1)
    {
        stacks->arr[--(stacks->top2)] = value;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop1(TwoStacks *stacks)
{
    if (stacks->top1 >= 0)
    {
        return stacks->arr[(stacks->top1)--];
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

int pop2(TwoStacks *stacks)
{
    if (stacks->top2 < MAX)
    {
        return stacks->arr[(stacks->top2)++];
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

void display1(TwoStacks *stacks)
{
    if (stacks->top1 >= 0)
    {
        printf("Stack 1: ");
        for (int i = 0; i <= stacks->top1; i++)
        {
            printf("%d ", stacks->arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 1 is empty\n");
    }
}

void display2(TwoStacks *stacks)
{
    if (stacks->top2 < MAX)
    {
        printf("Stack 2: ");
        for (int i = MAX - 1; i >= stacks->top2; i--)
        {
            printf("%d ", stacks->arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 2 is empty\n");
    }
}

int main()
{
    TwoStacks stacks;
    initialize(&stacks);

    push1(&stacks, 10);
    push1(&stacks, 20);
    push2(&stacks, 30);
    push2(&stacks, 40);

    display1(&stacks); 
    display2(&stacks); 

    printf("Popped from Stack 1: %d\n", pop1(&stacks));
    printf("Popped from Stack 2: %d\n", pop2(&stacks));

    display1(&stacks);
    display2(&stacks);

    return 0;
}
