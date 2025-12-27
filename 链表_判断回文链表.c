/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {

    int len = 0;
    struct ListNode* p = head;
    while (p != NULL) {
        len++;
        p = p->next;
    }

    int* stack = (int*)malloc((len / 2) * sizeof(int));
    int top = -1;

    int isOdd = 0;
    if (len % 2 == 1) {
        isOdd = 1;
    }

    struct ListNode* t = head;
    int endTimes = len / 2;
    for (int i = 0; i < endTimes; i++) {
        stack[++top] = t->val;
        t = t->next;
    }

    if (isOdd) {
        t = t->next;
    }

    while (top >= 0) {
        if (stack[top--] != t->val) {
            free(stack);
            return false;
        }
        t = t->next;
    }

    free(stack);
    return true;
}
