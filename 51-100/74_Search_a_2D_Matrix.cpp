class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) {
			return false;
		} else if (matrix.size() == 1) {
		    if (matrix[0].size() == 0) {
		        return false;
		    } else if (matrix[0].size() == 1) {
		        if (matrix[0][0] == target) {
		            return true;
		        } else {
		            return false;
		        }
		    }
		}

		int m = matrix.size();
		int n = matrix[0].size();
		int head = 1;
		int tail = m * n;

		while (head < tail) {
			int mid = (head + tail) / 2;
			int x = mid / n;
			int y = mid % n - 1;

			if (mid % n == 0) {
				x--;
				y = n - 1;
			}

			if (matrix[x][y] == target) {
				return true;
			} else if (matrix[x][y] < target) {
				if (head == mid) {
					x = tail / n;
					y = tail % n - 1;
					if (tail % n == 0) {
					    x--;
					    y = n - 1;
					}
					if (matrix[x][y] == target) {
					    return true;
					} else {
					    return false;
					}
				} else {
					head = mid;
				}
			} else if (matrix[x][y] > target) {
				if (tail == mid) {
					x = head / n;
					y = head % n - 1;
					if (head % n == 0) {
					    x--;
					    y = n - 1;
					}
					if (matrix[x][y] == target) {
					    return true;
					} else {
					    return false;
					}
				}
				else {
					tail = mid;
				}
			}
		}
		return false;
	}
};