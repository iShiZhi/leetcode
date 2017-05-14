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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        
        ListNode *normal = head;
        ListNode *fast = head;
        
        while (true) {
            if (normal->next == NULL) {
                return false;
            } else {
                normal = normal->next;
            }
            
            if (fast->next == NULL || fast->next->next == NULL) {
                return false;
            } else {
                fast = fast->next->next;
            }
            
            if (fast == normal) {
                return true;
            }
        }
    }
};