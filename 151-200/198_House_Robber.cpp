class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else {
            vector<int> result(n, 0);
            result[0] = nums[0];
            result[1] = max(nums[0], nums[1]);
            for(int i = 2; i < n; i ++)
                result[i] = max(result[i - 2] + nums[i], result[i - 1]);
            return result[n - 1];
        }
    }
};