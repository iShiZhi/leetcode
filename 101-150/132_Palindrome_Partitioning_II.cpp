class Solution {
public:
	int minCut(string s) {
		vector<vector<bool>> flags(s.length(), vector<bool>(s.length(), false));
		vector<int> cut(s.length() + 1);
		
		for (int i = 0; i < s.length(); i++) {
			flags[i][i] = true;
		}

		cut[s.length()] = -1;
		for (int i = s.length() - 1; i >= 0; i--) {
			cut[i] = cut[i + 1] + 1;
			for (int j = i + 1; j < s.length(); j++) {
				if (s[i] == s[j] && (i == j - 1 || flags[i + 1][j - 1])) {
					flags[i][j] = true;
					if (j == s.length() - 1) {
						cut[i] = 0;
					} else if (cut[j + 1] + 1 < cut[i]) {
						cut[i] = cut[j + 1] + 1;
					}
				}
			}
		}

		return cut[0];
	}
};