class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) return 1;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > nums.size()) {
				nums[i] = -1;
			} else {
				int index = i;
				while (index != nums[index] - 1) {
					if (nums[index] <= 0 || nums[index] > nums.size() || nums[nums[index] - 1] == nums[index]) {
						nums[index] = -1;
						break;
					}

					int tmp = nums[nums[index] - 1];
					nums[nums[index] - 1] = nums[index];
					nums[index] = tmp;
				}
			}
		}

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}

		return nums.size() + 1;
	}
};