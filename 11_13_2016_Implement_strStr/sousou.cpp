class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        
        int loop = haystack.size()-needle.size();
        for (int i=0; i<=loop; i++)
        {
            if (!haystack.compare(i, needle.size(), needle)) return i;
        }
        return -1;
    }
};
