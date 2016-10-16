class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int L=0;
        int R=nums.size()-1;
        int M;
        vector<int> result(2,-1);
        while(L<=R){
            M=(L+R)/2;
            if(nums[M]==target) break;
            if(nums[M]<target) L=M+1;
            else R=M-1;
        }
        if(L<=R){
            result[0]=M;
            result[1]=M;
            
            for(L=M;nums[L-1]==nums[M] && L>0;) L--;
            result[0]=L;
            for(R=M;nums[R+1]==nums[M] && R<nums.size()-1;) R++;
            result[1]=R;
        }
        return result;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        int L=0;int R=nums.size()-1;
        while(L<R){
            int M=(L+R)/2;
            if(nums[M]<target) L=M+1;
            else R=M;
        }
        if(nums[L]!=target) return result;
        else result[0]=L;
        
        R=nums.size()-1;
        while(L<R){
            int M=(L+R)/2+1;
            if(nums[M]>target) R=M-1;
            else L=M;
        }
        result[1]=R;
        return result;
    }
};
