class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int numDays = prices.size();
        if (!numDays) {
            return 0;
        }
        vector<int> buy(numDays, 0);
        vector<int> sell(numDays, 0);
        sell[numDays-1] = prices[numDays - 1];
        for (int i = numDays - 2; i >= 0; i--) {
            buy[i] = max(sell[i+1] - prices[i], buy[i+1]);
            sell[i] = max(prices[i], sell[i+1]);
        }
        return buy[0];
    }
};
