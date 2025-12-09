/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param arr int整型一维数组
 * @param arrLen int arr数组长度
 * @return ListNode类
 */
#include <stdio.h>
struct ListNode* vectorToListnode(int* arr, int arrLen ) {
    // write code here
    if (arrLen == 0) {
        return NULL;
    }

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;

    struct ListNode* temp = head;

    for (int i = 1; i < arrLen; i++) {

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->val = arr[i];
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;

    }
    return head;
}
