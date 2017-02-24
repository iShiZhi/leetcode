class Solution {
public:
    static const string map[10];
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() > 0) {
            vector<string> tmp = letterCombinations(digits.substr(1, digits.length() - 1));
            if (tmp.size() == 0) {
                tmp.push_back("");
            }
            for (int i = 0; i < map[digits[0] - '0'].length(); i++) {
                for (int j = 0; j < tmp.size(); j++) {
                    ans.push_back(map[digits[0] - '0'][i] + tmp[j]);
                }
            }
        }
        return ans;
    }
};

const string Solution::map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};