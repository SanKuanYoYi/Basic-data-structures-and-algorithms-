/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {

    if (head == NULL) {
        return NULL;
    }

    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while (cur != NULL) {

        struct ListNode* temp = cur->next;

        cur -> next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

