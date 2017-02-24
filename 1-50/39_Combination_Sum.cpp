class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<vector<int>> tmpResult;
        
        int head = 0;
        vector<int> tmp;
        tmp.push_back(0);
        tmpResult.push_back(tmp);
        while (head < tmpResult.size()) {
            for (int i = 0; i < candidates.size(); i++) {
                if ((tmpResult[head].size() == 1 || tmpResult[head].back() <= candidates[i]) && tmpResult[head][0] + candidates[i] <= target) {
                    vector<int> tmp;
                    tmp.assign(tmpResult[head].begin(), tmpResult[head].end());
                    tmp[0] += candidates[i];
                    tmp.push_back(candidates[i]);
                    if (tmp[0] < target) {
                        tmpResult.push_back(tmp);
                    } else if (tmp[0] == target) {
                        tmp.erase(tmp.begin());
                        result.push_back(tmp);
                    }
                }
            }
            
            head++;
        }
        
        return result;
    }
};