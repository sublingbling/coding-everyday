class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> r;
        for(auto a:nums){
            if(r.empty()||a>r.back()) r.push_back(a);
            else{
                for(auto& b:r) {  //since r is increase order, can use binary search for further optimize
                    if(a<=b){
                        b=a;
                        break;
                    }
                }
            }
        }
        return r.size();
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> r;
        for(auto a:nums){
            if(r.empty()||a>r.back()) r.push_back(a);
            else{
                *lower_bound(r.begin(), r.end(), a)=a;
            }
        }
        return r.size();
    }
};
