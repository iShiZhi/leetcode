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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preHead, int preTail, int inHead, int inTail) {
        TreeNode* root = new TreeNode(preorder[preHead]);
        if (preHead < preTail) {
            int index = inHead;
            while (index <= inTail && inorder[index] != preorder[preHead]) {
                index++;
            }
            
            int len = index - inHead;
            if (index != inHead) {
                root->left = build(preorder, inorder, preHead + 1, preHead + len, inHead, inHead + len - 1);
            }
            if (index != inTail) {
                root->right = build(preorder, inorder, preHead + len + 1, preTail, inHead + len + 1, inTail);
            }
        }
        return root;
    }
};