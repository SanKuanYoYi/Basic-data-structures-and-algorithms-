/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    if (list1 == NULL)
        return list2;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = list1;

    struct ListNode* pre = dummy;
    for (int i = 0; i < a; i++) {
        pre = pre->next;
    }

    struct ListNode* next = pre;
    int distance = b - a + 1;
    for (int i = 0; i < distance + 1; i++) {
        next = next->next;
    }

    struct ListNode* list2_tail = list2;
    if (list2_tail != NULL) {
        while (list2_tail->next != NULL) {
            list2_tail = list2_tail->next;
        }
    }

    struct ListNode* to_delete = pre->next;
    pre->next = list2;

    if (list2_tail != NULL) {
        list2_tail->next = next;
    } else {
        pre->next = next;
    }

    struct ListNode* temp = NULL;
    while (to_delete != next) {
        temp = to_delete;
        to_delete = to_delete->next;
        free(temp);
    }

    struct ListNode* result = dummy->next;
    free(dummy);

    return result;
}
