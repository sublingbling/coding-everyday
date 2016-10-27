class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (!m && !n) {
            assert(false);
        } else if (!m) {
            return n % 2 ? nums2[n/2] : (double)(nums2[n/2] + nums2[n/2 - 1]) / 2;
        } else if (!n) {
            return m % 2 ? nums1[m/2] : (double)(nums1[m/2] + nums1[m/2 - 1]) / 2;
        }
        int medianPos = (m + n) / 2;
        int prev;
        int curr = -1;
        for (int i = 0, j = 0, cnt = 0; cnt < medianPos + 1; cnt++) {
            prev = curr;
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    curr = nums1[i];
                    i++;
                } else {
                    curr = nums2[j];
                    j++;
                }
            } else if (i < m) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
        }
        return (n + m) % 2 ? double(curr) : (double)(prev + curr) / 2;
    }
};
