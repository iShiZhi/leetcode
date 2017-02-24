class Solution {
public:
	set<string> result;

	vector<string> generateParenthesis(int n) {
		vector<char> parentheses;
		generate(parentheses, n, 0, 0);

		vector<string> results;
		for (set<string>::iterator iter = result.begin(); iter != result.end(); iter++) {
			results.push_back(*iter);
		}

		return results;
	}

	void generate(vector<char>& parentheses, int n, int left, int mismatch) {
		if (parentheses.size() == 2 * n) {
			string tmp = "";
			for (int i = 0; i < 2 * n; i++) {
				tmp += parentheses[i];
			}
			result.insert(tmp);
		}
		else {
			for (int i = 0; i < 2; i++) {
				if (i == 0 && left < n) {
					parentheses.push_back('(');
					generate(parentheses, n, left + 1, mismatch + 1);
					parentheses.erase(parentheses.end() - 1);
				}
				else if (parentheses.size() - left < n && mismatch >= 1) {
					parentheses.push_back(')');
					generate(parentheses, n, left, mismatch - 1);
					parentheses.erase(parentheses.end() - 1);
				}
			}
		}
	}
};