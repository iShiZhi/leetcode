class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<vector<int>> tmpResult;
        
        int head = 0;
        vector<int> tmp;
        tmp.push_back(0);
        tmpResult.push_back(tmp);
        while (head < tmpResult.size()) {
            for (int i = 0; i < candidates.size(); i++) {
                if ((tmpResult[head].size() == 1 || candidates[tmpResult[head].back()] <= candidates[i]) && tmpResult[head][0] + candidates[i] <= target) {
                    bool flag = true;
                    for (int j = 1; j < tmpResult[head].size(); j++) {
                        if (tmpResult[head][j] == i) {
                            flag = false;
                            break;
                        }
                    }
                    
                    if (!flag) continue;
                    
                    vector<int> tmp;
                    if (tmpResult[head][0] + candidates[i] < target) {
                        tmp.assign(tmpResult[head].begin(), tmpResult[head].end());
                        tmp[0] += candidates[i];
                        tmp.push_back(i);
                        tmpResult.push_back(tmp);
                    } else {
                        for (int j = 1; j < tmpResult[head].size(); j++) {
                            tmp.push_back(candidates[tmpResult[head][j]]);
                            
                        }
                        tmp.push_back(candidates[i]);
                        
                        flag = true;
                        for (int j = 0; j < result.size(); j++) {
                            if (result[j].size() != tmp.size()) continue;
                            bool equal = true;
                            for (int k = 0; k < result[j].size(); k++) {
                                if (result[j][k] != tmp[k]) {
                                    equal = false;
                                    break;
                                }
                            }
                            if (equal) {
                                flag = false;
                                break;
                            }
                        }
                        
                        if (flag) result.push_back(tmp);
                    }
                }
            }
            
            head++;
        }
        
        return result;
    }
};