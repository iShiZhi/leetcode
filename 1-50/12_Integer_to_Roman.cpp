class Solution {
public:
    string getRomanString(int digit, int multi) {
        string result = "";
        
        string ch1, ch2, ch3;
        if (multi == 100) {
            ch1 = "C";
            ch2 = "D";
            ch3 = "M";
        } else if (multi == 10) {
            ch1 = "X";
            ch2 = "L";
            ch3 = "C";
        } else if (multi == 1) {
            ch1 = "I";
            ch2 = "V";
            ch3 = "X";
        }
        
        if (digit == 4) {
            result += ch1;
            result += ch2;
        } else if (digit == 5) {
            result += ch2;
        } else if (digit == 9) {
            result += ch1;
            result += ch3;
        } else {
            int tmp = digit;
            if (digit > 5) {
                result += ch2;
                tmp = tmp - 5;
            }
            
            for (int i = 0; i < tmp; i++) {
                result += ch1;
            }
        }
        
        return result;
    }

    string intToRoman(int num) {
        string result = "";
        
        for (int i = 0; i < num / 1000; i ++) {
            result = result + 'M';
        }
        num = num % 1000;
        
        result = result + getRomanString(num / 100, 100);
        num = num % 100;
        result = result + getRomanString(num / 10, 10);
        num = num % 10;
        result = result + getRomanString(num, 1);
        
        return result;
    }
};