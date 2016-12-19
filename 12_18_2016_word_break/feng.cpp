class Solution {
private:
    int* dp;
    bool wordBreakR(string& s, int l, unordered_set<string>& wordDict) {
        if(l==s.size()) return true;
        for(int i=1; i<=s.size()-l;i++){
            if(dp[l+i]!=0 && wordDict.find(s.substr(l,i))!=wordDict.end()){ 
                if(dp[l+i]!=-1) return dp[l+i];
                if(dp[l+i] = wordBreakR(s, l+i,wordDict)) return true;
            } 
        }
        return false;
    }    
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.empty()) return true;
        dp = new int[(int)s.size()+1];
        for(int i=0; i<s.size();i++) dp[i]=-1;
        dp[s.size()]=1;
        return wordBreakR(s, 0, wordDict);
    }
};
