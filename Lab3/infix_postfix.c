#include <stdio.h>

#define MAX_SIZE 10

struct Stack
{
   int top;
    int arr[MAX_SIZE];
};

void initialize(struct Stack *stack){
    stack->top = -1;    
}

int isEmpty(struct Stack *stack){
    if(stack->top == -1)
        return printf("Stack Is Empty!!");
}

int isFull(struct Stack *stack){
    if (stack->top == MAX_SIZE-1)
    {
        return  printf("Stack Is Full!!");
    }  
}

int main(){
    struct Stack stack;
    initialize(&stack);
    isEmpty(&stack);
    return 0;
}
