class Solution {
public:
    bool isValid(string s) {
        if (!s.length()) {
            return true;
        }
        vector<char> st;
        map<char, char> parenMap = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push_back(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty() || parenMap[st.back()] != ch) {
                    return false;
                } else {
                    st.pop_back();
                }
            } else {
                assert(false);
            }
        }
        return st.empty();
    }
};
