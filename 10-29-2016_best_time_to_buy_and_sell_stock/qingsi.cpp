class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int numDays = prices.size();
        if (!numDays) {
            return 0;
        }
        int buy = 0;
        int sell = prices[numDays - 1];
        for (int i = numDays - 2; i >= 0; i--) {
            buy = max(sell - prices[i], buy);
            sell = max(prices[i], sell);
        }
        return buy;
    }
};
