class Solution {
public:
	int numDecodings(string s) {
		if (s.length() == 0 || s[0] == '0') {
		    return 0;
		}
		vector<int> ways(s.length() + 1, 0);
		ways[0] = 1;
		ways[1] = 1;

		for (int i = 2; i <= s.length(); i++) {
			if (s[i - 1] != '0') {
				ways[i] += ways[i - 1];
			} 
				
			int comb = (s[i - 1] - '0') + (s[i - 2] - '0') * 10;
			if (comb >= 10 && comb <= 26) {
			    ways[i] += ways[i - 2];
			}
			
			if (ways[i] == 0) {
			    return 0;
			}
		}
		return ways[s.length()];
	}
};