/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* pre = dummy;
    struct ListNode* cur = head;
    while (cur != NULL) {
        if (cur->val == val) {
            struct ListNode* del = cur;
            pre->next = cur->next;
            cur = cur->next;
            free(del);
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

    struct ListNode* ansHead = dummy->next;
    free(dummy);

    return ansHead;
}

