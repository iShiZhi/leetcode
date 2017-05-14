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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* current = NULL;
        if (nums.size() == 0) {
            return current;
        }
        
        if (nums.size() == 1) {
            current = new TreeNode(nums[0]);
            return current;
        }
        
        int mid = nums.size() / 2;
        current = new TreeNode(nums[mid]);
        
        if (mid != 0) {
            vector<int> leftNums;
            for (int i = 0; i < mid; i++) {
				leftNums.push_back(nums[i]);
			}
            current->left = sortedArrayToBST(leftNums);
        } else {
            current->left = NULL;
        }
        
        if (mid != nums.size() - 1) {
            vector<int> rightNums;
            for (int i = mid + 1; i < nums.size(); i++) {
				rightNums.push_back(nums[i]);
			}
            current->right = sortedArrayToBST(rightNums);
        } else {
            current->right = NULL;
        }
        
        return current;
    }
};