class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sz = nums.size();
        int minElem = *(std::min_element(nums.begin(), nums.end()));
        return std::accumulate(nums.begin(), nums.end(), -sz*minElem);
    }
};
