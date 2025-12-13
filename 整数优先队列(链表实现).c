#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} ListNode;

ListNode* creat(int x) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void insert(ListNode** head, int x) {
    ListNode* newNode = creat(x);
    newNode->next = *head;
    *head = newNode;
}

int findMin(ListNode* head) {
    if (head == NULL) {
        return 0;
    }

    ListNode* temp = head;
    int min = temp->data;

    while (temp != NULL) {
        if (temp->data < min) {
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

void deleteMin(ListNode** head) {
    if (*head == NULL) {
        return;
    }

    ListNode* temp = *head;
    int min = temp->data;
    ListNode* minPrev = NULL;
    ListNode* minNode = temp;

    while (temp->next != NULL) {
        if (temp->next->data < min) {
            min = temp->next->data;
            minPrev = temp;
            minNode = temp->next;
        }
        temp = temp->next;
    }

    if (minPrev == NULL) {
        *head = minNode->next;
    } else {
        minPrev->next = minNode->next;
    }
    free(minNode);
}

int main() {
    int n;
    scanf("%d", &n);

    ListNode* head = NULL;

    for (int i = 0; i < n; i++) {
        int op;
        scanf("%d", &op);

        switch (op) {
            case 1: {
                    int x;
                    scanf("%d", &x);
                    insert(&head, x);
                    break;
                }

            case 2: {
                    printf("%d\n", findMin(head));
                    break;
                }

            case 3: {
                    deleteMin(&head);
                    break;
                }
        }
    }

    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
