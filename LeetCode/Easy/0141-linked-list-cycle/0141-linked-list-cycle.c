/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    
    struct ListNode *slow = head;

    while(head != NULL && head->next != NULL) {
        head=head->next->next;
        slow=slow->next;

        if(slow==head) {
            return TRUE;
        }
    }
    return FALSE;
}