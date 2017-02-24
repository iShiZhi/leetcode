class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int index = 0;
       for (int i = nums.size() - 1; i >= 1; i--) {
           if (nums[i] > nums[i - 1]) {
               index = i;
               break;
           }
       }
       
       if (index > 1 || nums[0] < nums[1]) {
           for (int i = nums.size() - 1; i >= index; i --) {
               if (nums[i] > nums[index - 1]) {
                   int tmp = nums[i];
                   nums[i] = nums[index - 1];
                   nums[index - 1] = tmp;
                   break;
               }
           }
       } else {
           index = 0;
       }
       
       for (int i = index; i < nums.size() - 1; i++) {
           for (int j = i + 1; j < nums.size(); j++) {
               if (nums[i] > nums[j]) {
                   int tmp = nums[i];
                   nums[i] = nums[j];
                   nums[j] = tmp;
               }
           }
       }
    }
};