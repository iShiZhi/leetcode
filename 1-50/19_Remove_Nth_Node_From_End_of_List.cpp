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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node1 = head;
        ListNode* node2 = head;
        
        int tmp = 0;
        while (node1 != NULL && tmp < n) {
            node1 = node1->next;
            tmp++;
        }
        
        if (tmp < n) return head;
        if (node1 == NULL) {
            return head->next;
        } else {
            node1 = node1->next;
        }
        
        while (node1 != NULL) {
            node1 = node1->next;
            node2 = node2->next;
        }
        
        
        node2->next = node2->next->next;
        
        return head;
    }
};