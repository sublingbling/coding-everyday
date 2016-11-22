class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
          
        int left = 0;
        int right = numbers.size()-1;
        while (numbers[left]+numbers[right]!=target){
          if (numbers[left]+numbers[right] > target){
            right--;
          } else {
            left++;
          }
          if(right==left)
            return ret;
        }
        ret.push_back(left+1);
        ret.push_back(right+1);
        return ret;
    }
};
