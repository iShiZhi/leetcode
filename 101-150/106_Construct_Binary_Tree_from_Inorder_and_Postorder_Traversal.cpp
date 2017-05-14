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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inHead, int inTail, int postHead, int postTail) {
        TreeNode* root = new TreeNode(postorder[postTail]);
        if (inHead < inTail) {
            int index = inHead;
            while (index <= inTail && inorder[index] != postorder[postTail]) {
                index++;
            }
            
            int len = index - inHead;
            if (index != inHead) {
                root->left = build(inorder, postorder, inHead, inHead + len - 1, postHead, postHead + len - 1);
            }
            if (index != inTail) {
                root->right = build(inorder, postorder, inHead + len + 1, inTail, postHead + len, postTail - 1);
            }
        }
        return root;
    }
};