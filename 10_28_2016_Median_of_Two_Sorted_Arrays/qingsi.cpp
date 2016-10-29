class Solution {
    int _findKth(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int k) {
        if (start1 > end1) {
            return nums2[start2 + k];
        }
        if (start2 > end2) {
            return nums1[start1 + k];
        }
        int mid1 = (start1+end1) / 2;
        int mid2 = (start2+end2) / 2;
        if (nums1[mid1] < nums2[mid2]) {
            if (k < mid1 - start1 + mid2 - start2 + 1) {
                return _findKth(nums1, nums2, start1, end1, start2, mid2 - 1, k);
            } else {
                return _findKth(nums1, nums2, mid1 + 1, end1, start2, end2, k - (mid1 - start1 + 1));
            }
        } else {
            if (k < mid1 - start1 + mid2 - start2 + 1) {
                return _findKth(nums1, nums2, start1, mid1 - 1, start2, end2, k);
            } else {
                return _findKth(nums1, nums2, start1, end1, mid2 + 1, end2, k - (mid2 - start2 + 1));
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (_findKth(nums1, nums2, 0, m-1, 0, n-1, (m + n - 1) / 2) + _findKth(nums1, nums2, 0, m-1, 0, n-1, (m + n) / 2)) / 2.0;
    }
};
