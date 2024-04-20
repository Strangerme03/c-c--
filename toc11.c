//WAP to implement PDA that accepts the language L= {an bn}.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct {
    char items[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char c) {
    stack->items[++(stack->top)] = c;
}

char pop(Stack *stack) {
    if (stack->top == -1) {
        return '\0';
    } else {
        return stack->items[(stack->top)--];
    }
}

bool isAccepted(char *input) {
    Stack stack;
    initStack(&stack);
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] == 'a') {
            push(&stack, 'a');
        } else if (input[i] == 'b') {
            if (pop(&stack) != 'a') {
                return false;
            }
        } else {
            return false;
        }
    }

    return (stack.top == -1);
}

int main() {
    char input[100];

    printf("Enter the string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("String belongs to the language L = {an bn}\n");
    } else {
        printf("String does not belong to the language L = {an bn}\n");
    }

    return 0;
}