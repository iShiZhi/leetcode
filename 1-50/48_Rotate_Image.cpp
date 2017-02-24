class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) return;

		int size = matrix.size() - 1;
		for (int i = 0; i < matrix.size() / 2; i++) {
			for (int j = i; j < matrix.size() - i - 1; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[size - j][i];
				matrix[size - j][i] = matrix[size - i][size - j];
				matrix[size - i][size - j] = matrix[j][size - i];
				matrix[j][size - i] = tmp;
			}
		}
	}
};