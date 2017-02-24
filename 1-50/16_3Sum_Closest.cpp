class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
		bool init = true;

		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			int current = target - nums[i];
			int head = i + 1;
			int tail = nums.size() - 1;
			while (head < tail) {
				int tmp = nums[head] + nums[tail];
				if (init || abs(current - tmp) < abs(target - result)) {
					init = false;
					result = nums[i] + nums[head] + nums[tail];
				}

				if (tmp < current) {
					head++;
				} else if (tmp > current) {
					tail--;
				} else {
					break;
				}
			}
			if (result == target && !init) {
				break;
			}
		}

		return result;
	}
};