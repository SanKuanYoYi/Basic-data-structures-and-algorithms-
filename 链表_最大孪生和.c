/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* findMid(struct ListNode* head) {

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

struct ListNode* reverse(struct ListNode* head) {

    struct ListNode* pre = NULL;
    struct ListNode* cur = head;

    while (cur != NULL) {
        struct ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

int pairSum(struct ListNode* head) {

    struct ListNode* mid = findMid(head);
    struct ListNode* revHead = reverse(mid);

    int max = 0;

    struct ListNode* p = head;
    while (p != mid) {
        int sum = 0;
        sum = p->val + revHead->val;

        if (sum > max) {
            max = sum;
        }

        p = p->next;
        revHead = revHead->next;
    }

    return max;
}
