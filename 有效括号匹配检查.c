#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000

int main() {

    char s[MAX_SIZE];
    fgets(s, MAX_SIZE, stdin);
    s[strcspn(s, "\n")] = '\0';

    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char temp = s[i];

        if (temp == '(' || temp == '{' || temp == '[') {
            stack[++top] = temp;
        }

        else if (temp == ')' || temp == '}' || temp == ']') {
            if (top == -1) {
                printf("false\n");
                return 0;
            }

            char topch = stack[top];
            if ((temp == ')' && topch == '(') ||
                    (temp == '}' && topch == '{') ||
                    (temp == ']' && topch == '[')) {
                top--;
            } else {
                printf("false\n");
                return 0;
            }
        }
    }

    if (top == -1) {
        printf("true\n");
    } else printf("false\n");

    return 0;
}
