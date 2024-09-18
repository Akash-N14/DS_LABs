#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct 
{
    int top;
    char items[MAX];
} Stack;

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
    if (s->top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
    {
        return s->items[(s->top)--];
    }
}

int isPalindrome(char str[])
{
    Stack stack;
    stack.top = -1;
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        push(&stack, str[i]);

    }
    for (int i = 0; i < length; i++)
    {
        if (str[i])
        {
            if (str[i] != pop(&stack))
            {
                return 0;
            }
        }
    }
    return 1; 
}

int main()
{
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
