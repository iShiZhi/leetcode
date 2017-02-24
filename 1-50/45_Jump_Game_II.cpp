class Solution {
public:
	int jump(vector<int>& nums) {
		vector<int> tries;
		tries.push_back(0);
		for (int i = 1; i < nums.size(); i++) {
			tries.push_back(nums.size() - 1);
		}

		int forward = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			int start = i + 1 > forward ? i + 1 : forward;
			for (int j = start; j <= i + nums[i]; j++) {
				if (j < nums.size() && tries[j] > tries[i] + 1) {
					tries[j] = tries[i] + 1;
				}
			}

			forward = i + nums[i];
		}

		return tries[nums.size() - 1];
	}
};