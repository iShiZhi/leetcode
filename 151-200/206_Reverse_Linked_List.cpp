/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        
        ListNode* newHead = head;
        ListNode* current = head->next;
        head->next = NULL;
        while (current != NULL) {
            ListNode* tmp = current->next;
            current->next = newHead;
            newHead = current;
            current = tmp;
        }
        
        return newHead;
    }
};