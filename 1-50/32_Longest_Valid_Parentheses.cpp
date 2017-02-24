class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> pstack;
		int max = 0;
		int last = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				pstack.push(i);
			} else if (pstack.empty()) {
				last = i + 1;
			} else {
				pstack.pop();
				if (pstack.empty()) {
					max = max > i - last + 1 ? max : i - last + 1;
				} else {
					max = max > i - pstack.top() ? max : i - pstack.top();
				}
			}
		}
		return max;
	}
};