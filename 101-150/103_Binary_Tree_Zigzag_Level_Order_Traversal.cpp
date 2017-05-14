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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        
        int maxDepth = 0;
        map<int, vector<int>> nodes;
        traverse(root, 1, nodes, maxDepth);
        for (int i = 1; i <= maxDepth; i++) {
            if (i % 2 == 0) {
                reverse(nodes[i].begin(), nodes[i].end());
            }
            
            result.push_back(nodes.at(i));
        }
        
        return result;
    }
    
    void traverse(TreeNode* root, int curDepth, map<int, vector<int>>& nodes, int& maxDepth) {
        if (curDepth > maxDepth) {
            maxDepth = curDepth;
        }
        
        if (nodes.find(curDepth) == nodes.end()) {
            vector<int> curNode;
            nodes[curDepth] = curNode;
        }
        
        nodes[curDepth].push_back(root->val);
        
        if (root->left != NULL) {
            traverse(root->left, curDepth + 1, nodes, maxDepth);
        }
        
        if (root->right != NULL) {
            traverse(root->right, curDepth + 1, nodes, maxDepth);
        }
    }
};