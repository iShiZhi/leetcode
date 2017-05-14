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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* newHead = NULL;

		while (head != NULL) {
			if (newHead == NULL) {
				newHead = head;
				head = head->next;
				newHead->next = NULL;
			} else {
				ListNode* current = newHead;
				ListNode* prev = NULL;

				while (current != NULL && current->val < head->val) {
					prev = current;
					current = current->next;
				}

				if (current == NULL) {
					prev->next = head;
					head = head->next;
					prev->next->next = NULL;
				} else if (prev == NULL) {
					newHead = head;
					prev = head->next;
					head->next = current;
					head = prev;
				} else {
					prev->next = head;
					prev = head->next;
					head->next = current;
					head = prev;
				}
			}
		}

		return newHead;
	}
};