class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0, blue=nums.size()-1;
        for(int i=0; i<=blue;)
        {
            switch (nums[i])
            {
                case 0:
                    nums[i++] = nums[red];
                    nums[red++] = 0;
                    break;
                case 2:
                    nums[i] = nums[blue];
                    nums[blue--] = 2;
                    break;
                case 1:
                    i++;
                    break;
                default:
                    return;
            }
        }
        
        return;
    }
};
