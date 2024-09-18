#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct{
    int top;
    int items[MAX];
}Stack;

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

int evaluatePrefix(char* expr) {
    Stack stack;
    stack.top = -1;

    for (int i = strlen(expr) - 1; i >= 0; i--) {
        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            int op1 = pop(&stack);
            int op2 = pop(&stack);
            switch (expr[i]) {
                case '+':
                    push(&stack, op1 + op2);
                    break;
                case '-':
                    push(&stack, op1 - op2);
                    break;
                case '*':
                    push(&stack, op1 * op2);
                    break;
                case '/':
                    push(&stack, op1 / op2);
                    break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char expr[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", expr);

    int result = evaluatePrefix(expr);
    printf("The result of the prefix expression is: %d\n", result);

    return 0;
}
