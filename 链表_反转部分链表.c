/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode ListNode;
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

    struct ListNode* p = head;
    struct ListNode* pre = NULL;
    struct ListNode* sub = NULL;

    int cnt = 0;
    while (p != NULL) {
        cnt++;

        if (cnt == left - 1) {
            pre = p;
        }
        if (cnt == right + 1) {
            sub = p;
        }

        p = p->next;
    }

    p = (pre == NULL) ? head : pre->next;
    p->next = sub;

    struct ListNode* current = p->next;
    struct ListNode* nextNode = NULL;

    while (current != sub) {

        nextNode = current->next;
        current->next = p;
        p = current;
        current = nextNode;
    }

    if (pre != NULL) {
        pre->next = p;
        return head;
    }

    return p;
}
