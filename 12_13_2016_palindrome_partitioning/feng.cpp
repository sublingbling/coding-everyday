class Solution {
private:
    vector<vector<int>> a2b;
    vector<vector<string>> partition(string& s, int i){
        vector<vector<string>> p_r;
        if(i>=s.size()) return p_r;
        for(int j=0; j<a2b[i].size();j++){
            int r= a2b[i][j];
            string sub_s = s.substr(i,r-i+1);
            vector<vector<string>> p = partition(s, r+1);
            if(p.empty()){
                vector<string> t;
                t.push_back(sub_s);
                p_r.push_back(t);
            }
            for(int k=0; k<p.size();k++){
                p[k].push_back(sub_s);
                p_r.push_back(p[k]);
            }
        }
        return p_r;
    }
public:
    vector<vector<string>> partition(string s){
        string rev_s;
        for(int i=s.size()-1;i>=0;i--) rev_s.push_back(s[i]);
        vector<int> t;
        //build palindrome map
        for(int i=0; i<s.size();i++) a2b.push_back(t);
        
        for(int i=0; i<2*s.size(); i++){
            int l = i>>1;
            int r = (i+1)>>1;
            while(l>=0 && r< s.size()&& rev_s[l]==rev_s[r]){
                a2b[l].push_back(r);
                l--;
                r++;
            }
        }
        
        //partition
        return partition(rev_s,0);
    }
};
