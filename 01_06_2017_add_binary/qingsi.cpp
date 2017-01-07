class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int m = a.length();
        int n = b.length();
        string res("");
        int tmp;
        for (int i = 0; i < max(m, n); i++) {
            if (i < m && i < n) {
                tmp = a[m-1-i] - '0' + b[n-1-i] - '0' + carry;
            } else if (i < m) {
                tmp = a[m-1-i] - '0' + carry;
            } else if (i < n) {
                tmp = b[n-1-i] - '0' + carry;
            }
            carry = tmp / 2;
            res = to_string(tmp % 2) + res;
        }
        if (carry) {
            res = to_string(carry) + res;
        }
        return res;
    }
};
