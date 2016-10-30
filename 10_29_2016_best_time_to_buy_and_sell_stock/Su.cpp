class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int profit=0;
        int min=prices[0];
        int max=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i] < min) max=min=prices[i];
            if(prices[i]>max) max=prices[i];
            if(max-min>profit) profit=max-min;
        }
        return profit;
    }
};
