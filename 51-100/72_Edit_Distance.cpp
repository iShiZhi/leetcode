class Solution {
public:
	int minDistance(string word1, string word2) {
		vector<int> d1;
		vector<int> d2;
		for (int i = 0; i <= word2.length(); i++) {
			d1.push_back(i);
		}

		for (int i = 1; i <= word1.length(); i++) {
			d2.push_back(i);
			for (int j = 1; j <= word2.length(); j++) {
				d2.push_back(word1.length() + word2.length());

				if (word1[i - 1] == word2[j - 1] && d1[j - 1] < d2[j]) {
					d2[j] = d1[j - 1];
				}

                if (d1[j - 1] + 1 < d2[j]) {
					d2[j] = d1[j - 1] + 1;
				}

				if (d1[j] + 1 < d2[j]) {
					d2[j] = d1[j] + 1;
				}

				if (d2[j - 1] + 1 < d2[j]) {
					d2[j] = d2[j - 1] + 1;
				}
			}

			d1.clear();
			d1.assign(d2.begin(), d2.end());
			d2.clear();
		}

		return d1[word2.length()];
	}
};