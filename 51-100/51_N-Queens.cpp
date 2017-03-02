class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> pos;
		vector<vector<string>> result;

		generate(pos, n, result);
		return result;
	}

	void generate(vector<int>& pos, int n, vector<vector<string>>& result) {
		if (pos.size() == n) {
			vector<string> tmp;
			for (int i = 0; i < n; i++) {
				string str = "";
				for (int j = 0; j < n; j++) {
					str = str + '.';
				}
				tmp.push_back(str);
			}
			for (int i = 0; i < pos.size(); i++) {
				tmp[i][pos[i]] = 'Q';
			}

			result.push_back(tmp);
		} else {
			for (int i = 0; i < n; i++) {
				if (valid(pos, i)) {
					pos.push_back(i);
					generate(pos, n, result);
					pos.erase(pos.end() - 1);
				}
			}
		}
	}

	bool valid(vector<int>& pos, int curPos) {
		for (int i = 0; i < pos.size(); i++) {
			if (curPos == pos[i] || pos.size() - i == abs(curPos - pos[i]) || pos.size() + curPos == i + pos[i]) {
				return false;
			}
		}
		return true;
	}
};