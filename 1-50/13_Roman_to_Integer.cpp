class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        map<char, int> digits;
        digits['I']=1;  
        digits['V']=5;  
        digits['X']=10;  
        digits['L']=50;  
        digits['C']=100;  
        digits['D']=500;  
        digits['M']=1000;  
          
        int i = 0;  
        while (i < s.size()) {
            while (i < s.size() && digits[s[i]] >= digits[s[i + 1]]) {  
                sum = sum + digits[s[i]];  
                i++;  
            }  
            while (i < s.size() && digits[s[i]] < digits[s[i+1]]) {  
                sum = sum - digits[s[i]];  
                i++;  
            }  
                  
        }  
        return sum;  
    }
};