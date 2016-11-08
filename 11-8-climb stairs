class Solution {
public:
    int climbStairs(int n) {
      int i = 3;
      std::vector<int> vec;
      vec.push_back(0);
      vec.push_back(1);
      vec.push_back(2);
      
      while ( i <= n ) {
          vec.push_back(vec[i-1]+vec[i-2]);
          i++;
      }
      return vec[n];
    }
    
};
