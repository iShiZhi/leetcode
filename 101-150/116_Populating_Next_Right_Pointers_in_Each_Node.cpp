/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        
        map<int, TreeLinkNode*> nodes;
        traverse(root, 1, nodes);
    }
    
    void traverse(TreeLinkNode* root, int curDepth, map<int, TreeLinkNode*>& nodes) {
        if (nodes.find(curDepth) != nodes.end()) {
            nodes[curDepth]->next = root;
        }
        nodes[curDepth] = root;
        
        if (root->left != NULL) {
            traverse(root->left, curDepth + 1, nodes);
        }
        
        if (root->right != NULL) {
            traverse(root->right, curDepth + 1, nodes);
        }
    }
};