class Solution {
public:
	bool isMatch(string s, string p) {
		string reg = "";
		vector<bool> star;
		int i = 0;
		while (i < p.length()) {
			if (i + 1 < p.length() && p[i + 1] == '*') {
				star.push_back(true);
				reg += p[i];
				i++;
			}
			else {
				star.push_back(false);
				reg += p[i];
			}
			i++;
		}

		vector<vector<bool>> flag;

		for (int i = 0; i <= s.length(); i++) {
			vector<bool> tmp;
			flag.push_back(tmp);
			for (int j = 0; j <= reg.length(); j++) {
				flag[i].push_back(false);
			}
		}

		flag[0][0] = true;

		int count = 0;
		while (count < star.size() && star[count]) {
			count++;
		}
		for (int i = 1; i <= s.length(); i++) {
			flag[i][0] = false;
		}

		for (int j = 1; j <= reg.length(); j++) {
			if (j <= count) {
				flag[0][j] = true;
			}
			else {
				flag[0][j] = false;
			}
		}

		for (int i = 1; i <= s.length(); i++) {
			for (int j = 1; j <= reg.length(); j++) {
				flag[i][j] = false;
				if (flag[i - 1][j - 1] && (s[i - 1] == reg[j - 1] || reg[j - 1] == '.')) {
					flag[i][j] = true;
				}

				for (int k = j; k >= 1; k--) {
					if (star[k - 1]) {
						if ((reg[k - 1] == s[i - 1] || reg[k - 1] == '.') && (flag[i - 1][k] || flag[i - 1][k - 1])) {
							flag[i][j] = true;
						}

						if (k >= 2 && (reg[k - 2] == s[i - 1] || reg[k - 2] == '.') && flag[i - 1][k - 2]) {
							flag[i][j] = true;
						}
					}
					else {
						break;
					}
				}
			}
		}

		return flag[s.length()][reg.length()];
	}
};