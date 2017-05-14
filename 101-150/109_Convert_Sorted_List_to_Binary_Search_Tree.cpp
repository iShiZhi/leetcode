class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int len = 0;
		ListNode* current = head;
		while (current != NULL) {
			current = current->next;
			len++;
		}
		return build(head, len);
	}

	TreeNode* build(ListNode* head, int len) {
		if (head == NULL) return NULL;
		if (head->next == NULL) {
			return new TreeNode(head->val);
		}
		int index = len / 2;
		ListNode* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		TreeNode* root = new TreeNode(current->val);
		if (index != 0) {
			root->left = build(head, index);
		}

		if (index != len - 1) {
			root->right = build(current->next, len - index - 1);
		}

		return root;
	}
};