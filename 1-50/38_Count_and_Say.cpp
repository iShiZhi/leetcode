class Solution {
public:
    string countAndSay(int n) {
		if (n == 1) return "1";

		string last = "1";
		string result = "";
		for (int i = 2; i <= n; i++) {
			char ch = last[0];
			int count = 1;
			for (int j = 1; j < last.length(); j++) {
				if (ch == last[j]) {
					count++;
				}
				else {
					result += '0' + count;
					result += ch;

					ch = last[j];
					count = 1;
				}
			}

			result += '0' + count;
			result += ch;

			last = result;
			result = "";
		}

		return last;
	}
};