class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int moveForward = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == val) {
                moveForward++;
            } else {
                nums[i - moveForward] = nums[i];
            }
        }
        
        return size - moveForward;
    }
};