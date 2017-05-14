class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> availableNums;
        for (int i = 0; i < nums.size(); i++) {
            availableNums.insert(nums[i]);
        }
        
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            int asc = 0;
            int tmpNum = nums[i];
            while (availableNums.find(tmpNum) != availableNums.end()) {
                availableNums.erase(tmpNum);
                asc++;
                tmpNum++;
            }
            
            int desc = 0;
            tmpNum = nums[i] - 1;
            while (availableNums.find(tmpNum) != availableNums.end()) {
                availableNums.erase(tmpNum);
                desc++;
                tmpNum--;
            }
            
            if (asc + desc > result) result = asc + desc;
        }
        
        return result;
    }
};