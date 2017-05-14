class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> flags(s.length() + 1, false);
		flags[0] = true;

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < wordDict.size(); j++) {
				int index = i - wordDict[j].size() + 1;
				if (index >= 0 && flags[index] && s.substr(index, wordDict[j].size()) == wordDict[j]) {
					flags[i + 1] = true;
				}
			}
		}

		return flags[s.length()];
	}
};