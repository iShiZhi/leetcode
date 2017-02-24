class Solution {
public:

	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}

		long long a = llabs((long long)dividend);
		long long b = llabs((long long)divisor);
		
		vector<long long> cache;
		long long tmp = b;
		while (tmp <= a) {
			cache.push_back(tmp);
			tmp = tmp << 1;
		}

		long long sum = 0;
		int result = 0;
		for (int i = cache.size() - 1; i >= 0; i--) {
			if (sum + cache[i] > a) {
				continue;
			} else {
				sum += cache[i];
				result += pow(2, i);
			}
		}

		if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
			return -result;
		} else {
			return result;
		}
	}
};