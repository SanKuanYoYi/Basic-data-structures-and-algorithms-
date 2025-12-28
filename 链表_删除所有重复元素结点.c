/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* cur = dummy;
    while (cur->next != NULL && cur->next->next != NULL) {
        int check = cur->next->val;
        if (check == cur->next->next->val) {
            while (cur->next != NULL && cur->next->val == check) {
                struct ListNode* temp = cur->next;
                cur->next = cur->next->next;
                free(temp);
            }
        } else {
            cur = cur->next;
        }
    }

    struct ListNode* ansHead = dummy->next;
    free(dummy);

    return ansHead;
}
