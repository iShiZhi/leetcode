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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* current = NULL;
        
        while (true) {
            int currentVal = 0;
            int index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != NULL && (index == -1 || currentVal > lists[i]->val)) {
                    index = i;
                    currentVal = lists[i]->val;
                }
            }
            
            if (index == -1) {
                break;
            } else {
                if (result == NULL) {
                    result = new ListNode(currentVal);
                    current = result;
                } else {
                    current->next = new ListNode(currentVal);
                    current = current->next;
                }
                
                lists[index] = lists[index]->next;
            }
        }
        
        return result;
    }
};