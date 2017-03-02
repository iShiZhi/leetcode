class Solution {
public:
	int totalNQueens(int n) {
		vector<int> pos;
		int result = 0;

		generate(pos, n, result);
		return result;
	}

	void generate(vector<int>& pos, int n, int& result) {
		if (pos.size() == n) {
			result++;
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