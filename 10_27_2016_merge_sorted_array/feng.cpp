class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m -= 1;  //index
        n -= 1;  //index
        for(int i=m+n+1; i>=0; i--){
            if(n<0) break;   //stop if n is empty
            if(m<0||nums1[m]<=nums2[n]){
                nums1[i]=nums2[n];
                n--;
            }
            else{
                nums1[i]=nums1[m];
                m--;
            }
        }
    }
};
