class Solution {
    bool isPalindrome(string& s, int start, int end) {
        if (s.length() == 0) {
            return false;
        }
        assert(start <= end);
        int left = start;
        int right = end;
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        for (int i = 0; i < s.length(); i++) {
            if (isPalindrome(s, 0, i)) {
                if (i == s.length()-1) {
                    res.push_back(vector<string>(1, s));
                } else {
                    auto tmp = partition(s.substr(i+1));
                    if (tmp.size() > 0) {
                        for (auto& p : tmp) {
                            p.insert(p.begin(), s.substr(0, i+1));
                            res.push_back(std::move(p));
                        }
                    }
                }
            }
        }
        return res;
    }
};
