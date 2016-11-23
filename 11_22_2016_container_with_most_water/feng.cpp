class Solution {
public:
    int maxArea(vector<int>& height) {
        
        deque<int> l;
        deque<int> r;
        
        for(int i=0; i<=height.size()-1;i++){
            if(l.empty()) l.push_back(i);
            else if(height[i]>height[l.back()]) l.push_back(i);
        }
        for(int i=height.size()-1; i>=l.back(); i--){
            if(r.empty()) r.push_front(i);
            else if(height[i]>height[r.front()]) r.push_front(i);
        }
        
        int max_area=0;
        
        while(!l.empty() && !r.empty()){
            if(height[l.front()]<height[r.back()]){
                max_area = max(max_area, (r.back()-l.front())*height[l.front()]);
                l.pop_front();
            }
            else{
                max_area = max(max_area, (r.back()-l.front())*height[r.back()]);
                r.pop_back();
            }
        }
        return max_area;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int idx_l=0;
        int max_l = idx_l;
        int idx_r=height.size()-1;
        int max_r=idx_r;
        int max_area=min(height[max_l],height[max_r])*(max_r-max_l);
        
        while(idx_l < idx_r){
            if(height[max_l] < height[max_r]){
                while(height[max_l] >= height[idx_l]) idx_l++;
                    max_l = idx_l;
            }
            else{
                while(height[max_r] >= height[idx_r]) idx_r--;
                    max_r = idx_r;
                }
            int area=min(height[max_l],height[max_r])*(max_r-max_l);
            max_area = max(area,max_area);
        }
        
        
        return max_area; 
    }
};
