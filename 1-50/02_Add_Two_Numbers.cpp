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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* current = NULL;
        
        int tmp = 0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                tmp = tmp + l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                tmp = tmp + l2->val;
                l2 = l2->next;
            }
            
            if (result == NULL) {
                result = new ListNode(tmp % 10);
                current = result;
            } else {
                current->next = new ListNode(tmp % 10);
                current = current->next;
            }
            tmp = tmp / 10;
        }
        
        if (tmp > 0) {
            current->next = new ListNode(tmp % 10);
        }
        
        return result;
    }
};