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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        
        ListNode *normal = head;
        ListNode *fast = head;
        
        while (true) {
            if (normal->next == NULL) {
                return NULL;
            } else {
                normal = normal->next;
            }
            
            if (fast->next == NULL || fast->next->next == NULL) {
                return NULL;
            } else {
                fast = fast->next->next;
            }
            
            if (fast == normal) {
                break;
            }
        }
        
        normal = head;
        while (normal != fast) {
            normal = normal->next;
            fast = fast->next;
        }
        
        return normal;
    }
};