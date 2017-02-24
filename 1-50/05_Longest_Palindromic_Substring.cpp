class Solution {
public:
    string longestPalindrome(string s) {
        string result = s.substr(0, 1);

		vector<bool> flag1;
		vector<bool> flag2;
		vector<bool> flag3;

		bool flag = false;
		for (int i = 0; i < s.size(); i++) {
			flag1.push_back(true);
			if (i != s.size() - 1 && s[i] == s[i + 1]) {
				flag2.push_back(true);
				if (!flag) {
					flag = true;
					result = s.substr(i, 2);
				}
			} else {
			    flag2.push_back(false);
			}
			flag3.push_back(false);
		}


		for (int i = 3; i <= s.size(); i++) {
			flag = false;
			for (int j = 0; j <= s.size() - i; j++) {
				if (s[j] == s[j + i - 1] && flag1[j + 1]) {
					flag3[j] = true;
					if (!flag) {
						flag = true;
						result = s.substr(j, i);
					}
				}
			}

			flag1.clear();
			flag1.assign(flag2.begin(), flag2.end());
			flag2.clear();
			flag2.assign(flag3.begin(), flag3.end());
			for (int j = 0; j < s.size(); j++) {
				flag3[j] = false;
			}
		}

		return result;
    }
};