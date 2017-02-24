class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
    
    int search(vector<int>& nums, int target, int left, int right) {
        if (right == left) {
            if (nums[left] == target) {
                return left;
            } else if (nums[left] > target) {
                return left;
            } else {
                return left + 1;
            }
        } else {
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                return search(nums, target, mid + 1, right);
            } else {
                return search(nums, target, left, mid);
            }
        }
    }
};