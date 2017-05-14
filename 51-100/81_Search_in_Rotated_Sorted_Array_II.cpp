class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return true;
            } else {
                return false;
            }
        }
        
        int head = 0;
        int tail = nums.size() - 1;
        while (head < tail) {
            if (head == tail - 1) {
                if (nums[head] == target || nums[tail] == target) {
                    return true;
                } else {
                    return false;
                }
                break;
            } else {
                int mid = (head + tail) / 2;
                
                if (nums[head] < nums[mid]) {
                    if (nums[head] <= target && nums[mid] >= target) {
                        tail = mid;
                    } else {
                        head = mid;
                    }
                } else if (nums[head] > nums[mid]) {
                    if (nums[mid] <= target && nums[tail] >= target) {
                        head = mid;
                    } else {
                        tail = mid;
                    }
                } else {
                    head++;
                }
            }
        }
        
        return false;
    }
};