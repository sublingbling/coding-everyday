class Solution {
public:
    int maxArea(vector<int>& height) {
      return max(height, 0, height.size()-1);
    }
    
    int max(vector<int>& height, int left, int right){
        if ((left+1) == right)
          return height[right]>height[left] ? height[left] : height[right];
        
        int origVal = (height[right]>height[left] ? height[left] : height[right])*(right-left);
        int oldLeft = left;
        int oldRight  =right;
        if (height[right]>height[left]){
           do{
               left++;
           }while(height[oldLeft]>height[left] && ((1+left)!=right));
        }else{
           do{
               right--;
           }while(height[right]<height[oldRight] && ((left+1)!=right));
        }
        int newVal = max(height, left, right);
        return newVal > origVal ? newVal : origVal;
    }
};
