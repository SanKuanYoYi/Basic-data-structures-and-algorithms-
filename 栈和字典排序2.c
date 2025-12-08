#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int* stack = (int*)malloc(n * sizeof(int));
    int* output = (int*)malloc(n * sizeof(int));
    int top = -1;
    int out_idx = 0;
    int need = 1;
    
    for (int i = 0; i < n; i++) {
        stack[++top] = a[i];

        while (top >= 0 && stack[top] == need) {
            output[out_idx++] = stack[top--];
            need++;
        }
    }

    while (top >= 0) {
        output[out_idx++] = stack[top--];
    }

    for (int i = 0; i < out_idx; i++) {
        printf("%d", output[i]);
        if (i != out_idx - 1) {
            printf(" ");
        }
    }
    
    free(a);
    free(stack);
    free(output);
    
    return 0;
}
