/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL; 
    struct ListNode* temp = NULL;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // if even, then move slow to the other halfs first node
    if (fast) {
        slow = slow->next;
    }

    while (slow) {
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    fast = head;
    slow = prev;

    while (slow) {
        if (fast->val != slow->val) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }

    return true;
}