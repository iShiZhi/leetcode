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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       ListNode* result = NULL;
       ListNode* current = NULL;
       
       while (l1 != NULL || l2 != NULL) {
           int currentVal = 0;
           
           if (l1 == NULL) {
               currentVal = l2->val;
               l2 = l2->next;
           } else if (l2 == NULL) {
               currentVal = l1->val;
               l1 = l1->next;
           } else if (l1->val < l2->val) {
               currentVal = l1->val;
               l1 = l1->next;
           } else {
               currentVal = l2->val;
               l2 = l2->next;
           }
           
           if (result == NULL) {
               result = new ListNode(currentVal);
               current = result;
           } else {
               current->next = new ListNode(currentVal);
               current = current->next;
           }
       }
       
       return result;
    }
};