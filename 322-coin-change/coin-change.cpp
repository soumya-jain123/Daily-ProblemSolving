class Solution {
public:
    int solve(int n, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(n == 0)
            return 1e9;
        if(amount == 0)
            return 0;

        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int notTake = solve(n - 1, amount, coins, dp);

        int take = 1e9;
        if(coins[n - 1] <= amount)
            take = 1 + solve(n, amount - coins[n - 1], coins, dp);
        
        return dp[n][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins.size(), amount, coins, dp);


        return (ans >= 1e9) ? -1 : ans;
    }
};