/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /*
struct ListNode* middleNode(struct ListNode* head) {

    int len = 0;
    struct ListNode* p = head;

    while (p != NULL) {
        len++;
        p = p->next;
    }

    int endPos = len / 2 + 1;
    int currentPos = 1;
    struct ListNode* cur = head;

    while (currentPos < endPos) {

        cur = cur->next;
        currentPos++;
    }

    return cur;
}
*/

struct ListNode* middleNode(struct ListNode* head) {
	
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}
