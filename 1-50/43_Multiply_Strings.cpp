class Solution {
public:
	string multiply(string num1, string num2) {
		string result = "";
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		
		string postfix = "";
		for (int i = num1.length() - 1; i >= 0; i--) {
			string tmp = postfix;
			int extra = 0;
			for (int j = num2.length() - 1; j >= 0; j--) {
				extra = extra + (num1[i] - '0') * (num2[j] - '0');
				tmp = (char)(extra % 10 + '0') + tmp;
				extra = extra / 10;
			}
			if (extra > 0) tmp = (char)(extra % 10 + '0') + tmp;

			int j = result.length() - 1;
			int k = tmp.length() - 1;
			extra = 0;
			string plus = "";
			while (j >= 0 || k >= 0) {
				if (j >= 0) {
					extra = extra + (result[j] - '0');
					j--;
				}
				if (k >= 0) {
					extra = extra + (tmp[k] - '0');
					k--;
				}
				plus = (char)(extra % 10 + '0') + plus;
				extra = extra / 10;
			}
			if (extra > 0) plus = (char)(extra % 10 + '0') + plus;
			result = plus;
			postfix += '0';
		}
		return result;
	}
};