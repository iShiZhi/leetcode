class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;

		if (head->next->next == NULL) {
			if (head->val > head->next->val) {
				int tmp = head->val;
				head->val = head->next->val;
				head->next->val = tmp;
			}

			return head;
		}

		int len = 0;
		ListNode* current = head;
		while (current != NULL) {
			len++;
			current = current->next;
		}

		ListNode* mid = head;
		int index = 0;
		while (index < len / 2) {
			index++;
			mid = mid->next;
		}

		ListNode* left = head;
		ListNode* leftHead = head;
		ListNode* right = mid->next;
		ListNode* rightHead = mid->next;

		ListNode* leftPrev = NULL;
		ListNode* rightPrev = NULL;
		while (left != mid || right != NULL) {
			while (left != mid && left->val <= mid->val) {
				leftPrev = left;
				left = left->next;
			}
			while (right != NULL && right->val >= mid->val) {
				rightPrev = right;
				right = right->next;
			}

			if (left != mid && right != NULL) {
				int tmp = left->val;
				left->val = right->val;
				right->val = tmp;
			} else if (left != mid) {
				if (left == leftHead) {
					leftHead = leftHead->next;
				}
				ListNode* tmp = rightHead->next;
				rightHead->next = left;
				if (leftPrev != NULL) leftPrev->next = left->next;
				left = left->next;
				rightHead->next->next = tmp;
			} else if (right != NULL) {
				if (right == rightHead) {
					rightHead = rightHead->next;
				}
				ListNode* tmp = leftHead->next;
				leftHead->next = right;
				if (rightPrev != NULL) rightPrev->next = right->next;
				right = right->next;
				leftHead->next->next = tmp;
			}
		}

		if (leftHead == mid) {
			leftHead = NULL;
		} else {
			left = leftHead;
			while (left->next != mid) left = left->next;
			left->next = NULL;
		}

		left->next = NULL;
		leftHead = sortList(leftHead);
		rightHead = sortList(rightHead);
		ListNode* newHead = leftHead;
		if (leftHead != NULL) {
			while (leftHead->next != NULL) leftHead = leftHead->next;
			leftHead->next = mid;
		} else {
			newHead = mid;
		}

		mid->next = rightHead;

		return newHead;
	}
};