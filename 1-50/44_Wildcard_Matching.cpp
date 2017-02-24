class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.length() == 0 && p.length() == 0) return true;
		if (s.length() > 0 && p.length() == 0) return false;

		vector<vector<bool>> flag;
		for (int i = 0; i <= s.length(); i++) {
			vector<bool> tmp;
			for (int j = 0; j <= p.length(); j++) {
				tmp.push_back(false);
			}
			flag.push_back(tmp);
		}

		flag[0][0] = true;
		int i = 1;
		while (i <= p.length() && p[i - 1] == '*') {
			flag[0][i] = true;
			i++;
		}

		for (int i = 1; i <= s.length(); i++) {
			for (int j = 1; j <= p.length(); j++) {
				if (flag[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
					flag[i][j] = true;
				}

				if (p[j - 1] == '*') {
					int k = i;
					while (k >= 0 && !flag[k][j - 1]) {
						k--;
					}

					if (k >= 0 && flag[k][j - 1]) flag[i][j] = true;
				}
			}
		}
		return flag[s.length()][p.length()];
	}
};