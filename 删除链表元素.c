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

struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    
    while (curr != NULL) {
    	
        if (curr->val == val) {

            prev->next = curr->next;
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        } else {

            prev = curr;
            curr = curr->next;
        }
    }

    struct ListNode* newHead = dummy->next;
    free(dummy);
    return newHead;
}

// 主函数 - 测试removeElements函数
int main() {
    // 测试用例1: {1,1,4,5,1,4}, 删除4
    int arr1[] = {1, 1, 4, 5, 1, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int val1 = 4;
    
    printf("测试用例1:\n");
    struct ListNode* list1 = createListFromArray(arr1, size1);
    printf("原始链表: ");
    printList(list1);
    printf("要删除的值: %d\n", val1);
    
    struct ListNode* result1 = removeElements(list1, val1);
    printf("删除后链表: ");
    printList(result1);
    
    // 测试用例2: {1,2,3,4,5}, 删除1
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int val2 = 1;
    
    printf("\n测试用例2:\n");
    struct ListNode* list2 = createListFromArray(arr2, size2);
    printf("原始链表: ");
    printList(list2);
    printf("要删除的值: %d\n", val2);
    
    struct ListNode* result2 = removeElements(list2, val2);
    printf("删除后链表: ");
    printList(result2);
    
    // 测试用例3: {2,2,2,2}, 删除2
    int arr3[] = {2, 2, 2, 2};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    int val3 = 2;
    
    printf("\n测试用例3:\n");
    struct ListNode* list3 = createListFromArray(arr3, size3);
    printf("原始链表: ");
    printList(list3);
    printf("要删除的值: %d\n", val3);
    
    struct ListNode* result3 = removeElements(list3, val3);
    printf("删除后链表: ");
    printList(result3);
    
    // 测试用例4: 空链表
    int val4 = 1;
    
    printf("\n测试用例4:\n");
    struct ListNode* list4 = NULL;
    printf("原始链表: ");
    printList(list4);
    printf("要删除的值: %d\n", val4);
    
    struct ListNode* result4 = removeElements(list4, val4);
    printf("删除后链表: ");
    printList(result4);
    
    // 测试用例5: {1,2,3}, 删除4（不存在的值）
    int arr5[] = {1, 2, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    int val5 = 4;
    
    printf("\n测试用例5:\n");
    struct ListNode* list5 = createListFromArray(arr5, size5);
    printf("原始链表: ");
    printList(list5);
    printf("要删除的值: %d\n", val5);
    
    struct ListNode* result5 = removeElements(list5, val5);
    printf("删除后链表: ");
    printList(result5);
    
    // 测试用例6: 删除中间连续的值
    int arr6[] = {1, 2, 2, 3, 2, 4, 2};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    int val6 = 2;
    
    printf("\n测试用例6:\n");
    struct ListNode* list6 = createListFromArray(arr6, size6);
    printf("原始链表: ");
    printList(list6);
    printf("要删除的值: %d\n", val6);
    
    struct ListNode* result6 = removeElements(list6, val6);
    printf("删除后链表: ");
    printList(result6);
    
    // 清理内存
    freeList(result1);
    freeList(result2);
    freeList(result3);
    freeList(result4);
    freeList(result5);
    freeList(result6);
    
    return 0;
}
