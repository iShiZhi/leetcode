class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        if (strs.size() == 0) {
            return "";
        }
        
        int pos = 0;
        while (true) {
            if (strs[0].length() <= pos) break;
            
            char ch = strs[0][pos];
            bool same = true;
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].length() <= pos || strs[i][pos] != ch) {
                    same = false;
                    break;
                }
            }
            
            if (!same) break;
            
            result = result + ch;
            pos++;
        }
        
        return result;
    }
};