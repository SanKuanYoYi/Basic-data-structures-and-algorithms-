#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {

    char* s1 = *(char**) a;
    char* s2 = *(char**) b;

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char temp1[len1 + len2 + 1];
    char temp2[len1 + len2 + 1];

    strcpy(temp1, s1);
    strcat(temp1, s2);

    strcpy(temp2, s2);
    strcat(temp2, s1);

    return strcmp(temp2, temp1);
}

int main() {

    int n;
    scanf("%d", &n);

    long nums[n][n+1];
    char* p[n];

    for(int i = 0; i < n; i++) {
        scanf("%s", &nums[i]);
        p[i] = nums[i];
    }

    qsort(p, n, sizeof(char*), compare);

    for (int i = 0; i < n; i++) {
        printf("%s", p[i]);
    }
    printf("\n");

    return 0;
}
