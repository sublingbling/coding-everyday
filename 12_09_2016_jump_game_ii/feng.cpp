class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end=0, count = 0;
        while(end<nums.size()-1){
            int next_end = 0;
            for(int i=start; i<=end; i++){
                next_end = max(next_end, i+nums[i]);
            }
            count++;
            start = end+1;
            end = next_end;
        }
        return count;
        
    }
};
