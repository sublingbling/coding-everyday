class Solution {
public:
    int climbStairs(int n) {
        vector<int> table;
        table.push_back(1);
        table.push_back(1);
        for (int i=2; i<n+1; i++)
        {
            table.push_back(table[i-1]+table[i-2]);
        }
        return table[n];
    }
};
