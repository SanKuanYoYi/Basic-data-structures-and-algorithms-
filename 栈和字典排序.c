#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int* b = (int*)malloc(n * sizeof(int));
    b[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        b[i] = (a[i] > b[i + 1]) ? a[i] : b[i + 1];
    }

    int* stack = (int*)malloc(n * sizeof(int));
    int* result = (int*)malloc(n * sizeof(int));

    int top = -1;
    int index = 0;

    for (int i = 0; i < n; i++) {
        stack[++top] = a[i];

        while (top >= 0 && stack[top] >= b[i + 1]) {
            result[index++] = stack[top--];
        }
    }

    while (top >= 0) {
        result[index++] = stack[top--];
    }

    for (int i = 0; i < index; i++) {
        printf("%d", result[i]);

        if (i != index - 1) {
            printf(" ");
        }
    }

    free(a);
    free(b);
    free(stack);
    free(result);

    return 0;
}
