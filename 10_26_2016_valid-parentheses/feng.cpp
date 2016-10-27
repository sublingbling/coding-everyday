class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i=0; i<s.size(); i++){
            switch(s[i]){
                case '(':
                case '{':
                case '[': t.push(s[i]);
                          break;
                case ')': if(t.empty()) return false;
                          else if(t.top()=='(') t.pop();
                          else return false;
                          break;
                case '}': if(t.empty()) return false;
                          else if(t.top()=='{') t.pop();
                          else return false;
                          break;
                case ']':if(t.empty()) return false;
                          else if(t.top()=='[') t.pop();
                          else return false;
                          break;
            }
        }
        if(t.empty()) return true;
        return false;
        
    }
};
