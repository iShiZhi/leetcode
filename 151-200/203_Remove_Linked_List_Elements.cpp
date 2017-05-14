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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        
        ListNode* current = head;
        ListNode* newHead = NULL;
        if (head->val != val) {
            newHead = head;
        }
        while (current->next != NULL) {
            if (current->next->val == val) {
                current->next = current->next->next;
            } else {
                if (newHead == NULL) {
                    newHead = current->next;
                }
                
                current = current->next;
            }
        }
        
        return newHead;
    }
};