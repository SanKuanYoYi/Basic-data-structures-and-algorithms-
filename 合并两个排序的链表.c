/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param pHead1 ListNode类
 * @param pHead2 ListNode类
 * @return ListNode类
 */
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2 ) {
    // write code here
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }

    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(
                                   struct ListNode));
    dummyHead->next = NULL;
    struct ListNode* temp = dummyHead;

    struct ListNode* p1 = pHead1;
    struct ListNode* p2 = pHead2;

    while (p1 != NULL && p2 != NULL) {

        if (p1->val <= p2->val) {
            temp->next = p1;
            p1 = p1->next;
        }

        else {
            temp->next = p2;
            p2 = p2->next;
        }

        temp = temp->next;
    }

    if (p1 == NULL) {
        temp->next = p2;
    } else {
        temp->next = p1;
    }

    return dummyHead->next;
}
