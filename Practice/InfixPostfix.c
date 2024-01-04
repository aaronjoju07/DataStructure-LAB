#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100;

struct stack
{
    int arr[100];
    int top;
};
int isEmpty(struct stack *stack)
{
    return (stack->top == -1);
}
void push(struct stack *stack, int x)
{
    if (stack->top == 100 - 1)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = x;
}
int pop(struct stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}
int peek(struct stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}
int precedence(char operation)
{
    if (operation == '+' || operation == '-')
    {
        return 1;
    }
    else if (operation == '*' || operation == '/')
    {
        return 2;
    }
    return 0;
}
void infixToPostfix(char infix[], char postfix[])
{
    struct stack stack;
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (isdigit(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '()')
        {
            push(&stack, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&stack) && peak(&stack) != '(')
            {
                postfix[j++] == pop(&stack);
            }
            if (!isEmpty(&stack) && peak(&stack) != '(')
            {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            }
            else
            {
                pop(&stack);
                i++;
            }
        }
    }
    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }
    postfix = '\0';
}
int eveluatePostfix()
{
}
int main()
{
    struct stack *stack;
    stack->top = -1;
    char infix[] = "3+5*(6-2)/8";
    char postfix[100];
    infixToPostfix(infix, postfix);
    return 0;
}
