class Solution {

public:

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() == 0) return result;
		
		set<int> sum;
		set<int> used;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			sum.clear();
			used.clear();
			int target = -nums[i];
			for (int j = i + 1; j < nums.size(); j++) {
				if (sum.find(target - nums[j]) != sum.end() && used.find(target - nums[j]) == used.end()) {
					used.insert(target - nums[j]);

					vector<int> triplet;
					triplet.push_back(nums[i]);
					triplet.push_back(target - nums[j]);
					triplet.push_back(nums[j]);


					result.push_back(triplet);
				}

				sum.insert(nums[j]);
			}
		}

		return result;
	}

};