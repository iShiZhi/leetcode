#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int tmp = x;
        if (tmp < 0) tmp = -tmp;
        while (tmp > 0) {
            result = result * 10 + tmp % 10;
            tmp = tmp / 10;
        }
        
        if (x < 0) result = -result;
        if (result > INT_MAX) result = 0;
        if (result < INT_MIN) result = 0;
        
        return (int)result;
    }
};