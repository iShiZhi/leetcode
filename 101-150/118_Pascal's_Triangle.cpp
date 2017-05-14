class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 1; i <= numRows; i++) {
            vector<int> curRow;
            curRow.push_back(1);
            for (int j = 1; j < i - 1; j++) {
                curRow.push_back(result.back()[j - 1] + result.back()[j]);
            }
            if (i != 1) curRow.push_back(1);
            result.push_back(curRow);
        }
        
        return result;
    }
};