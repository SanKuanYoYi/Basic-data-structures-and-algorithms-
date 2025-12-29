/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {

    struct ListNode* stack = NULL;
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;

    while (cur != NULL) {
        next = cur->next;

        while (stack != NULL && stack->val < cur->val) {
            pre = stack;
            stack = stack->next;
            free(pre);
        }

        cur->next = stack;
        stack = cur;
        cur = next;
    }

    pre = NULL;
    while (stack != NULL) {
        next = stack->next;
        stack->next = pre;
        pre = stack;
        stack = next;
    }

    return pre;
}
