class Solution {
public:
    //    r a r a r a r
    //r   1 1 2 2 3 3 4
    //a   0 1 1 3 3 6 6
    //r   0 0 1 1 4 4 10
    
    //    d  d  d
    //d   1  2  3
    //d   0  1  3
    int numDistinct(string s, string t) {
        int* count = new int[t.size()];
        for(int i=0; i<t.size();i++) count[i]=0;
        for(int i=0; i< s.size(); i++){
            for(int j=t.size()-1; j>=0; j--){
                if(s[i]==t[j]){
                    if(j==0) count[0]++;
                    else if(count[j-1]!=0) count[j] = count[j-1]+count[j];
                }
            }
        }
        int r = count[t.size()-1];
        delete[] count;
        return r;
    }
};
