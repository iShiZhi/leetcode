class Solution {
public:
    int countPrimes(int n) {
        vector<bool> flag(n, false);
        for (int i = 2; i * i < n; i++) {  
            if (!flag[i]) {  
                for (int j = i; i * j < n; j++) {  
                    flag[i * j] = true;  
                }  
            }  
        }
        
        int result = 0;  
        for (int i = 2; i < n; i++) {  
            if (flag[i] == false) result++;  
        }  
        return result;  
    }
};