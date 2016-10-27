class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::unique_ptr<int[]> arr(new int[m+n]);
        for (int i = 0, j = 0, k = 0; k < m + n; k++) {
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    arr[k] = nums1[i];
                    i++;
                } else {
                    arr[k] = nums2[j];
                    j++;
                }
            } else if (i < m) {
                arr[k] = nums1[i];
                i++;
            } else {
                arr[k] = nums2[j];
                j++;
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = arr[i];
        }
    }
};
