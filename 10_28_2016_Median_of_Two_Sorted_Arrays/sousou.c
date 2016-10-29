// 高票答案太牛了，用c誊写一遍…

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (!nums1 && !nums2) return 0;
    int *ptr1=nums1, *ptr2=nums2;
    int size1=nums1Size,size2=nums2Size;
    if (nums1Size > nums2Size)
    {
        ptr1=nums2;
        ptr2=nums1;
        size1=nums2Size;
        size2=nums1Size;
    }

    int min=0, max=size1, mid=(size1+size2+1)/2;
    int i=0, j=0;
    while (min <= max)
    {
        i = (min+max)/2;
        j = mid-i;
        if (i<size1 && ptr1[i]<ptr2[j-1]) min = i+1;
        else if (i>0 && ptr2[j]<ptr1[i-1]) max = i-1;
        else break;
    }
    
    double median1, median2;
    if (mid == i) median1 = ptr1[i-1];
    else if (mid == j) median1 = ptr2[j-1];
    else median1 = ptr1[i-1]>ptr2[j-1] ? ptr1[i-1] : ptr2[j-1];
    
    if (0 != (size1+size2)%2) return median1;
    
    if (size1 == i) median2 = ptr2[j];
    else if (size2 == j) median2 = ptr1[i];
    else median2 = ptr1[i]<ptr2[j] ? ptr1[i] : ptr2[j];
    
    return (median1+median2)/2;
}
