class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> cache(s.length() + 1);
		cache[0].push_back("");

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < wordDict.size(); j++) {
				int index = i - wordDict[j].size() + 1;
				if (index >= 0 && cache[index].size() > 0 && s.substr(index, wordDict[j].size()) == wordDict[j]) {
					cache[i + 1].push_back(wordDict[j]);
				}
			}
		}

        vector<string> result;
        traverse("", cache, s.length(), result);
        return result;
    }
    
    void traverse(string str, vector<vector<string>>& cache, int index, vector<string>& result) {
        if (index == 0) {
            result.push_back(str);
        } else {
            for (int i = 0; i < cache[index].size(); i++) {
                if (str.empty()) {
                    traverse(cache[index][i], cache, index - cache[index][i].size(), result);
                } else {
                    traverse(cache[index][i] + ' ' + str, cache, index - cache[index][i].size(), result);
                }
            }
        }
    }
};