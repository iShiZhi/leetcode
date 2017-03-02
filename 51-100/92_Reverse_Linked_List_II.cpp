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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* current = head;
		int index = 1;

		ListNode* prev = NULL;
		if (m > 1) {
			while (index < m - 1) {
				current = current->next;
				index++;
			}
			prev = current;
			current = current->next;
			index++;
		}

		ListNode* newHead = current;
		while (index < n) {
			ListNode* tmp = current->next->next;
			current->next->next = newHead;
			newHead = current->next;
			current->next = tmp;
			index++;
		}

		if (prev == NULL) {
			return newHead;
		} else {
			prev->next = newHead;
			return head;
		}
	}
};