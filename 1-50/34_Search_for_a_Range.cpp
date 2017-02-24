class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.size() == 0) {
			result.push_back(-1);
			result.push_back(-1);
		} else {
			result.push_back(findLeft(nums, target, 0, nums.size() - 1));
			result.push_back(findRight(nums, target, 0, nums.size() - 1));
		}

		return result;
	}

	int findLeft(vector<int>& nums, int target, int left, int right) {
		if (left == right || left == right - 1) {
			if (target == nums[left]) {
				return left;
			} else if (target == nums[right]) {
				return right;
			} else {
				return -1;
			}
		} else {
			int mid = (left + right) / 2;
			if (nums[mid] >= target) {
				return findLeft(nums, target, left, mid);
			} else {
				return findLeft(nums, target, mid, right);
			}
		}
	}

	int findRight(vector<int>& nums, int target, int left, int right) {
		if (left == right || left == right - 1) {
			if (target == nums[right]) {
				return right;
			} else if (target == nums[left]) {
				return left;
			} else {
				return -1;
			}
		} else {
			int mid = (left + right) / 2;
			if (nums[mid] <= target) {
				return findRight(nums, target, mid, right);
			} else {
				return findRight(nums, target, left, mid);
			}
		}
	}
};