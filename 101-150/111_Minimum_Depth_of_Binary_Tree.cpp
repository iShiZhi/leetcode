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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int result = INT_MAX;
        traverse(root, result, 1);
        return result;
    }
    
    void traverse(TreeNode* root, int& result, int curDepth) {
        if (root->left == NULL && root->right == NULL && curDepth < result) {
            result = curDepth;
        }
        
        if (root->left != NULL) {
            traverse(root->left, result, curDepth + 1);
        }
        
        if (root->right != NULL) {
            traverse(root->right, result, curDepth + 1);
        }
    }
};