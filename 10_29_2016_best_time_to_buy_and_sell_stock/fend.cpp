class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int min_p, max_p, profit;
        min_p= max_p= prices[0];
        profit = 0;
        for(auto a:prices){
            if(a<=min_p) min_p = max_p = a;   //reset if smaller than previous smallest number;
            else if(a>max_p){                 //update if larger than max_p
            max_p = a;
            profit = max(profit, max_p-min_p);    
            }     
        }
        return profit;
    }
};
