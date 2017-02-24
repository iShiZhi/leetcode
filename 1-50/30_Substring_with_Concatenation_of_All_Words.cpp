class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.size() == 0) {
			return result;
		}

		int perLength = words[0].length();
		if (s.length() < words.size() * perLength) {
			return result;
		}

		map<string, int> exist;
		map<string, int> wordCount;
		for (int j = 0; j < words.size(); j++) {
			wordCount[words[j]] = wordCount[words[j]] + 1;
		}
		for (int i = 0; i <= s.length() - words.size() * perLength; i++) {
			bool found = true;
			int count = 0;

			for (int j = 0; j < words.size(); j++) {
				exist[words[j]] = 0;
			}

			for (int j = 0; j < words.size(); j++) {
				string tmpStr = s.substr(i + j * perLength, perLength);
				if (exist.find(tmpStr) != exist.end()) {
					exist[tmpStr] ++;
					count++;
					if (exist[tmpStr] > wordCount[tmpStr]) {
						found = false;
						break;
					}
						
				}
				else {
					found = false;
					break;
				}
			}

			if (found && count == words.size()) {
				result.push_back(i);
			}
		}

		return result;
	}
};