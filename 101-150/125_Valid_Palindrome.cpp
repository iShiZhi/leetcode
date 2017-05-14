class Solution {
public:
    bool isAlphanumeric(const char c) {
        if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9') {
            return true;
        } else {
            return false;
        }
    }
    
    char toLower(const char c) {
        if ('A' <= c && c <= 'Z')
            return 'a' + c - 'A';
        return c;
    }
    
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
            
        int begin = 0;
        int end = s.size() - 1;
        while (true) {
            while (begin < s.size() && !isAlphanumeric(s[begin])) {
                begin++;
            }
            while (end >= 0 && !isAlphanumeric(s[end])) {
                end--;
            }
            if (end <= begin) return true;
            if (toLower(s[begin]) != toLower(s[end])) return false;
            begin++;
            end--;
        }
    }

};