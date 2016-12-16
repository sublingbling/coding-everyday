class Solution {
private:
    vector<vector<int>> a2b;
public:
    int minCut(string s) {
         //build palindrome map
        vector<int> t;
        for(int i=0; i<s.size();i++) a2b.push_back(t);
        
        for(int i=0; i<2*s.size(); i++){
            int l = i>>1;
            int r = (i+1)>>1;
            while(l>=0 && r< s.size()&& s[l]==s[r]){
                a2b[l].push_back(r);
                l--;
                r++;
            }
        }
        
        //how many steps it take from 0 to size()-1;
        int* steps_l = new int[s.size()+1];
        int* steps_r = new int[s.size()+1];
        steps_l[0] = steps_r[0] = 0;
        for(int i =1; i<s.size(); i++) steps_l[i] = steps_r[i] = INT_MAX;
        
        for(int i=0; i< a2b.size(); i++){
            for(int j=0; j< a2b[i].size(); j++){
                steps_l[a2b[i][j]+1] = min(steps_l[a2b[i][j]+1], steps_l[i]+1);
                steps_r[a2b[i][j]] = min(steps_l[i],steps_r[a2b[i][j]]);
            }
        }
        return min(steps_l[s.size()-1],steps_r[s.size()-1]);
    }
};

//combine map build and step count
class Solution {
public:
    int minCut(string s) {
        //how many steps it take from 0 to size()-1;
        int* steps_l = new int[s.size()+1];
        int* steps_r = new int[s.size()+1];
        steps_l[0] = steps_r[0] = 0;
        for(int i =1; i<s.size(); i++) steps_l[i] = steps_r[i] = INT_MAX;
        
        for(int i=0; i<2*s.size(); i++){
            int l = i>>1;
            int r = (i+1)>>1;
            while(l>=0 && r< s.size()&& s[l]==s[r]){
                steps_l[r+1] = min(steps_l[r+1], steps_l[l]+1);
                steps_r[r] = min(steps_l[l],steps_r[r]);
                l--;
                r++;
            }
        }
        
        return min(steps_l[s.size()-1],steps_r[s.size()-1]);
    }
};
