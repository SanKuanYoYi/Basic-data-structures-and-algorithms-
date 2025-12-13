#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    long long data;
    struct QueueNode* next;
} QueueNode;

QueueNode* creatNew(long long x) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));

    newNode->data = x;
    newNode->next = NULL;

    return newNode;
}

QueueNode* add_queue(QueueNode* head, long long x) {
    QueueNode* newNode = creatNew(x);

    if (head == NULL) {
        return newNode;
    }

    QueueNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

QueueNode* pop_head(QueueNode* head) {
    if (head == NULL) {
        return NULL;
    }

    QueueNode* newHead = head->next;
    free(head);

    return newHead;
}

void print_head(QueueNode* head) {
    printf("%lld\n", head->data);
}

void count_head(QueueNode* head) {
    QueueNode* temp = head;

    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("%d\n", count);
}

int main() {

    QueueNode* head = NULL;

    int n;
    scanf("%d", &n);

    while (n--) {

        int opt;
        scanf("%d", &opt);

        switch (opt) {

            case 1: {
                    long long x;
                    scanf("%lld", &x);

                    head = add_queue(head, x);
                    break;
                }

            case 2:
                if (head != NULL) {
                    head = pop_head(head);
                    break;
                } else {
                    printf("ERR_CANNOT_POP\n");
                    break;
                }

            case 3:
                if (head != NULL) {
                    print_head(head);
                    break;
                } else {
                    printf("ERR_CANNOT_QUERY\n");
                    break;
                }

            case 4:
                count_head(head);
        }

    }

    return 0;
}
