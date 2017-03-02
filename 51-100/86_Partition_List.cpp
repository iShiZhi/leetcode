class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL) return head;
		ListNode* prev = NULL;

		if (head->val < x) {
			prev = head;
		}

		ListNode* current = head;
		while (current->next != NULL) {
			if (current->next->val < x) {
				if (prev == NULL) {
					ListNode* tmp = current->next->next;
					current->next->next = head;
					head = current->next;
					current->next = tmp;
					prev = head;
				} else if (prev != current) {
					ListNode* tmp = current->next->next;
					current->next->next = prev->next;
					prev->next = current->next;
					current->next = tmp;
					prev = prev->next;
				} else {
					prev = prev->next;
					current = current->next;
				}

			} else {
				current = current->next;
			}
		}

		return head;
	}
};