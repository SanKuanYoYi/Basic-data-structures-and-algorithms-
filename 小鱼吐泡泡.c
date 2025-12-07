#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {

        char s[MAX_SIZE];
        fgets(s, MAX_SIZE, stdin);
        s[strcspn(s, "\n")] = '\0';

        char stack[MAX_SIZE] = {0};
        int top = -1;

        for (int i = 0; i < strlen(s); i++) {
            char ch = s[i];

            if (ch == 'o') {

                if (top > -1) {
                    if (stack[top] == 'o') {
                        stack[top] = 'O';
                    } else if (stack[top] == 'O') {
                        stack[++top] = ch;
                    }
                } else {
                    stack[++top] = ch;
                }
            }

            else if (ch == 'O') {

                if (top > -1) {
                    if (stack[top] == 'O') {
                        stack[top] = 0 + '0';
                        top--;
                    } else if (stack[top] == 'o') {
                        stack[++top] = ch;
                    }
                } else {
                    stack[++top] = ch;
                }
            }

        }

        if (top == -1) {
            printf("\n");
        }

        else
            for (int i = 0; i < strlen(stack) && stack[i] != '0'; i++) {
                printf("%c", stack[i]);
            }
        printf("\n");


    }

    return 0;
}
