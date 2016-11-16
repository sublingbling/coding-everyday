class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) {
            return 0;
        }
        if (!haystack.size()) {
            return -1;
        }
        auto T = kmpParse(needle);
        return strStrKMP(haystack, needle);
        /*
        int szHaystack = haystack.size();
        int szNeedle = needle.size();
        for (int i = 0; i < szHaystack - szNeedle + 1; i++) {
            int j = 0;
            while (j < szNeedle && haystack[i+j] == needle[j]) {
                j++;
            }
            if (j == szNeedle) {
                return i;
            }
        }
        return -1;
        */
    }
    
    vector<int> kmpParse(string str) {
        int sz = str.size();
        vector<int> T(sz);
        T[0] = -1;
        for (int i = 1; i < sz; i++) {
            if (i == 1) {
                T[i] = 0;
                continue;
            }
            int tmp = T[i-1];
            while (tmp >= 0) {
                if (str[tmp] == str[i-1]) {
                    T[i] = tmp+1;
                    break;
                } else {
                    tmp = T[tmp];
                }
            }
        }
        return T;
    }
    
    int strStrKMP(string haystack, string needle) {
        auto T = kmpParse(needle);
        int i = 0;
        int j = 0;
        while (i + j < haystack.size() + 1) {
            if (j == needle.size()) {
                return i; 
            }
            if (haystack[i+j] == needle[j]) {
                j++;
            } else {
                int k = T[j];
                i += j - k; 
                j = max(k, 0);
            }
        }
        return -1;
    }
};
