class Solution {
public:
    map<int, double> cache;

    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1 || n == -1) {
            if (n > 0) {
                cache[n] = x;
            } else {
                cache[n] = 1/x;
            }
        } else {
            int y = n / 2;
            map<int, double>::iterator iter = cache.find(y);
            double value = 1;
            if (iter != cache.end()) {
                value = iter->second * iter->second;
            } else {
                value = myPow(x, y);
                cache[y] = value;
                value = value * value;
            }
            
            if (n % 2 == 0) {
                cache[n] = value;
            } else {
                if (n > 0) {
                    cache[n] = value * x;
                } else {
                    cache[n] = value / x;
                }
            }    
        }
        
        return cache[n];
    }
};