int maxProfit(int* prices, int pricesSize) {
    if (!prices) return 0;
    int buy=prices[0], profit=0;
    for (int i=0; i<pricesSize; i++)
    {
        if (prices[i]>buy)
        {
            if (prices[i]-buy>profit)
                profit = prices[i] - buy;
        }
        else
            buy = prices[i];
    }
    
    return profit;
}
