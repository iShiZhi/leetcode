class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totalSize = nums1.size() + nums2.size();
		if (totalSize % 2 == 0) {
			return (search(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, totalSize / 2) + search(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, totalSize / 2 + 1)) / 2;
		} else {
			return search(nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, totalSize / 2 + 1);
		}
	}

	double search(vector<int>& nums1, vector<int>& nums2, int head1, int tail1, int head2, int tail2, int pos) {
		if (tail1 - head1 > tail2 - head2) {
			return search(nums2, nums1, head2, tail2, head1, tail1, pos);
		}

		if (head1 > tail1) {
			return nums2[head2 + pos - 1];
		}

		if (pos == 1) {
			if (nums1[head1] < nums2[head2]) {
				return nums1[head1];
			} else {
				return nums2[head2];
			}
		}

		int size1 = tail1 - head1 + 1;

		if ((pos - 1) / 2 >= size1) {
			int num1 = nums1[tail1];
			int num2 = nums2[pos - size1 - 1];

			if (num1 == num2) {
				return num1;
			} else if (num1 < num2) {
				return nums2[head2 + pos - size1 - 1];
			} else {
				return search(nums1, nums2, head1, tail1, head2 + pos - size1, tail2, size1);
			}
		} else {
			int mid = (pos - 1) / 2;

			int num1 = nums1[head1 + mid];
			int num2 = nums2[head2 + mid];

			if (num1 == num2) {
				return num1;
			} else if (num1 > num2) {
				if (pos % 2 == 1) {
					return search(nums1, nums2, head1, head1 + mid, head2 + mid, tail2, pos - (pos - 1) / 2);
				}
				else {
					return search(nums1, nums2, head1, head1 + mid + 1, head2 + mid + 1, tail2, pos - (pos - 1) / 2 - 1);
				}
			} else {
				if (pos % 2 == 1) {
					return search(nums1, nums2, head1 + mid, tail1, head2, head2 + mid, pos - (pos - 1) / 2);
				}
				else {
					return search(nums1, nums2, head1 + mid + 1, tail1, head2, head2 + mid + 1, pos - (pos - 1) / 2 - 1);
				}
			}
		}
	}
};