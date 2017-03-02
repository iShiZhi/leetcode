/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != NULL) {
            traverse(result, root);
        }

        return result;
    }

    void traverse(vector<int>& result, TreeNode* node) {
        if (node->left != NULL) {
            traverse(result, node->left);
        }
        result.push_back(node->val);
        if (node->right != NULL) {
            traverse(result, node->right);
        }
    }
};