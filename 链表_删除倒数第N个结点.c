/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

   int len = 0;
   struct ListNode* p = head;
   while (p != NULL) {
       len++;
       p = p->next;
   }

   if (len == 0 || n > len) {
       return head;
   }

   if (n == len) {
       struct ListNode* newHead = head->next;
       free(head);
       return newHead;
   }

   struct ListNode* t = head;
   for (int i = 0; i < len - n - 1; i++) {
       t = t->next;
   }

   struct ListNode* target = t->next;
   if (target != NULL) {
       t->next = target->next;
       free(target);
   }

   return head;
}
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;

    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    struct ListNode* target = slow->next;
    slow->next = slow->next->next;
    free(target);

    struct ListNode* ansHead = dummy->next;
    free(dummy);

    return ansHead;
}
