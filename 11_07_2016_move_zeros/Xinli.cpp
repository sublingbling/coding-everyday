class Solution {

public:
void moveZeroes(vector<int>& nums){
    moveZero(nums, 0);
}


void moveZero(vector<int>& nums, int index){

  int size=nums.size();
  int i =index;
  int j=index;

  while(nums [i] != 0 && i < size){
     i++;
     j++;
  }
  if(i == size)
    return;

  while(nums[j] == 0 && j<size){
    j++;
  }
  if(j == size)
    return;
  int temp= nums [i];
  nums[i] = nums[j];
  nums[j] = temp;
  moveZero(nums, i+1);
}
  
}
