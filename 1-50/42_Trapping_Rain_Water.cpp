class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0 || height.size() == 1) {
			return 0;
		}

		int head = 0;
		int tail = height.size() - 1;

		int result = 0;
		int lastHead = 0;
		int lastTail = height.size() - 1;
		while (head < tail) {
			if (height[head] < height[tail]) {
				head++;
				if (height[head] >= height[lastHead]) {
					lastHead = head;
				} else {
					result += height[lastHead] - height[head];
				}
			} else {
				tail--;
				if (height[tail] >= height[lastTail]) {
					lastTail = tail;
				} else {
					result += height[lastTail] - height[tail];
				}
			}
		}

		return result;
	}
};