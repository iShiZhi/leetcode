class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        
        if (n == 0) {
            result.push_back(0);
            return result;
        }
        
        result.push_back(0);
        result.push_back(1);
        
        for (int i = 2; i <= n; i++) {
            int bits = 1;
            for (int j = 0; j < i - 1; j++) {
                bits <<= 1;
            }
            for (int j = result.size() - 1; j >= 0; j--) {
                result.push_back(result[j] + bits);
            }
        }
        
        return result;
    }
};