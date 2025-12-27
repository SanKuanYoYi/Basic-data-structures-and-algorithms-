/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {

    if (head == NULL) {
        return false;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            fast = head;

            while (1) {

                if (fast == slow) {
                    return fast;
                }

                fast = fast->next;
                slow = slow->next;
            }
        }
    }

    return NULL;
}
