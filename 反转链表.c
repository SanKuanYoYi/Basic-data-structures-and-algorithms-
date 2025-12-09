
struct ListNode* ReverseList(struct ListNode* head ) {

    if (head == NULL) {
        return head;
    }

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {

        struct ListNode* next;

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;

}


