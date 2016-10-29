class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=0;
        int l2=0;
        int s = nums1.size() + nums2.size();
        int mid = (s+1)/2;
        while(l1+l2<mid){
            if(l1==nums1.size()) l2= mid - l1;
            else if(l2==nums2.size()) l1= mid - l2;
            else{
                int step = max(2,mid-l1-l2);  //move half distance or at least 1 step for each;
                int step1;                    //each vector move step/2; so each time can rule out step/2 element, logn
                int step2;
                if(l1+step/2>nums1.size()){   //can't move over boundary
                    step1 = nums1.size()-l1;
                    step2 = step - step1;     //add up to step
                } 
                else if(l2+step/2>nums2.size()){
                    step2 = nums2.size()-l2;
                    step1 = step - step2;
                }
                else{
                    step1 = step2 =  step/2;
                }
                
                //move to keep smaller part to left or l1 and l2;
                if(nums1[l1+step1-1]< nums2[l2+step2-1]) l1+=step1;
                else l2+= step2;
            } 
        }
        
        // .....a1 l1 ....
        // .....a2 l2 ....
        // k = max(a1,a2) k1 = max(l1,l2)    even number (k+k1)/2   odd number k
        int k = (l1<1)?nums2[l2-1]:(l2<1)?nums1[l1-1]:max(nums1[l1-1], nums2[l2-1]);
        if(s&1) return k;
        int k1 = (l1==nums1.size())?nums2[l2]:(l2==nums2.size())?nums1[l1]:min(nums1[l1], nums2[l2]);
        return (k+k1)/2.0;
        }
};
