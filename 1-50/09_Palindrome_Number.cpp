class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0) return false;

		int z = 0;
		while (x >= 10) {
		    z = z * 10 + x % 10;
		    x = x / 10;
		}
		z = z * 10 + x % 10;
		
		return x == z;
	}
};