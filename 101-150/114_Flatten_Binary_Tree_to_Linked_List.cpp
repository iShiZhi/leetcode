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
private:
    TreeNode* prev = NULL;
    
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        traverse(root);
    }
    
    void traverse(TreeNode* current) {
        prev = current;
        if (current->left != NULL) {
            traverse(current->left);
        }
        
        prev->right = current->right;
        if (prev->right != NULL) {
            traverse(prev->right);
        }
        
        if (current->left != NULL) {
            current->right = current->left;
            current->left = NULL;
        }
    }
};