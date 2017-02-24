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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode* prev = head;
		ListNode* current = head;
		ListNode* next = head->next;
		current->next = next->next;
		next->next = current;
		head = next;

		prev = head->next;
		current = prev->next;
		while (current != NULL && current->next != NULL) {
			next = current->next;
			current->next = next->next;
			next->next = current;
			prev->next = next;

			prev = current;
			current = current->next;
		}

		return head;
    }
};