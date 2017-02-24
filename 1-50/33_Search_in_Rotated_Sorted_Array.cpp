class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
		int head = 0;
		int tail = nums.size() - 1;
		int pivot = -1;
		while (head < tail) {
			if (head == tail - 1 && nums[head] > nums[tail]) {
				pivot = tail;
				break;
			}
			if (nums[head] > nums[tail]) {
				int mid = (head + tail) / 2;
				if (nums[head] < nums[mid]) {
					head = mid;
				} else {
					tail = mid;
				}

			} else {
				break;
			}
		}

		if (pivot == -1) {
			if (target > nums[nums.size() - 1] || target < nums[0]) {
				return -1;
			} else {
				head = 0;
				tail = nums.size() - 1;
			}
		} else {
		    if (target < nums[pivot] || target > nums[pivot - 1]) return -1;  
			if (target < nums[0]) {
			    if (target > nums[nums.size() - 1]) return -1;
				head = pivot;
				tail = nums.size() - 1;
			} else {
                if (target < nums[0]) return -1;
				head = 0;
				tail = pivot - 1;
			}
		}

		while (head <= tail) {
			if (head == tail - 1) {
				if (target == nums[head]) {
					return head;
				} else if (target == nums[tail]) {
					return tail;
				} else {
					return -1;
				}
			}
			int mid = (head + tail) / 2;
			if (target > nums[mid]) {
				head = mid;
			} else if (target < nums[mid]) {
				tail = mid;
			} else {
				return mid;
			}
		}
	}
};