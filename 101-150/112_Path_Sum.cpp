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
    bool found = false;
    
    void traverse(TreeNode* root, int sum, int curSum) {
        if (found) return;
        
        if (root->left == NULL && root->right == NULL && curSum == sum) {
            found = true;
        }
        
        if (root->left != NULL) {
            traverse(root->left, sum, curSum + root->left->val);
        }
        
        if (root->right != NULL) {
            traverse(root->right, sum, curSum + root->right->val);
        }
    }
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        
        traverse(root, sum, root->val);
        return found;
    }
};