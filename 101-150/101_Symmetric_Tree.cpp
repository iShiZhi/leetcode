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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        
        return compare(root->left, root->right);
    }
    
    bool compare(TreeNode* tree1, TreeNode* tree2) {
        bool flag = true;
        if (tree1 == NULL && tree2 == NULL) return true;
        
        if (tree1 == NULL && tree2 != NULL || tree1 != NULL && tree2 == NULL
            || tree1 != NULL && tree2 != NULL && tree1->val != tree2->val) {
            return false;        
        }
        
        flag &= compare(tree1->left, tree2->right);
        flag &= compare(tree1->right, tree2->left);
        
        return flag;
    }
};