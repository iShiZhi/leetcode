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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;

		ListNode* prev = NULL;
		ListNode* current = head;
		bool removeCurrent = false;
		while (current->next != NULL) {
			if (current->val == current->next->val) {
				current->next = current->next->next;
				removeCurrent = true;
			} else if (removeCurrent) {
				current = current->next;
				removeCurrent = false;
			} else if (prev == NULL) {
				prev = current;
				head = current;
				current = current->next;
			} else {
				prev->next = current;
				prev = prev->next;
				current = current->next;
			}
		}

        if (prev == NULL) head = NULL;

		if (prev != NULL && removeCurrent) {
			prev->next = NULL;
		} else if (current != NULL && !removeCurrent) {
		    if (prev == NULL) {
		        head = current;
		    } else {
		        prev->next = current;
		    }
		}

		return head;
	}
};