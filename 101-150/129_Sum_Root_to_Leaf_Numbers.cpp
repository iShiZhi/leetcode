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
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        
        long long result = 0;
        traverse(root, root->val, result);
        return result;
    }
    
    void traverse(TreeNode* root, long long digit, long long & result) {
        if (root->left == NULL && root->right == NULL) {
            result += digit;
        }
        
        if (root->left != NULL) traverse(root->left, digit * 10 + root->left->val, result);
        if (root->right != NULL) traverse(root->right, digit * 10 + root->right->val, result);
    }
};