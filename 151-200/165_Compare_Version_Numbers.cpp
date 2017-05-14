class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int> pv1;
		vector<int> pv2;

		getVersion(version1, pv1);
		getVersion(version2, pv2);

		int result = 0;
		int index = 0;
		while (index < pv1.size() && index < pv2.size()) {
			if (pv1[index] < pv2[index]) {
				result = -1;
				break;
			} else if (pv1[index] > pv2[index]) {
				result = 1;
				break;
			}

			index++;
		}

		if (result == 0 && index == pv1.size() && index < pv2.size()) {
			for (int i = index; i < pv2.size(); i++) {
				if (pv2[i] != 0) {
					result = -1;
					break;
				}
			}
			
		}

		if (result == 0 && index == pv2.size() && index < pv1.size()) {
			for (int i = index; i < pv1.size(); i++) {
				if (pv1[i] != 0) {
					result = 1;
					break;
				}
			}
		}

		return result;
	}

	void getVersion(string version, vector<int>& pv) {
		int index = 0;
		while (index < version.size()) {
			int num = 0;
			while (index < version.size() && version[index] != '.') {
				num = num * 10 + (version[index] - '0');
				index++;
			}
			pv.push_back(num);

			index++;
		}
	}
};