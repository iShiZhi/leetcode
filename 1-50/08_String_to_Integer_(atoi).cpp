#include <ctype.h>
#include <limits.h>

class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) {
            return 0;
        }
        
        int start = 0;
        while (start < str.length() && isspace(str[start]) != 0) start++;
        
        if (start == str.length()) {
            return 0;
        }
        
        long result = 0;
        bool nagative = false;
        if (str[start] == '-') {
            nagative = true;
            start ++;
        } else if (str[start] == '+') {
            start ++;
        }
        int length = 0;
        while (length < 11 && start < str.length() && str[start] >= '0' && str[start] <= '9') {
            length ++;
            result = result * 10 + str[start] - '0';
            start++;
        }
        if (result > INT_MAX && !nagative) result = INT_MAX;
        if (nagative && result > 0) result = -result;
        if (result < INT_MIN) result = INT_MIN;
        
        return result;
    }
};