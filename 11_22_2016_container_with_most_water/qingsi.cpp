class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int res = INT_MIN;
        while (i < j) {
            int area = min(height[i], height[j])*(j - i);
            if (area > res) {
                res = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
