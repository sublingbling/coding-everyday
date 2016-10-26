class Solution {
public:
    bool isValid(string s) {
        stack<char> pare;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') pare.push(s[i]);
            if(s[i]==')' || s[i]=='}' || s[i]==']') {
                if(pare.empty()) return false;
                char tmp = pare.top();
                switch(s[i]){
                    case ')':
                        if(tmp!='(') return false;
                        break;
                    case ']':
                        if(tmp!='[') return false;
                        break;
                    case '}':
                        if(tmp!='{') return false;
                        break;
                }
                pare.pop();
            }
        }
        if(pare.empty()) return true;
        
        return false;
        
    }
};
