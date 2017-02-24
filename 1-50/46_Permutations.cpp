class Solution {
public:
    vector<vector<int>> permutations;
    set<int> usedIndex;

    vector<vector<int>> permute(vector<int>& nums) {
        permutations.clear();
        usedIndex.clear();
        vector<int> result;
        
        generate(nums, result);
        return permutations;
    }
    
    void generate(vector<int>& nums, vector<int>& result) {
        if (result.size() == nums.size()) {
            vector<int> tmp;
            for (int i = 0; i < nums.size(); i++) {
                tmp.push_back(result[i]);
            }
            permutations.push_back(tmp);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (usedIndex.find(i) == usedIndex.end()) {
                    result.push_back(nums[i]);
                    usedIndex.insert(i);
                    generate(nums, result);
                    result.erase(result.end() - 1);
                    usedIndex.erase(usedIndex.find(i));
                }
            }
        }
    }
};