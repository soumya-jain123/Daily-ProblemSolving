class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = INT_MAX;
        int profit = INT_MIN;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minValue)
                minValue = prices[i];
            profit = max(profit, prices[i] - minValue);
        }

        return profit;
    }
};