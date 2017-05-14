class Solution {
public:
	unordered_map<int, bool> visited;
	bool isHappy(int n) {
		if (n <= 0 || visited[n]) return false;
		if (n == 1) return true;
		visited[n] = true;

		int cur = 0;
		while (n > 0) {
			cur += (n % 10) * (n % 10);
			n /= 10;
		}

		return isHappy(cur);
	}
};