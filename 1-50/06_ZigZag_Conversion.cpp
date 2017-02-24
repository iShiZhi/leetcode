class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs;
        
        for (int i = 0; i < numRows; i++) {
            strs.push_back("");
        }
        
        int i = 0;
        while (i < s.length()) {
            int j = 0;
            while (j < numRows && i < s.length()) {
                strs[j] += s[i];
                i++;
                j++;
            }
            
            j = numRows - 2;
            while (j > 0 && i < s.length()) {
                strs[j] += s[i];
                i++;
                j--;
            }
        }
        
        string result = "";
        for (int i = 0; i < numRows; i++) {
            result = result + strs[i];
        }
        
        return result;
    }
};