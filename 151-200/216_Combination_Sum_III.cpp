class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (n > 55 || k > 9 || n < 1 || k < 1) return result;
        
        vector<int> nums;
        traverse(k, n, nums, result);
        return result;
    }
    
    void traverse(int k, int n, vector<int>& nums, vector<vector<int>>& result) {
        if (nums.size() == k) {
            if (n == 0) {
                vector<int> cur;
                cur.assign(nums.begin(), nums.end());
                result.push_back(cur);
            }
        } else if (nums.size() < k) {
            int start = 1;
            if (nums.size() > 0) start = nums.back() + 1;
            for (int i = start; i <= 9; i++) {
                if (n - i >= 0) {
                    nums.push_back(i);
                    traverse(k, n - i, nums, result);
                    nums.erase(nums.end() - 1);
                }
            }
        }
    }
};