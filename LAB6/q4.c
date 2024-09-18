#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    char arr[MAX][MAX];
    int top;
}Stack;

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char *value)
{
    if (stack->top < MAX - 1)
    {
        strcpy(stack->arr[++(stack->top)], value);
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

void pop(Stack *stack, char *result)
{
    if (!isEmpty(stack))
    {
        strcpy(result, stack->arr[(stack->top)--]);
    }
    else
    {
        printf("Stack Underflow\n");
    }
}

void prefixToPostfix(char *prefix, char *postfix)
{
    Stack stack;
    stack.top = -1;

    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--)
    {
        if (isalnum(prefix[i]))
        {
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand);
        }
        else
        {
            char operand1[MAX], operand2[MAX];
            pop(&stack, operand1);
            pop(&stack, operand2);
            char expr[MAX] = "";
            strcat(expr, operand1);
            strcat(expr, operand2);
            int len = strlen(expr);
            expr[len] = prefix[i];
            expr[len + 1] = '\0';
            push(&stack, expr);
        }
    }
    pop(&stack, postfix);
}

int main()
{
    char prefix[MAX], postfix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
