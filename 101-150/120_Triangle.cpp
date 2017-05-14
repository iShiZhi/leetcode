class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> path;
		vector<int> path1(triangle.size(), INT_MAX);
		vector<int> path2(triangle.size(), INT_MAX);
		path.push_back(path1);
		path.push_back(path2);

		path[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				int prev = (i - 1) % 2;
				int cur = i % 2;
				
				path[cur][j] = INT_MAX;

				if (j < triangle[i - 1].size() && triangle[i][j] + path[prev][j] < path[cur][j]) {
					path[cur][j] = triangle[i][j] + path[prev][j];
				}

				if (j > 0 && triangle[i][j] + path[prev][j - 1] < path[cur][j]) {
					path[cur][j] = triangle[i][j] + path[prev][j - 1];
				}
			}
		}

		int result = INT_MAX;
		for (int i = 0; i < triangle.back().size(); i++) {
			if (result > path[(triangle.size() - 1) % 2][i]) {
				result = path[(triangle.size() - 1) % 2][i];
			}
		}

		return result;
	}
};