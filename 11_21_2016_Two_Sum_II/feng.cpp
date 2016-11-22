class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> r;
        int lo=0;
        int hi=numbers.size()-1;
        while(lo<hi){
            if(numbers[lo]+numbers[hi]<target) lo++;
            else if(numbers[lo]+numbers[hi]>target) hi--;
            else {r.push_back(lo+1); r.push_back(hi+1); return r;}
        }
        return r;
    }
};
