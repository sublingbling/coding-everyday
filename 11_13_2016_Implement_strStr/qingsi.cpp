class Solution {
public:
    int strStr(string haystack, string needle) {
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
    }
};
