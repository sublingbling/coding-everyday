class Solution {
public:
    string addBinary(string a, string b) {
        string c(max(a.size(),b.size()),'0');
        int overflow = 0;
        int idx_a=a.size()-1, idx_b=b.size()-1;
        int idx_c= max(a.size(),b.size())-1;
        while(idx_a>=0 || idx_b>=0){
            int _a = idx_a>=0 ?a[idx_a]-'0':0;
            int _b = idx_b>=0 ?b[idx_b]-'0':0;
            if(_a&&_b){c[idx_c]= overflow?'1':'0'; overflow=1;}
            else if(_a||_b){c[idx_c]= overflow?'0':'1';}
            else{c[idx_c]=overflow?'1':'0';overflow=0;}
            idx_a--;
            idx_b--;
            idx_c--;
        }
        return overflow?'1'+c:c;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int overflow = 0, idx_a=a.size()-1, idx_b=b.size()-1;
        while(idx_a>=0 || idx_b>=0 || overflow){
            overflow += idx_a>=0? a[idx_a--]-'0':0;
            overflow += idx_b>=0? b[idx_b--]-'0':0;
            s = char(overflow%2 + '0')+s;
            overflow /= 2;
        }
        return s;
    }
};
