class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> pos;
        
        int result = 0;
        int front = 0;
        int back = 0;
        
        while (back < s.length()) {
            std::map<char,int>::iterator iter = pos.find(s[back]);
            if (iter != pos.end() && iter->second + 1 > front) {
                front = iter->second + 1;
            } 
            pos[s[back]] = back;
            if (result < back - front + 1) {
                result = back - front + 1;
            }
            back++;
        }
        
        return result;
    }
};