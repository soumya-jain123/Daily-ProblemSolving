class Solution {
public:
    int solve(int i, int hold, vector<int>& prices, vector<vector<int>>& dp){
        if(i == prices.size())
            return 0;

        if(dp[i][hold] != -1)
            return dp[i][hold];

        if(hold){
            return dp[i][hold] = max(-prices[i] + solve(i + 1, 0, prices, dp), solve(i + 1, 1, prices, dp));
        }else{
            return dp[i][hold] = max(prices[i] + solve(i + 1, 1, prices, dp), solve(i + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices, dp); // index, not holding stock, prices array
    }
};