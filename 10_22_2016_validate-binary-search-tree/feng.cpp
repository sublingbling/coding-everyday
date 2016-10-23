class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> s;
        int idx = 0;
        while(idx < preorder.size()){
            if(preorder[idx]==',') idx++;
            else if(preorder[idx]!=','){
                if(preorder[idx]=='#' && (!s.empty())){
                    while(s.top()=='#'){
                        s.pop();
                        if(s.empty()) return false;
                        s.pop();
                        if(s.empty()) break;
                    }
                    s.push('#');
                }
                else{
                    s.push(preorder[idx]);
                }
                while(preorder[idx]!=','){idx++; if(idx==preorder.size()) break;}
            }
            
        }
        if(s.size()==1){
            if( s.top()=='#') return true;
        }
        return false;
    }
};
