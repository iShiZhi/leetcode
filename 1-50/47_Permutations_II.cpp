class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<vector<int>> tmpResult;
        
        int head = 0;
        vector<int> first;
        tmpResult.push_back(first);
        while (head < tmpResult.size()) {
            for (int i = 0; i < nums.size(); i ++) {
                bool flag = true;
                for (int j = 0; j < tmpResult[head].size(); j ++) {
                    if (tmpResult[head][j] == i) {
                        flag = false;
                        break;
                    }
                }
                
                if (flag) {
                    vector<int> tmp;
                    
                    if (tmpResult[head].size() < nums.size() - 1) {
                        tmp.assign(tmpResult[head].begin(), tmpResult[head].end());
                        tmp.push_back(i);
                    
                        bool exist = false;
                        for (int j = 0; j < tmpResult.size(); j++) {
                            if (tmpResult[j].size() != tmp.size()) continue;
                            bool equal = true;
                            for (int k = 0; k < tmpResult[j].size(); k++) {
                                if (nums[tmpResult[j][k]] != nums[tmp[k]]) {
                                    equal = false;
                                    break;
                                }
                            }
                            if (equal) {
                                exist = true;
                                break;
                            }
                        }
                        
                        if (!exist) {
                            tmpResult.push_back(tmp);
                        }
                    } else {
                        for (int j = 0; j < tmpResult[head].size(); j++) {
                            tmp.push_back(nums[tmpResult[head][j]]);
                        }
                        tmp.push_back(nums[i]);
                        
                        bool exist = false;
                        for (int j = 0; j < result.size(); j++) {
                            bool equal = true;
                            for (int k = 0; k < result[j].size(); k++) {
                                if (result[j][k] != tmp[k]) {
                                    equal = false;
                                    break;
                                }
                            }
                            if (equal) {
                                exist = true;
                                break;
                            }
                        }
                        
                        if (!exist) {
                            result.push_back(tmp);
                        }
                    }
                }
            }
            
            head++;
        }
        
        return result;
    }
};