class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4) return result;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			set<int> used;
			for (int j = i + 1; j < nums.size() - 2; j++) {
				int current = target - nums[i] - nums[j];
				if (used.find(current) == used.end()) {
					int head = j + 1;
					int tail = nums.size() - 1;
					
					while (head < tail) {	
						if (nums[head] + nums[tail] < current) {
							head++;
						} else if (nums[head] + nums[tail] > current) {
							tail--;
						} else {
							if (!(head > j + 1 && nums[head] == nums[head - 1] && tail < nums.size() - 1 && nums[tail] == nums[tail + 1])) {
								vector<int> ar;
								ar.push_back(nums[i]);
								ar.push_back(nums[j]);
								ar.push_back(nums[head]);
								ar.push_back(nums[tail]);
								result.push_back(ar);
							}
							head++;
							tail--;
						}
						
					}
				}
				used.insert(current);
			}
		}

		return result;
	}

};