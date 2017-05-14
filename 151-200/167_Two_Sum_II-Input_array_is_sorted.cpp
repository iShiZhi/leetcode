class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0;
        int tail = numbers.size() - 1;
        
        while (head < tail) {
            if (numbers[head] + numbers[tail] == target) {
                break;
            } else if (numbers[head] + numbers[tail] < target) {
                head++;
            } else {
                tail--;
            }
        }
        
        vector<int> result;
        result.push_back(head + 1);
        result.push_back(tail + 1);
        return result;
    }
};