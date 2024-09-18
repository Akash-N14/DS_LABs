#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int top;
    char items[MAX];
}Stack;

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char value)
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

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
    {
        return s->items[(s->top)--];
    }
}

char peek(Stack *s)
{
    if (isEmpty(s))
    {
        return '\0';
    }
    else
    {
        return s->items[s->top];
    }
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void reverse(char *exp)
{
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack stack;
    stack.top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }
    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

void infixToPrefix(char *infix, char *prefix)
{
    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
