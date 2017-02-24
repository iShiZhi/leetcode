class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        
        stack<char> parentheses;
        for (int i = 0; i < s.length(); i ++) {
            if (parentheses.size() > 0) {
                if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                    if (s[i] == ')' && parentheses.top() == '(' ||
                        s[i] == ']' && parentheses.top() == '[' ||
                        s[i] == '}' && parentheses.top() == '{') {
                        parentheses.pop();
                    } else {
                        result = false;
                        break;
                    }
                } else if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    parentheses.push(s[i]);
                }
            } else {
                parentheses.push(s[i]);
            }
        }
        
        if (parentheses.size() > 0) {
            result = false;
        }
        
        return result;
    }
};