class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
            x = -x;
        }
        int res = 0;
        while (x) {
            int digit = x%10;
            int tmp = res*10 + digit;
            if ((tmp - digit)/10 != res) {
                return 0;
            }
            res = tmp;
            x = x / 10;
        }
        res *= sign;
        return res;
    }
};
