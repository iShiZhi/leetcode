class Solution {
public:
	string getPermutation(int n, int k) {
		string result = "";
		vector<bool> used;
		vector<int> count;
		int tmp = 1;
		for (int i = 0; i < n; i++) {
			used.push_back(false);
			tmp = tmp * (i + 1);
			count.push_back(tmp);
		}

		int index = k;
		for (int i = n; i >= 2; i--) {
			int pos = index / count[i - 2];
			if (index % count[i - 2] != 0) {
				pos++;
			}
			tmp = 0;
			for (int j = 0; j < n; j++) {
				if (!used[j]) {
					tmp++;
					if (tmp == pos) {
						used[j] = true;
						result += (char)(j + 49);
						break;
					}
				}
			}
			index = index - (pos - 1) * count[i - 2];
		}
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				result += (char)(i + 49);
				break;
			}
		}

		return result;
	}
};