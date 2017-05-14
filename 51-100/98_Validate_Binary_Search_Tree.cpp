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
    bool isValidBST(TreeNode* root) {
        vector<int> result;
        if (root != NULL) {
            traverse(result, root);
        }
        
        bool flag = true;
        for (int i = 1; i < result.size(); i++) {
            if (result[i] <= result[i - 1]) {
                flag = false;
                break;
            }
        }
        
        return flag;
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