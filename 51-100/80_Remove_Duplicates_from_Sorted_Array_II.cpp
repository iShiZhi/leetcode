class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        
        int len = 1;
        bool dup = false;
        int index = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[index]) {
                len++;
                dup = false;
                index++;
                nums[index] = nums[i];
            } else if (!dup) {
                len++;
                dup = true;
                index++;
                nums[index] = nums[i];
            }
        }
        
        return len;
    }
};