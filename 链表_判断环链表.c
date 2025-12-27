/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {

    struct ListNode* fastNode = head;
    struct ListNode* slowNode = head;

    while (fastNode != NULL && fastNode->next != NULL) {

        slowNode = slowNode->next;
        fastNode = fastNode->next->next;

        if (slowNode == fastNode) {
            return true;
        }
    }

    return false;
}
