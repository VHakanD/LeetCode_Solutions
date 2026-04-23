/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp = head;
    int count=1, i=0;
    int mid;

    while(temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    mid= (count/2);

    while(i<mid)
    {
        head = head->next;
        i++;
    }
    return head;
}