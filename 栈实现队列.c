#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void pushStack(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++(stack->top)] = value;
    }
}

int popStack(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return -1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

Stack* stack1 = NULL;
Stack* stack2 = NULL;
int initialized = 0;

void initStacks() {
    if (!initialized) {
        stack1 = createStack(1000);
        stack2 = createStack(1000);
        initialized = 1;
    }
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param node int整型
 * @return 无
 */
void push(int node) {

    initStacks();

    pushStack(stack1, node);
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param 无
 * @return int整型
 */
int pop() {

    initStacks();

    if (isStackEmpty(stack2)) {
        while (!isStackEmpty(stack1)) {
            int value = popStack(stack1);
            pushStack(stack2, value);
        }
    }

    return popStack(stack2);
}
