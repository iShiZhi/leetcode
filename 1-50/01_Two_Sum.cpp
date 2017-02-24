class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> existResult;
        
        for (int i = 0; i < nums.size(); i ++) {
            if (existResult.find(nums[i]) != existResult.end()) {
                result.push_back(existResult.at(nums[i]));
                result.push_back(i);
                break;
            }
            
            existResult[target - nums[i]] = i;
        }
        
        return result;
    }
};