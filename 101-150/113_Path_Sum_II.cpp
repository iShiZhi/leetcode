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
    void traverse(TreeNode* root, int sum, int curSum, vector<int>& vals, vector<vector<int>>& result) {
        if (root->left == NULL && root->right == NULL && curSum == sum) {
            vector<int> tmp;
            tmp.assign(vals.begin(), vals.end());
            result.push_back(tmp);
        }
        
        if (root->left != NULL) {
            vals.push_back(root->left->val);
            traverse(root->left, sum, curSum + root->left->val, vals, result);
            vals.erase(vals.end() - 1);
        }
        
        if (root->right != NULL) {
            vals.push_back(root->right->val);
            traverse(root->right, sum, curSum + root->right->val, vals, result);
            vals.erase(vals.end() - 1);
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        
        vector<int> vals;
        vals.push_back(root->val);
        traverse(root, sum, root->val, vals, result);
        return result;
    }
};