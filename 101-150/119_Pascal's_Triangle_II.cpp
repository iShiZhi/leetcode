class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        
        result.push_back(1);
        int prev = 1;
        for (int i = 1; i <= rowIndex; i++) {
            prev = 1;
            for (int j = 1; j < i; j++) {
                result[j] = prev + result[j];
                prev = result[j] - prev;
            }
            result.push_back(1);
        }
        
        return result;
    }
};