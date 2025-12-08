#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* createListFromArray(int arr[], int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    printf("{");
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(",");
        }
        current = current->next;
    }
    printf("}\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

struct ListNode* swapPairs(struct ListNode* head) {

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    
    while (prev->next != NULL && prev->next->next != NULL) {

        struct ListNode* node1 = prev->next;
        struct ListNode* node2 = prev->next->next;

        prev->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        prev = node1;
    }
    
    return dummy.next;
}

int main() {

    int arr1[] = {7, 0, 1, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("测试用例1:\n");
    struct ListNode* list1 = createListFromArray(arr1, size1);
    printf("原始链表: ");
    printList(list1);
    
    struct ListNode* result1 = swapPairs(list1);
    printf("交换后链表: ");
    printList(result1);

    printf("\n测试用例2:\n");
    struct ListNode* list2 = NULL;
    printf("原始链表: ");
    printList(list2);
    
    struct ListNode* result2 = swapPairs(list2);
    printf("交换后链表: ");
    printList(result2);

    int arr3[] = {5};
    int size3 = 1;
    
    printf("\n测试用例3:\n");
    struct ListNode* list3 = createListFromArray(arr3, size3);
    printf("原始链表: ");
    printList(list3);
    
    struct ListNode* result3 = swapPairs(list3);
    printf("交换后链表: ");
    printList(result3);

    int arr4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    
    printf("\n测试用例4:\n");
    struct ListNode* list4 = createListFromArray(arr4, size4);
    printf("原始链表: ");
    printList(list4);
    
    struct ListNode* result4 = swapPairs(list4);
    printf("交换后链表: ");
    printList(result4);

    int arr5[] = {10, 20};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    
    printf("\n测试用例5:\n");
    struct ListNode* list5 = createListFromArray(arr5, size5);
    printf("原始链表: ");
    printList(list5);
    
    struct ListNode* result5 = swapPairs(list5);
    printf("交换后链表: ");
    printList(result5);

    freeList(result1);
    freeList(result2);
    freeList(result3);
    freeList(result4);
    freeList(result5);
    
    return 0;
}
