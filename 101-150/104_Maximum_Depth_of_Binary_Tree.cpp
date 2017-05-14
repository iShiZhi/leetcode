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
    int maxDepth(TreeNode* root) {
        int result = 0;
        
        if (root == NULL) {
            return result;
        }
        
        traverse(root, result, 1);
        return result;
    }
    
    void traverse(TreeNode* root, int& result, int curDepth) {
        if (result < curDepth) {
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