class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int head = 0;
        int tail = 0;
        int sum = nums[0];
        int result = INT_MAX;
        while (head <= tail && tail < nums.size()) {
            if (sum >= s) {
                if (tail - head + 1 < result) {
                    result = tail - head + 1;
                }
                
                if (head < tail) {
                    sum -= nums[head];
                    head++;
                    continue;
                }
            }
            
            tail++;
            if (tail < nums.size()) {
                sum += nums[tail];
            }
        }
        
        if (result == INT_MAX) result = 0;
        
        return result;
    }
};