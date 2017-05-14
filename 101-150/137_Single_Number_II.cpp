class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int i = 0; i < 32; i++) {
            int digit = 0;
            for (int j = 0; j < nums.size(); j++) {
                digit += (nums[j] >> i) & 1;
            }
            result += (digit % 3) << i;
        }
        
        return result;
    }
};