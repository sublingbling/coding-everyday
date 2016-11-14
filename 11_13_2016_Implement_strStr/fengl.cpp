class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        
        //build kmp
        int needle_kmp[needle.size()];
        needle_kmp[0] = -1;
        for(int i=1; i<needle.size(); i++){
            int idx = needle_kmp[i-1];
            while(needle[i]!=needle[idx+1]&&idx>-1) idx = needle_kmp[idx];
            needle_kmp[i]=(needle[i]==needle[idx+1])? idx+1:-1;
        }
        
        //search with kmp
        int idx_h = 0, idx_n = 0;
        while(idx_h<haystack.size()&&idx_n < needle.size()){
            if(haystack[idx_h]==needle[idx_n]){idx_h++;idx_n++;}
            else if(idx_n==0) idx_h++;
            else idx_n = needle_kmp[idx_n-1]+1;
            
        }
        
        if(idx_n == needle.size()) return idx_h-idx_n; //found
        return -1;  //not found
    }
};
