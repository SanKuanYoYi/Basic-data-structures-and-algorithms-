/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));

    dummy->next = head;
    dummy->val = 0;

    struct ListNode* pre = dummy;
    struct ListNode* cur = head;

    while (cur) {

        int doubleVal = 2 * cur->val;
        if (doubleVal >= 10) {
            pre->val++;
        }

        cur->val = doubleVal % 10;
        pre = cur;
        cur = cur->next;
    }
    if (dummy->val == 1)
        return dummy;
    else {
        return dummy->next;
    }
}

