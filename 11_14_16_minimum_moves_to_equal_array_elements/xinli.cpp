class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (!nums.size()) return 0;
        //find min value and sum
        int min = nums[0];
        int sum = min;
        for(int i = 1; i<nums.size();i++){
            if(min > nums[i]){
                min = nums[i];
            }
            sum += nums[i];
        }

        // m = sum-min*size
        return sum-min*nums.size();
    }

};
