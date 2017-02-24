class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            int tmp = right - left;
            
            if (height[left] > height[right]) {
                tmp = tmp * height[right];
                right --;
            } else {
                tmp = tmp * height[left];
                left ++;
            }
            
            if (tmp > result) result = tmp;
        }
        
        return result;
    }
};