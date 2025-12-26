/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* reverseKGroup(struct ListNode* head, int k) {

   if (head == NULL || k == 1) {
       return head;
   }

   int sum = 0;
   struct ListNode* p = head;
   while (p != NULL) {
       sum++;
       p = p->next;
   }

   struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
   dummy->next = head;
   struct ListNode* pre = dummy;

   while (sum >= k) {

       struct ListNode* cur = pre->next;
       struct ListNode* end = cur;

       struct ListNode* previous = NULL;
       struct ListNode* next = NULL;

       for (int i = 0; i < k; i++) {
           next = cur->next;
           cur->next = previous;
           previous = cur;
           cur = next;
       }

       pre->next = previous;
       end->next = cur;

       pre = end;
       sum -= k;
   }

   struct ListNode* newHead = dummy->next;
   free(dummy);

   return newHead;
}
*/

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) {
        return head;
    }

    int sum = 0;
    struct ListNode* p = head;
    while (p != NULL) {
        sum++;
        p = p->next;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode* pre = dummy; // 上一组的尾节点
    struct ListNode* cur = head;  // 当前组的第一个节点

    while (sum >= k) {
        struct ListNode* group_end = cur;
        for (int i = 1; i < k; i++) {
            group_end = group_end->next;
        }

        // 记录下一组的头节点
        struct ListNode* next_group = group_end->next;

        struct ListNode* prev = NULL;
        struct ListNode* current = cur;
        struct ListNode* next = NULL;

        for (int i = 0; i < k; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        pre->next = prev;       // 上一组连接到当前组的新头节点
        cur->next = next_group; // 当前组的新尾节点连接到下一组

        pre = cur;        // pre指向当前组的新尾节点
        cur = next_group; // cur指向下一组的第一个节点
        sum -= k;         // 减少剩余节点数
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}
