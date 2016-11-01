class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx(2,0);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    idx[0]=i;
                    idx[1]=j;
                    return idx;
                }
            }
        }
        return idx;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idxp;
        vector<int> idxn;
        vector<int> *pidx=NULL;
        int idx;
        for(int i=0;i<nums.size();i++){
            idx = target-nums[i];
			pidx = (idx<0)?&idxn:&idxp;
			if(abs(idx)<(*pidx).size() && (*pidx)[abs(idx)]) {
				(*pidx).resize(2);
				(*pidx)[0]=(*pidx)[abs(idx)]-1;
				(*pidx)[1]=i;
				return (*pidx);
			}

			idx = nums[i];
            pidx = (idx<0)?&idxn:&idxp;
            if(abs(idx)>=(*pidx).size()) (*pidx).resize(abs(idx)+1);
			(*pidx)[abs(idx)]=i+1;
        }
		return (*pidx);
    }
};
