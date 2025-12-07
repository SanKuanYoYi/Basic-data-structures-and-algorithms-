#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000

typedef struct {
    long long data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
    return;
}

void push(Stack* s, long long x) {
    s->data[++(s->top)] = x;
    return;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return;
    } else s->top--;
    return;
}

void query(Stack* s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return;
    } else printf("%lld\n", s->data[s->top]);
    return;
}

void size(Stack* s) {
    printf("%d\n", s->top + 1);
    return;
}

int main() {

    Stack s;
    initStack(&s);

    int n;
    scanf("%d", &n);

    while (n--) {

        char opt[10];
        scanf("%s", opt);

        if (strcmp("push", opt) == 0) {
            long long x;
            scanf("%lld", &x);
            push(&s, x);
        }

        else if (strcmp("pop", opt) == 0) {
            pop(&s);
        }

        else if (strcmp("query", opt) == 0) {
            query(&s);
        }

        else if (strcmp("size", opt) == 0) {
            size(&s);
        }

    }

    return 0;
}
