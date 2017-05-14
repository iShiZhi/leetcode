class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int result = 0;
		heights.push_back(0);
		stack<int> stack;
		for (int i = 0; i < heights.size(); i++) {
			while (!stack.empty() && heights[i] < heights[stack.top()]) {
				int index = stack.top();
				stack.pop();
				int width = stack.empty() ? i : i - stack.top() - 1;
				if (result < heights[index] * width) {
					result = heights[index] * width;
				}
			}
			stack.push(i);
		}
		
		return result;
	}
};