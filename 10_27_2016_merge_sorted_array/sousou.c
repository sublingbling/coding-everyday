void merge(int* nums1, int m, int* nums2, int n) {
    if (0 == m) 
    {
        memcpy(nums1, nums2, n*sizeof(int));
        return;
    }
    if (0 == n) return;
    
    for(int i=m-1, end=m+n-1; i>=0; i--,end--) nums1[end] = nums1[i];
    int i=0,i1=n,i2=0;
    while (i1<m+n && i2<n)
        nums1[i++] = nums1[i1] > nums2[i2] ? nums2[i2++] : nums1[i1++];
    if (m+n == i1) memcpy(nums1+i, nums2+i2, (n-i2)*sizeof(int));
    
    return;
}
