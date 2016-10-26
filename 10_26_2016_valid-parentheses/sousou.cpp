class Solution {
public:
    bool isValid(string s) {
        if (0 == s.size()) return true;
        
        stack<char> myStack;
        char d1='('-')', d2='['-']', d3='{'-'}';
        char d=0;
        for (int i=0; i<s.size(); i++)
        {
            if (myStack.size()>s.size()/2) return false;
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    myStack.push(s[i]);
                    continue;
                case ')':
                    d = d1;
                    break;
                case ']':
                    d = d2;
                    break;
                case '}':
                    d = d3;
                    break;
                default:
                    return false;
            }
            if (myStack.empty()) return false;
            char top = myStack.top();
            if (top == s[i]+d) myStack.pop();
            else return false;
        }
        if (0==myStack.size()) return true;
        else return false;
    }
};
