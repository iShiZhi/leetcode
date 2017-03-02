class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> nums;

        iterate(result, nums, n, k);

        return result;
    }

    void iterate(vector<vector<int>>& result, vector<int>& nums, int n, int k) {
        if (nums.size() == k) {
            vector<int> tmp;
            tmp.assign(nums.begin(), nums.end());
            result.push_back(nums);
        } else {
            for (int i = 1; i <= n; i ++) {
                if (nums.size() == 0 || nums.back() < i) {
                    nums.push_back(i);
                    iterate(result, nums, n, k);
                    nums.erase(nums.end() - 1);
                }
            }
        }
    }
};
