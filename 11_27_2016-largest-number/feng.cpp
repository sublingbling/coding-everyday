class Solution {
private:
    struct compare{
        bool operator()(string a, string b){
            return a+b > b+a;
        }
    };
    
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto a:nums) s.push_back(to_string(a));
        sort(s.begin(),s.end(),compare());
        string r;
        for(auto a:s) {
            r+= a; 
            if(r[0]=='0') break;
        }
        return r;
    }
};
