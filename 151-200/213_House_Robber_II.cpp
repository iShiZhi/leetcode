class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else {
            int* dp = new int[n + 1];  
            
            dp[0] = nums[0];    
            for (int i = 1; i < n-1 ; ++i){  
                dp[i] = max(dp[i - 1], (i == 1 ? 0: dp[i - 2]) + nums[i]);  
            }  
            int res1=dp[n-2];  

            dp[1] = nums[1];  
            for (int i = 2; i < n ; ++i){  
                dp[i] = max(dp[i - 1], (i == 2 ? 0 : dp[i - 2]) + nums[i]);  
            }  
            int res2 = dp[n - 1];  
        
            return max(res1, res2);
        }
    }
};