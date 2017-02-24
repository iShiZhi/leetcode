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
	ListNode* reverse(ListNode* head) {
		ListNode* current = head;
		ListNode* next;
		while (current->next != NULL) {
			next = current->next;
			current->next = next->next;
			next->next = head;
			head = next;
		}

		return current;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* prev = NULL;
		ListNode* newHead = head;
		while (newHead != NULL) {
			ListNode* tmpNode = newHead;
			int tmp = 1;
			while (tmpNode != NULL && tmp < k) {
				tmpNode = tmpNode->next;
				tmp++;
			}
			if (tmp < k || tmpNode == NULL) break;

			ListNode* next = tmpNode->next;
			tmpNode->next = NULL;
			ListNode* newTail = reverse(newHead);
			if (prev == NULL) {
				head = tmpNode;
			} else {
				prev->next = tmpNode;
			}

			newTail->next = next;
			prev = newTail;
			newHead = prev->next;
		}

		return head;
	}
};