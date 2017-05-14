class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long m = numerator;
		long long n = denominator;
		m = abs(m);
		n = abs(n);

		string result = to_string(m / n);
        if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) result = '-' + result;
		if (m % n == 0) {
			return result;
		}	
		result += '.';
        int baseLen = result.size();

		map<long long, int> recur;

		long long cur = (m % n) * 10;
		int index = 0;
		while (cur > 0 && recur.find(cur) == recur.end()) {
		    recur[cur] = index;
			result += to_string(cur / n);
			cur = (cur % n) * 10;
			index++;
		}

		if (cur > 0) {
			result = result.substr(0, baseLen + recur.at(cur)) + '(' + result.substr(baseLen + recur.at(cur)) + ')';
		}	

		return result;
	}
};