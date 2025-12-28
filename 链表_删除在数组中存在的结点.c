/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {

    if (head == NULL)
        return NULL;

    int max = 0;
    struct ListNode* temp = head;
    while (temp) {
        if (temp->val > max)
            max = temp->val;
        temp = temp->next;
    }

    int* check = (int*)calloc(max + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= max) {
            check[nums[i]] = 1;
        }
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* pre = dummy;
    struct ListNode* cur = head;

    while (cur != NULL) {
        if (cur->val <= max && check[cur->val]) {
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
    free(check);

    return ansHead;
}
